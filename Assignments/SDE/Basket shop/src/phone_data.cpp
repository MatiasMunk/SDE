#include "phone_data.hpp"

Phone::Phone()
{
	this->id = 0;
	this->category = "";
	this->product = "";
	this->brand = "";
	this->model = "";
	this->description = "";
	this->currency = "";
	this->price = 0;
	this->stock = 0;

	this->launch_announced = "";
	this->launch_release = "";

	this->body_dimensions = "";
	this->body_weight = "";
	this->body_build = "";

	this->display_size = "";
	this->display_resolution = "";
	this->display_protection = "";
	this->display_hz = "";

	this->platform_os = "";
	this->platform_chipset = "";
	this->platform_cpu = "";
	this->platform_gpu = "";

	this->memory_internal = "";

	this->battery_type = "";
	this->battery_charging = "";

	this->images_font = "";
	this->images_back = "";
	this->images_side = "";
	this->images_thumbnail = "";
}

Phone::~Phone()
{

}