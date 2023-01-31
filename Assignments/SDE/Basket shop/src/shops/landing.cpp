#include "landing.hpp"

Landing::Landing(GFXHandler& _gfx_handler, FontHandler& _font_handler, Cart& _cart) : gfx_handler(&_gfx_handler), font_handler(&_font_handler), cart(&_cart)
{
	this->cart_button = new Bitmap(this->gfx_handler->GetBitmap("shop_ui", "cart.png"), 970, 65);
}

Landing::~Landing()
{

}

void Landing::HandleEvent(ALLEGRO_EVENT& _event)
{
	this->cart_button->HandleEvent(_event);
	if (this->cart_button->Clicked(_event))
	{
		this->cart->show = true;
	}

	if (!this->cart->show)
	{
	}
}

void Landing::Render()
{
	al_set_clipping_rectangle(0, 50, al_get_display_width(al_get_current_display()), al_get_display_height(al_get_current_display()));

	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_draw_multiline_text(this->font_handler->arial, al_map_rgb(0, 0, 0), 20, 70, 700, 12, 0, "Welcome to the Basket Shop. Here you can buy electronics, equipment and other IT related things.Navigate in the menu above to choose product categories, and see what merchandise we offer : )");

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