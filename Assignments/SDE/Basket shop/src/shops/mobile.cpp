#include "mobile.hpp"

Mobile::Mobile(GFXHandler& _gfx_handler, FontHandler& _font_handler, Cart& _cart) : gfx_handler(&_gfx_handler), font_handler(&_font_handler), cart(&_cart)
{
	this->cart_button = new Bitmap(this->gfx_handler->GetBitmap("shop_ui", "cart.png"), 970, 65);

	this->num_phones = 0;
	try
	{
		std::ifstream f("data/phones.json");
		this->phones_json = json::parse(f);

		for (auto it = this->phones_json.begin(); it != this->phones_json.end(); ++it)
		{
			Phone phone;
			phone.id = (*it)["id"].get<int>();
			phone.category = (*it)["category"].get<std::string>();
			phone.product = (*it)["product"].get<std::string>();
			phone.brand = (*it)["brand"].get<std::string>();
			phone.model = (*it)["model"].get<std::string>();
			phone.description = (*it)["description"].get<std::string>();
			phone.currency = (*it)["currency"].get<std::string>();
			phone.price = (*it)["price"].get<int>();
			phone.stock = (*it)["stock"].get<int>();

			auto& elem = (*it)["launch"];
			phone.launch_announced = elem["announced"].get<std::string>();
			phone.launch_release = elem["release"].get<std::string>();

			elem = (*it)["body"];
			phone.body_dimensions = elem["dimensions"].get<std::string>();
			phone.body_weight = elem["weight"].get<std::string>();
			phone.body_build = elem["build"].get<std::string>();

			elem = (*it)["display"];
			phone.display_size = elem["size"].get<std::string>();
			phone.display_resolution = elem["resolution"].get<std::string>();
			phone.display_protection = elem["protection"].get<std::string>();
			phone.display_hz = elem["hz"].get<std::string>();

			elem = (*it)["platform"];
			phone.platform_os = elem["os"].get<std::string>();
			phone.platform_chipset = elem["chipset"].get<std::string>();
			phone.platform_cpu = elem["cpu"].get<std::string>();
			phone.platform_gpu = elem["gpu"].get<std::string>();

			elem = (*it)["memory"];
			phone.memory_internal = elem["internal"].get<std::string>();

			elem = (*it)["battery"];
			phone.battery_type = elem["type"].get<std::string>();
			phone.battery_charging = elem["charging"].get<std::string>();

			elem = (*it)["images"];
			phone.images_font = elem["front"].get<std::string>();
			phone.images_back = elem["back"].get<std::string>();
			phone.images_side = elem["side"].get<std::string>();
			phone.images_thumbnail = elem["thumbnail"].get<std::string>();

			this->phones[phone.id] = phone;

			this->purchase_buttons.push_back(new Button(90 + (this->num_phones * 150), 225, 65, 20, "Purchase"));
			this->num_phones++;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Mobile::~Mobile()
{
	for (auto button : this->purchase_buttons)
	{
		delete button;
		button = nullptr;
	}
}

void Mobile::HandleEvent(ALLEGRO_EVENT& _event)
{
	this->cart_button->HandleEvent(_event);
	if (this->cart_button->Clicked(_event))
	{
		this->cart->show = true;
	}

	if (!this->cart->show)
	{
		for (auto button : this->purchase_buttons)
		{
			button->HandleEvent(_event);
		}

		for (int i = 0; i < this->purchase_buttons.size(); i++)
		{
			if (this->purchase_buttons.at(i)->Clicked(_event))
			{
				this->cart->AddProduct("Smartphones", reinterpret_cast<void*>(&this->phones.at(i + 1)));
			}
		}
	}
}

void Mobile::Render()
{
	al_set_clipping_rectangle(0, 50, al_get_display_width(al_get_current_display()), al_get_display_height(al_get_current_display()));

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_draw_multiline_text(this->font_handler->arial, al_map_rgb(0, 0, 0), 20, 70, 700, 12, 0, "In need of a new phone? Find all the latest phones on this page.");

	std::map<int, Phone>::iterator it = phones.begin();

	int num_phones = 0;
	while (it != phones.end())
	{
		al_draw_textf(this->font_handler->arial, al_map_rgb(0, 0, 0), 85 + (num_phones * 150), 100, ALLEGRO_ALIGN_CENTER, "%s", it->second.product.c_str());
		al_draw_rectangle(20 + (num_phones * 150), 120, 21 + (num_phones * 150) + 136, 221, al_map_rgb(255, 0, 0), 1);
		al_draw_bitmap(this->gfx_handler->GetBitmap("products/phones/" + std::to_string(it->second.id), it->second.images_thumbnail), 20 + (num_phones * 150), 120, 0);
		std::stringstream ss;
		ss.imbue(std::locale(""));
		ss << std::setprecision(2) << std::fixed << it->second.price;
		al_draw_textf(FontHandler().arial, al_map_rgb(0, 0, 0), 85 + (num_phones * 150), 227, ALLEGRO_ALIGN_RIGHT, "$%s", ss.str().c_str());
		this->purchase_buttons.at(num_phones)->Render();
		num_phones++;
		it++;
	}

	this->cart_button->Render();
	if (this->cart->num_products > 0)
	{
		al_draw_filled_circle(970 + this->cart_button->w, 65, 9, al_map_rgb(255, 0, 0));
		al_draw_textf(FontHandler().arial, al_map_rgb(255, 255, 255), 970 + this->cart_button->w, 65 - 8, ALLEGRO_ALIGN_CENTER, "%i", this->cart->num_products);
	}
	std::stringstream ss;
	ss.imbue(std::locale(""));
	ss << std::setprecision(2) << std::fixed << this->cart->sum;
	al_draw_textf(FontHandler().arial, al_map_rgb(0, 0, 0), 982, 95, ALLEGRO_ALIGN_CENTER, "$ %s", ss.str().c_str());

	al_set_clipping_rectangle(0, 0, al_get_display_width(al_get_current_display()), al_get_display_height(al_get_current_display()));
}