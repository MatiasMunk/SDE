#include "phone.hpp"

Phone::Phone()
{
	id = 0;
	product = "";
	brand = "";
	model = "";
	category = "";
	description = "";
	currency = "";
	price = 0;
	stock = 0;

	launch_announced = "";
	launch_release = "";

	body_dimensions = "";
	body_weight = "";
	body_build = "";

	display_size = "";
	display_resolution = "";
	display_protection = "";
	display_hz = "";

	platform_os = "";
	platform_chipset = "";
	platform_cpu = "";
	platform_gpu = "";

	memory_internal = "";

	battery_type = "";
	battery_charging = "";

	images_font = "";
	images_back = "";
	images_side = "";
	images_thumbnail = "";
}

Phone::~Phone()
{

}