#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include "gfx_handler.hpp"
#include "font_handler.hpp"
#include "menu.hpp"
#include "shop.hpp"

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

	int shop_page = 0;
	GFXHandler gfx_handler;
	FontHandler font_handler;
	Shop shop(shop_page, gfx_handler, font_handler);
	Menu menu(0, 0, al_get_display_width(display), 50, font_handler, shop_page);

	bool running = true;
	bool redraw = false;

	al_start_timer(timer);

	while (running)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		shop.HandleEvent(event);
		menu.HandleEvent(event);

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

			shop.Render();
			menu.Render();

			al_flip_display();
		}
	}

	return 0;
}