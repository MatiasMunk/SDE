#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include <string>
#include <vector>
#include <map>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "font_handler.hpp"

struct SubMenu
{
	int x, y;
	int w, h;

	SubMenu(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h)
	{

	}

	void HandleEvent(ALLEGRO_EVENT& _event)
	{

	}

	void Render()
	{
		al_draw_filled_rectangle(this->x, this->y, this->x + this->w, this->y + this->h, al_map_rgba(25, 25, 112, 100));
	}
};

class Menu
{
public:
	int x, y;
	int w, h;

	FontHandler* font_handler;

	std::vector<std::string> menus;

	char selected_menu;
	SubMenu* sub_menu;
	int* shop_page;

public:
	Menu(int _x, int _y, int _w, int _h, FontHandler &_font_handler, int&_shop_page);
	~Menu();

	void HandleEvent(ALLEGRO_EVENT& _event);
	void Render();
};

#endif //MENU_HPP_INCLUDED