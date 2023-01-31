#ifndef CART_INCLUDED_HPP
#define CART_INCLUDED_HPP

#include <iostream>
#include <string>
#include <map>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "product.hpp"
#include "phone_data.hpp"

class Cart
{
public:
	int num_products;
	std::map<int, std::map<std::string, void*>> products;
	double sum;

	bool show;

public:
	Cart();
	~Cart();

	bool AddProduct(std::string _category, void* _product);

	void Render();
};

#endif //CART_INCLUDED_HPP