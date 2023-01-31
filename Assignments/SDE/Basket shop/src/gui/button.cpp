#include "button.hpp"

Button::Button(int _x, int _y, int _w, int _h, std::string _text) : x(_x), y(_y), w(_w), h(_h), text(_text)
{
	this->hovered = false;
}

Button::~Button()
{

}

void Button::HandleEvent(ALLEGRO_EVENT& _event)
{
	if (_event.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		if (_event.mouse.x >= this->x && _event.mouse.x <= this->x + this->w && _event.mouse.y >= this->y && _event.mouse.y <= this->y + this->h)
		{
			printf("Hovered\n");
			this->hovered = true;
		}
		else
		{
			this->hovered = false;
		}
	}
}

bool Button::Clicked(ALLEGRO_EVENT& _event)
{
	if (_event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		if (_event.mouse.button & 1)
		{
			if (this->hovered)
			{
				return true;
			}
		}
	}

	return false;
}

void Button::Render()
{
	al_draw_filled_rectangle(this->x, this->y, this->x + w, this->y + h, al_map_rgb(25, 25, 112));
	al_draw_text(FontHandler().arial, al_map_rgb(255, 255, 255), this->x + (this->w/2), this->y + 2, ALLEGRO_ALIGN_CENTER, this->text.c_str());
}