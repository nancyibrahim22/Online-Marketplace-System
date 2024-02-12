#include "NewCart.h"
#include "Products.h"
#include "Functions.h"
#include "Customer.h"
#include <iostream>
#include <List>
#include<string>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <iterator>
#include <vector>

using namespace std;


void NewCart::AddToCart() {

	
	vector<Products>w;
	w = generate();


	int id1;
	int q1;
	int num;
	bool ask = false;

	do {
		cout << "Enter the Numeber of product id ";
		cin >> id1;
		for (int i = 0; i < w.size(); i++)
		{
			if (w[i].Id == id1) {

				cout << "Enter the Quantity of Product : " << w[i].Name << "\n";
				cin >> q1;

				 if(q1==0) {
					cout << " Please enter A valid quantity " << "\n";
				 }
			      else if (w[i].Quantity - q1 > 0) {
				  int new_quantity = w[i].Quantity - q1;
				  w[i].Quantity = q1;
				  cart.push_back(w[i]);
				  price += w[i].Price * q1;
				  w[i].Quantity = new_quantity;
				  cout << price << endl;
				  cout << w[i].Quantity << endl;

			      }
				else {
					cout << " Quantity is not enough " << "\n";
				}
			}
		}
		
		bool waka = false;
		do
		{
			cout << " Do you want another product ? " << endl;
			cin >> num;
			
			if (num == 1) {
				ask = true;
				waka = false;
			}
			else if (num == 2) {
				ask = false;
				waka = false;
			}
			else {
				
				cout << "please type 1 or 2 "<< endl;
				waka = true;
			}

		} while (waka);
		

	} while (ask);

		
	cout << cart.size() << endl;

	for (int i = 0; i < cart.size(); i++) {
		cout << "        Product Id : " << cart[i].Id << endl;
		cout << "        Product Category : " << cart[i].Category << endl;
		cout << "        Product Name : " << cart[i].Name << endl;
		cout << "        Total Price " << cart[i].Price << " L.E " << endl;
		cout << "\n" << "               **********       " << endl;
	}
	cout << "------------------------------------------------------------------------------"<< endl;
	cout << " Total price of your cart after tax : " << price << endl;

	bool ok = false;
	int c ;

	do
	{
		cout << "Are You want to confirm your Payment ?" << endl;
		cout << "Press 1 for Yes " << endl;
		cout << "Press 2 for No " << endl;
		cin >> c;

		if(c==1) {
			/*remove("products\\id.txt");*/
			for (int i = 0; i < cart.size(); i++) {
				for (int j = 0; j < w.size(); j++)
				{
					if (cart[i].Id == w[i].Id) {
						string res = ("Products\\" + to_string(cart[i].Id) + ".txt");
						remove(res.c_str());

						if (w[i].Quantity != 0) {
							ofstream temp(("Products\\" + to_string(cart[i].Id) + ".txt"), ios::app);
							temp << w[i].Id << "\n" << w[i].Category << "\n" << w[i].Name << "\n" << w[i].Quantity << "\n" << w[i].Seller_Id << "\n" << w[i].Price << "\n" << w[i].Rating << "\n";
							temp.close();

						}
					}
					/*if (w[i].Quantity != 0) {
						ofstream temp1("products\\id.txt", ios::app);
						temp1 << w[i].Id << endl;
						temp1.close();
					}*/
				}
			}
			ok == true;
		}

		else if (c == 2){
			ok = true;
		}


		else {
			ok = false;
		}
		
	} while (!ok);

	
}





