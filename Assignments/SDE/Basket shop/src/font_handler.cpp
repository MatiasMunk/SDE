#include "font_handler.hpp"

bool FontHandler::initialized = false;
ALLEGRO_FONT* FontHandler::arial;

FontHandler::FontHandler()
{
	if(!this->initialized)
    {
        this->LoadFonts();

        this->initialized = true;
    }
}

FontHandler::~FontHandler()
{

}

void FontHandler::LoadFonts()
{
    this->arial = al_load_ttf_font("data/fonts/arial.ttf", 14, 0);

    if (arial == NULL)
    {
        std::cout << "Could not load font" << std::endl;
    }
}