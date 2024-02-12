#pragma once
#include <iostream>
#include "Products.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Functions.h"
#include "Customer.h"

using namespace std;
Customer c;

vector<Products> generate() {
	Customer c;
	vector<Products> w;
	vector <int> q;
	string lines;
	Products p;

	ifstream read;
	read.open(("Products\\id.txt"), ios::app);
	while (getline(read, lines)) {
		q.push_back(stoi(lines));
	}

	for (int var : q)
	{


		string lines;
		ifstream read;
		read.open(("Products\\" + to_string(var) + ".txt"), ios::app);
		for (int j = 0; getline(read, lines); j++) {

			if (j == 0) {
				p.Id = stoi(lines);
			}
			else if (j == 1) {
				p.Category = lines;
			}
			else if (j == 2) {
				p.Name = lines;
			}
			else if (j == 3) {
				p.Quantity = stoi(lines);
			}
			else if (j == 4) {
				p.Seller_Id = stoi(lines);
			}
			else if (j == 5) {
				p.Price = stoi(lines);
			}
			else if (j == 6) {
				p.Rating = stoi(lines);
			}
		}
		w.push_back(p);
	}

	return w;
}
void ShowProductsByCategory() {
	Customer c;
	vector<Products> w;
	vector<string> a;
	w = generate();
	string lines1;
	ifstream read1;
	read1.open(("Products\\category.txt"), ios::app);
	while (getline(read1, lines1)) {
		a.push_back(lines1);
	}
	for (int j = 0; j < a.size(); j++)
	{
		cout << " Products of Category  : " << a[j] << endl << "\n";
		for (int i = 0; i < w.size(); i++)
		{
			if (w[i].Category == a[j]) {
				cout << "        Product Id : " << w[i].Id << endl;
				cout << "        Product Category : " << w[i].Category << endl;
				cout << "        Product Name : " << w[i].Name << endl;
				cout << "        Product Price " << w[i].Price << " L.E " << endl;
				cout << "\n" << "               **********       " << endl;
			}
		}
		cout << "    -------------------------------------------   " << endl;
	}
}
void ShowProducts() {

	vector<Products> w;
	w = generate();

	for (int i = 0; i < w.size(); i++)
	{
			cout << "        Product Id : " <<                w[i].Id << endl;
			cout << "        Product Category : " <<          w[i].Category << endl;
			cout << "        Product Quantity Avalible : " << w[i].Quantity << endl;
			cout << "        Product Name : " <<              w[i].Name << endl;
			cout << "        Product Price " <<               w[i].Price << " L.E " << endl;
			cout << "\n" << "               **********       " << endl;
		
	}
	
}
void cust1() {
	
	int num;
	cout << "Press 1 for Register "<< "\n" <<"if you already have an account press 2 for login"<< endl;
	bool waka1 = false;
	do
	{
		cin >> num;
		if (num == 1) {
			c.regestration();
			waka1 = true;
		}
		else if (num == 2) {
			c.login();
			waka1 = true;
		}
		else {

			cout << "please type 1 or 2 " << endl;
			waka1 = false;
		}
	} while (!waka1);
}
void adding_product_to_cust() {
	c.add_cart();
}
void AfterLogin() {
	int num;
	bool waka1 = false;
	cout << "              Logged successfully       " << endl; 
	ShowProducts();
	do
	{
		cout << "  Press 1 to browse Products by Categories  " << endl;
		cout << "  Press 2 to browse Products by Name  " << endl;
		cout << "  Press 3 to Add Product to your cart  " << endl;
		cin >> num;
		if (num == 1) 
		{
			ShowProductsByCategory();
			waka1 = false;
		}
		else if (num == 2)
		{
			ShowProductsByCategory();
			waka1 = false;
		}
		else if (num == 3)
		{
			adding_product_to_cust();
			waka1 = true;
		}
		else 
		{
			cout << " Please type 1 or 2 or 3 " << endl;
			waka1 = false;
		}
	} while (!waka1);
}
