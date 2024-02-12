#pragma once
#include "Products.h"
#include <vector>
class NewCart
{
public:
	vector <Products> cart;
	double price;
	void AddToCart();
};

