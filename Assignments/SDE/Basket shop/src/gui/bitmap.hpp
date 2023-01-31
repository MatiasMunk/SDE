#ifndef GUI_BITMAP_HPP_INCLUDED
#define GUI_BITMAP_HPP_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

class Bitmap
{
public:
	ALLEGRO_BITMAP* bitmap;
	int x, y;
	int w, h;

	bool hovered;

public:
	Bitmap(ALLEGRO_BITMAP* bitmap, int _x, int _y);
	~Bitmap();

	void HandleEvent(ALLEGRO_EVENT& _event);
	bool Clicked(ALLEGRO_EVENT& _event);
	void Render();
};

#endif