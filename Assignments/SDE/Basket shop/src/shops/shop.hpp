#ifndef SHOP_HPP_INCLUDED
#define SHOP_HPP_INCLUDED

#include <fstream>
#include <stdexcept>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include "../gfx_handler.hpp"
#include "../font_handler.hpp"
#include "../cart.hpp"

enum ShopPage
{
	LANDING,
	LAPTOP,
	GAMING,
	MOBILE,
	STORAGE,
	BLAH,
	BLAH2,
	BLAH3
};

class Shop
{
public:
	Shop() {}
	Shop(GFXHandler& _gfx_handler, FontHandler& _font_handler, Cart& _cart) {};

	virtual void HandleEvent(ALLEGRO_EVENT& _event) = 0;
	virtual void Render() = 0;
};

#endif