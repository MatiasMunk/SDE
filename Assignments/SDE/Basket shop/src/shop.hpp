#ifndef SHOP_HPP_INCLUDED
#define SHOP_HPP_INCLUDED

#include <fstream>
#include <stdexcept>

#include <nlohmann/json.hpp>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include "gfx_handler.hpp"
#include "font_handler.hpp"

#include "phone.hpp"

using json = nlohmann::json;

enum ShopPage
{
	HOME,
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
	int* shop_page;

	GFXHandler* gfx_handler;
	FontHandler* font_handler;

	json phones_json;
	std::map<int, Phone> phones;

public:
	Shop(int &_shop_page, GFXHandler& _gfx_handler, FontHandler& _font_handler);
	~Shop();

	void HandleEvent(ALLEGRO_EVENT& _event);
	void Render();
};

#endif