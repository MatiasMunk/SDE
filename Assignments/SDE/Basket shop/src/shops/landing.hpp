#ifndef SHOPS_LANDING_HPP_INCLUDED
#define SHOPS_LANDING_HPP_INCLUDED

#include <sstream>
#include <nlohmann/json.hpp>

#include "shop.hpp"

#include "../gui/bitmap.hpp"

using json = nlohmann::json;

class Landing : public Shop
{
public:
	GFXHandler* gfx_handler;
	FontHandler* font_handler;
	Cart* cart;

	Bitmap* cart_button;

public:
	Landing(GFXHandler& _gfx_handler, FontHandler& _font_handler, Cart& _cart);
	~Landing();

	void HandleEvent(ALLEGRO_EVENT& _event);
	void Render();
};

#endif //SHOPS_LANDING_HPP_INCLUDED