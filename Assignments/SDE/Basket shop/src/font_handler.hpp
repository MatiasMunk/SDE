#ifndef FONT_HANDLER_INCLUDED_HPP
#define FONT_HANDLER_INCLUDED_HPP

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class FontHandler
{
private:
	static bool initialized;

public:
	static ALLEGRO_FONT* arial;

public:
	FontHandler();
	~FontHandler();

	void LoadFonts();
};

#endif