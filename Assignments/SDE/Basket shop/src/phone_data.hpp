#ifndef PHONE_DATA_HPP_INCLUDED
#define PHONE_DATA_HPP_INCLUDED

#include <string>

#include "product.hpp"

class Phone : public Product
{
public:
	int id;
	std::string category;
	std::string product;
	std::string brand;
	std::string model;
	std::string description;
	std::string currency;
	double price;
	int stock;
	
	std::string launch_announced;
	std::string launch_release;

	std::string body_dimensions;
	std::string body_weight;
	std::string body_build;
	
	std::string display_size;
	std::string display_resolution;
	std::string display_protection;
	std::string display_hz;

	std::string platform_os;
	std::string platform_chipset;
	std::string platform_cpu;
	std::string platform_gpu;

	std::string memory_internal;

	std::string battery_type;
	std::string battery_charging;

	std::string images_font;
	std::string images_back;
	std::string images_side;
	std::string images_thumbnail;

public:
	Phone();
	~Phone();
};

#endif //PHONE_DATA_HPP_INCLUDED