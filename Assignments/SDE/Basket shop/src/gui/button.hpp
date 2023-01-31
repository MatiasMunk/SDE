#ifndef GUI_BUTTON_HPP_INCLUDED
#define GUI_BUTTON_HPP_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "../font_handler.hpp"

class Button
{
public:
	int x, y;
	int w, h;
	std::string text;

	bool hovered;

public:
	Button(int _x, int _y, int _w, int _h, std::string _text);
	~Button();

	void HandleEvent(ALLEGRO_EVENT& _event);
	bool Clicked(ALLEGRO_EVENT& _event);
	void Render();
};

#endif //GUI_BUTTON_HPP_INCLUDED