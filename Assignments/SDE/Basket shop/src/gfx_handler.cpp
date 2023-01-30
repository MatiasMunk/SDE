#include "gfx_handler.hpp"

#include <iostream>

bool GFXHandler::initialized_ = false;
std::map<unsigned int, std::unique_ptr<GFXHandler::Directory>> GFXHandler::directories;
std::string GFXHandler::path;

GFXHandler::GFXHandler()
{
    if (!this->initialized_)
    {
        this->path = "images/products/";

        this->initialized_ = true;
    }
}

GFXHandler::GFXHandler(std::string path)
{
    this->path = path;

    if (!this->initialized_)
    {
        this->initialized_ = true;
    }
}

GFXHandler::Directory::Directory(std::string path, unsigned int id)
{
    this->path = path;
    this->id = id;
}

ALLEGRO_BITMAP* GFXHandler::Directory::GetBitmap(std::string png)
{
    if (this->bitmaps.find(id) == this->bitmaps.end())
    {
        std::string filename = path + "/" + std::to_string(this->id) + "/" + png;
        this->bitmaps[id] = al_load_bitmap(filename.c_str());

        if (!this->bitmaps[id])
        {
            return NULL;
        }
    }

    return this->bitmaps[id];
}

void GFXHandler::Directory::Clear()
{
    for (auto& it : this->bitmaps)
    {
        al_destroy_bitmap(it.second);
    }

    this->bitmaps.clear();
}

ALLEGRO_BITMAP* GFXHandler::GetBitmap(std::string product_path, unsigned int dir_id, std::string png)
{
    if (this->directories.find(dir_id) == this->directories.end())
    {
        this->directories[dir_id] = std::make_unique<Directory>("data/images/products/" + product_path, dir_id);
    }

    return this->directories[dir_id]->GetBitmap(png);
}

void GFXHandler::Clear()
{
    for (auto& it : this->directories)
    {
        it.second->Clear();
    }
}
