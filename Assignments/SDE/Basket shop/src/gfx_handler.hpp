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
        std::map<std::string, ALLEGRO_BITMAP*> bitmaps;

    public:
        Directory(std::string _path);
        ALLEGRO_BITMAP* GetBitmap(std::string _file);
        void Clear();
    };

private:
    static bool initialized_;
    static std::map<std::string, std::unique_ptr<Directory>> directories;

public:
    static std::string path;

    GFXHandler();
    GFXHandler(std::string _path);
    ALLEGRO_BITMAP* GetBitmap(std::string _path, std::string _file);
    void Clear();
};

#endif // GFX_HANDLER_HPP_INCLUDED
