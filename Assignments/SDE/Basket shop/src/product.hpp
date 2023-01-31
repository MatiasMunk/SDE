#ifndef PRODUCT_HPP_INCLUDED
#define PRODUCT_HPP_INCLUDED

#include <string>

class Product
{
public:
	int id;
	std::string category;
	std::string product;
	std::string description;
	std::string currency;
	int price;
	int stock;

public:
	Product();
	~Product();

	friend class Phone;
};

#endif