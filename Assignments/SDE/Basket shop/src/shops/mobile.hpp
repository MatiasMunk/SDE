#ifndef SHOPS_MOBILE_HPP_INCLUDED
#define SHOPS_MOBILE_HPP_INCLUDED

#include <sstream>
#include <nlohmann/json.hpp>

#include "shop.hpp"
#include "../phone_data.hpp"

#include "../gui/bitmap.hpp"
#include "../gui/button.hpp"

using json = nlohmann::json;

class Mobile : public Shop
{
public:
	GFXHandler* gfx_handler;
	FontHandler* font_handler;
	Cart* cart;

	Bitmap* cart_button;

	int num_phones;
	json phones_json;
	std::map<int, Phone> phones;

	std::vector<Button*> purchase_buttons;

public:
	Mobile(GFXHandler& _gfx_handler, FontHandler& _font_handler, Cart& _cart);
	~Mobile();

	void HandleEvent(ALLEGRO_EVENT& _event);
	void Render();
};

#endif //SHOPS_MOBILE_HPP_INCLUDED