#include "menu.hpp"

Menu::Menu(int _x, int _y, int _w, int _h, FontHandler& _font_handler, int& _shop_page) : x(_x), y(_y), w(_w), h(_h), font_handler(&_font_handler), shop_page(&_shop_page)
{
	this->menus.push_back("Home");
	this->menus.push_back("Laptop");
	this->menus.push_back("Gaming");
	this->menus.push_back("Mobile");
	this->menus.push_back("Storage");
	this->menus.push_back("Blah");
	this->menus.push_back("Blah");
	this->menus.push_back("Blah");

	selected_menu = -1;
	sub_menu = nullptr;
}

Menu::~Menu()
{

}

void Menu::HandleEvent(ALLEGRO_EVENT& _event)
{
	if (_event.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		if (_event.mouse.x >= 0 && _event.mouse.x <= al_get_display_width(al_get_current_display())
			&& _event.mouse.y >= 0 && _event.mouse.y <= 50)
		{
			selected_menu = _event.mouse.x / 128;
		}
		else
		{
			selected_menu = -1;
		}
	}
	else if (_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		if (_event.mouse.button & 1)
		{
			if (selected_menu != -1 && selected_menu < 8)
			{
				*this->shop_page = selected_menu;


				/*if (sub_menu)
				{
					delete this->sub_menu;
					this->sub_menu = nullptr;
				}

				this->sub_menu = new SubMenu(selected_menu * 128, 50, 128, 50);*/
			}
		}
	}
}

void Menu::Render()
{
	al_draw_filled_rectangle(x, y, w, h, al_map_rgba(25, 25, 112, 100));

	for (int i = 1; i < 8; i++)
	{
		al_draw_line(i * 128, 0, i * 128, 50, al_map_rgb(255, 255, 255), 1);
	}

	for (int i = 0; i < 8; i++)
	{
		al_draw_text(font_handler->arial, al_map_rgb(255, 255, 255), 64 + (i * 128), 18, ALLEGRO_ALIGN_CENTER, menus.at(i).c_str());
	}

	if (this->sub_menu)
		this->sub_menu->Render();
}