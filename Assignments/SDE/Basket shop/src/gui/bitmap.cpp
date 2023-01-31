#include "bitmap.hpp"
#include "../font_handler.hpp"

Bitmap::Bitmap(ALLEGRO_BITMAP* _bitmap, int _x, int _y) : bitmap(_bitmap), x(_x), y(_y)
{
	this->w = al_get_bitmap_width(_bitmap);
	this->h = al_get_bitmap_height(_bitmap);
	this->hovered = false;
}

Bitmap::~Bitmap()
{

}

void Bitmap::HandleEvent(ALLEGRO_EVENT& _event)
{
	if (_event.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		if (_event.mouse.x >= this->x && _event.mouse.x <= this->x + this->w && _event.mouse.y >= this->y && _event.mouse.y <= this->y + this->h)
		{
			this->hovered = true;
		}
		else
		{
			this->hovered = false;
		}
	}
}

bool Bitmap::Clicked(ALLEGRO_EVENT& _event)
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

void Bitmap::Render()
{
	al_draw_bitmap(this->bitmap, this->x, this->y, 0);
}