#include "gfx_handler.hpp"

#include <iostream>

bool GFXHandler::initialized_ = false;
std::map<std::string, std::unique_ptr<GFXHandler::Directory>> GFXHandler::directories;
std::string GFXHandler::path;

GFXHandler::GFXHandler()
{
    if (!this->initialized_)
    {
        this->path = "";

        this->initialized_ = true;
    }
}

GFXHandler::GFXHandler(std::string _path)
{
    this->path = _path;

    if (!this->initialized_)
    {
        this->initialized_ = true;
    }
}

GFXHandler::Directory::Directory(std::string _path)
{
    this->path = _path;
}

ALLEGRO_BITMAP* GFXHandler::Directory::GetBitmap(std::string _file)
{
    if (this->bitmaps.find(_file) == this->bitmaps.end())
    {
        std::string filename = path + "/" + _file;

        this->bitmaps[_file] = al_load_bitmap(filename.c_str());

        if (!this->bitmaps[_file])
        {
            return NULL;
        }
    }

    return this->bitmaps[_file];
}

void GFXHandler::Directory::Clear()
{
    for (auto& it : this->bitmaps)
    {
        al_destroy_bitmap(it.second);
    }

    this->bitmaps.clear();
}

ALLEGRO_BITMAP* GFXHandler::GetBitmap(std::string _path, std::string _file)
{
    std::string directory = "data/images/" + _path;
    if (this->directories.find(directory) == this->directories.end())
    {
        this->directories[directory] = std::make_unique<Directory>(directory);
    }

    return this->directories[directory]->GetBitmap(_file);
}

void GFXHandler::Clear()
{
    for (auto& it : this->directories)
    {
        it.second->Clear();
    }
}
