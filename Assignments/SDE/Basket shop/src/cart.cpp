#include "cart.hpp"
#include "gfx_handler.hpp"
#include "font_handler.hpp"

Cart::Cart()
{
	this->num_products = 0;
	this->products = {};
	this->sum = 0.00;

	this->show = false;
}

Cart::~Cart()
{

}

bool Cart::AddProduct(std::string _category, void* _product)
{
	if (_category == "Smartphones")
	{
		Phone* product = static_cast<Phone*>(_product);
		if (product->category == "Smartphones")
		{
			this->products.insert(std::make_pair(num_products, std::map<std::string, void*>()));
			this->products[num_products].insert(std::make_pair("Smartphones", _product));
			this->sum += product->price;
		}
	}
	else
	{
		return false;
	}

	this->num_products++;

	return true;
}

void Cart::Render()
{
	al_set_clipping_rectangle(0, 50, al_get_display_width(al_get_current_display()), al_get_display_height(al_get_current_display()));

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_draw_line(600, 0, 600, al_get_display_height(al_get_current_display()), al_map_rgb(0, 0, 0), 1);

	al_draw_text(FontHandler().arial, al_map_rgb(0, 0, 0), 300, 70, ALLEGRO_ALIGN_CENTER, "Shopping cart");

	//Draw
	std::map<int, std::map<std::string, void*> >::iterator itr;
	std::map<std::string, void*>::iterator ptr;

	int num_items = 0;
	for (itr = this->products.begin(); itr != this->products.end(); itr++)
	{
		for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++)
		{
			if (ptr->first == "Smartphones")
			{
				Phone* phone = reinterpret_cast<Phone*>(ptr->second);
				ALLEGRO_BITMAP* bitmap = GFXHandler().GetBitmap("products/phones/" + std::to_string(phone->id), phone->images_thumbnail);

				al_draw_textf(FontHandler().arial, al_map_rgb(0, 0, 0), 20, 105 + (num_items * 125), 0, "#%i", itr->first);
				al_draw_textf(FontHandler().arial, al_map_rgb(0, 0, 0), 300, 105 + (num_items * 125), ALLEGRO_ALIGN_CENTER, "%s %s", phone->brand.c_str(), phone->product.c_str());
				al_draw_bitmap(bitmap, 20, 125 + (num_items * 125), 0);
				al_draw_multiline_textf(FontHandler().arial, al_map_rgb(0, 0, 0), 165, 125 + (num_items * 125), 430, 12, 0, "Product description:\n\n%s", phone->description.c_str());
				al_draw_line(0, 105 + (num_items * 125), 600, 105 + (num_items * 125), al_map_rgb(0, 0, 0), 1);
			}
		}
		num_items++;
	}

	al_set_clipping_rectangle(0, 0, al_get_display_width(al_get_current_display()), al_get_display_height(al_get_current_display()));
}