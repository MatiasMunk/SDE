#include "shop.hpp"

Shop::Shop(int &_shop_page, GFXHandler& _gfx_handler, FontHandler& _font_handler) : shop_page(& _shop_page), gfx_handler(&_gfx_handler), font_handler(&_font_handler)
{
	try
	{
		std::ifstream f("data/phones.json");
		phones_json = json::parse(f);

		for (auto it = phones_json.begin(); it != phones_json.end(); ++it)
		{
			Phone phone;
			phone.id = (*it)["id"].get<int>();
			phone.product = (*it)["product"].get<std::string>();
			phone.brand = (*it)["brand"].get<std::string>();
			phone.model = (*it)["model"].get<std::string>();
			phone.category = (*it)["category"].get<std::string>();
			phone.description = (*it)["description"].get<std::string>();
			phone.currency = (*it)["currency"].get<std::string>();
			phone.price = (*it)["price"].get<int>();
			phone.stock = (*it)["stock"].get<int>();

			auto& elem = (*it)["launch"];
			phone.launch_announced = elem["announced"].get<std::string>();
			phone.launch_announced = elem["release"].get<std::string>();
			
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
			
			phones[phone.id] = phone;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

Shop::~Shop()
{

}

void Shop::HandleEvent(ALLEGRO_EVENT& _event)
{
}

void Shop::Render()
{
	al_set_clipping_rectangle(0, 50, al_get_display_width(al_get_current_display()), al_get_display_height(al_get_current_display()));

	al_clear_to_color(al_map_rgb(255, 255, 255));

	switch (*this->shop_page)
	{
		case ShopPage::HOME:
		{
			al_draw_multiline_text(this->font_handler->arial, al_map_rgb(0, 0, 0), 20, 70, 700, 12, 0, "Welcome to the Basket Shop.Here you can buy electronics, equipment and other IT related things.Navigate in the menu above to choose product categories, and see what merchandise we offer : )");
			break;
		}
		case ShopPage::MOBILE:
		{
			al_draw_multiline_text(this->font_handler->arial, al_map_rgb(0, 0, 0), 20, 70, 700, 12, 0, "In need of a new phone? Find all the latest phones on this page.");

			/*for (int i = 0; i < 4; i++)
			{
				al_draw_rectangle(20 + (i * 150), 100, 20 + (i * 150) + 136, 200, al_map_rgb(255, 0, 0), 1);
			}*/

			std::map<int, Phone>::iterator it = phones.begin();

			int num_phones = 0;
			while (it != phones.end())
			{
				al_draw_textf(this->font_handler->arial, al_map_rgb(0, 0, 0), 85 + (num_phones * 150), 100, ALLEGRO_ALIGN_CENTER, "%s", it->second.product.c_str());
				al_draw_rectangle(20 + (num_phones * 150), 120, 20 + (num_phones * 150) + 136, 200, al_map_rgb(255, 0, 0), 1);
				al_draw_bitmap(this->gfx_handler->GetBitmap("phones", it->second.id, it->second.images_thumbnail), 20 + (num_phones * 150), 120, 0);
				num_phones++;
				it++;
			}
			break;
		}
	}

	al_set_clipping_rectangle(0, 0, al_get_display_width(al_get_current_display()), al_get_display_height(al_get_current_display()));
}