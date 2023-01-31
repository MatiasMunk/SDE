#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include "gfx_handler.hpp"
#include "font_handler.hpp"
#include "menu.hpp"
#include "cart.hpp"

#include "shops/shop.hpp"
#include "shops/landing.hpp"
#include "shops/mobile.hpp"

void ChangeShop(GFXHandler& _gfx_handler, FontHandler& _font_handler, Cart& _cart, Shop*& _current_shop, int& _current_shop_id, int& _next_shop_id);

int main()
{
	ALLEGRO_DISPLAY* display = nullptr;
	ALLEGRO_TIMER* timer = nullptr;
	ALLEGRO_EVENT_QUEUE* event_queue = nullptr;

	if (!al_init())
		return 1;

	display = al_create_display(1024, 768);
	if (!display)
		return 1;

	timer = al_create_timer(1.0f / 60.0f);
	if (!timer)
		return 1;

	event_queue = al_create_event_queue();
	if (!event_queue)
		return 1;

	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	GFXHandler gfx_handler;
	FontHandler font_handler;
	int current_shop_id = -1;
	int next_shop_id = ShopPage::LANDING;
	Menu menu(0, 0, al_get_display_width(display), 50, font_handler, next_shop_id);
	Cart cart;
	Shop* shop = new Landing(gfx_handler, font_handler, cart);

	ChangeShop(gfx_handler, font_handler, cart, shop, current_shop_id, next_shop_id);

	bool running = true;
	bool redraw = false;

	al_start_timer(timer);

	while (running)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		menu.HandleEvent(event);
		shop->HandleEvent(event);

		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
		}
		else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			running = false;
		}

		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			menu.Render();
			shop->Render();
			if (cart.show)
				cart.Render();

			al_flip_display();
		}

		ChangeShop(gfx_handler, font_handler, cart, shop, current_shop_id, next_shop_id);
	}

	return 0;
}

void ChangeShop(GFXHandler& _gfx_handler, FontHandler& _font_handler, Cart& _cart, Shop*& _current_shop, int& _current_shop_id, int& _next_shop_id)
{
	if (_current_shop_id == _next_shop_id)
		return;

	switch (_next_shop_id)
	{
		case ShopPage::LANDING:
		{
			delete _current_shop;
			_current_shop = new Landing(_gfx_handler, _font_handler, _cart);
			break;
		}
		case ShopPage::LAPTOP:
		{
			break;
		}
		case ShopPage::GAMING:
		{
			break;
		}
		case ShopPage::MOBILE:
		{
			delete _current_shop;
			_current_shop = new Mobile(_gfx_handler, _font_handler, _cart);
			break;
		}
	}

	_current_shop_id = _next_shop_id;
}