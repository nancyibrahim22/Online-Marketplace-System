#pragma once
#include <string>
#include<vector>
#include "NewCart.h"
using namespace std;


class Customer
{
private:
	string name, phoneNumber, address, email;
	int ID;
	NewCart cart;

public:
	void regestration();
	void login();
	void add_cart();
};

