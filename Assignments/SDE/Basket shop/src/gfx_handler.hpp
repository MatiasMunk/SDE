#ifndef GFX_HANDLER_HPP_INCLUDED
#define GFX_HANDLER_HPP_INCLUDED

#include <string>
#include <map>
#include <memory>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

// to load and store graphics (monostate)
class GFXHandler
{
public:
    class Directory
    {
    private:
        std::string path;
        unsigned int id;
        std::map<unsigned int, ALLEGRO_BITMAP*> bitmaps;

    public:
        Directory(std::string path, unsigned int id);
        ALLEGRO_BITMAP* GetBitmap(std::string png);
        void Clear();
    };

private:
    static bool initialized_;
    static std::map<unsigned int, std::unique_ptr<Directory>> directories;

public:
    static std::string path;

    GFXHandler();
    GFXHandler(std::string path);
    ALLEGRO_BITMAP* GetBitmap(std::string product_path, unsigned int dir_id, std::string png);
    void Clear();
};

#endif // GFX_HANDLER_HPP_INCLUDED
