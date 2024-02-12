#pragma once
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


void Products::object()
{
	int choice;
	cout << "****Welcome to our online supermarket****" << endl;
	cout << "Press 1 to add a product" << endl;
	cin >> choice;
	Products p;
	if (choice == 1) {
		p.addProduct();
	}
}
void Products::addProduct()
{
	bool found = false;
	do {
		cout << " Please enter the product id: ";
		cin >> Id;
		string storeId;
		ifstream readID("Products\\id.txt");
		while (getline(readID, storeId)) {
			if (stoi(storeId) == Id) {
				found = false;
				cout << "This product already exists, please try another id: " << endl;
				break;
			}
			else {
				found = true;
			}
		}
	} while (!found);

	//all ids file
	ofstream writeID("Products\\id.txt", ios::app);
	writeID << Id << endl;
	writeID.close();



	//each file id
	cout << "Enter product category: ";
	cin >> Category;
	bool found1=false;
	string category1;
	string cat = Category;
	getline(cin, cat);

	

	ifstream readcat("Products\\category.txt");
	while (getline(readcat, category1)) {
		if (Category==category1) {
			found1 = true;
			break;
		}
		else{
			found1 = false;
		}
	}

	if (found1 == false) {
		ofstream writeID("Products\\category.txt", ios::app);
		writeID << Category << endl;
		writeID.close();
	}



	cout << "Enter product name: ";
	cin >> Name;
	string n = Name;
	getline(cin, n);

	cout << "Enter product quantity: ";
	cin >> Quantity;
	string quant = to_string(Quantity);
	getline(cin, quant);

	cout << "Enter product seller id: ";
	cin >> Seller_Id;
	string s_id = to_string(Seller_Id);
	getline(cin, s_id);

	cout << "Enter product price: ";
	cin >> Price;
	string p =to_string(Price);
	getline(cin, p);

	cout << "Enter product rating: ";
	cin >> Rating;
	string r = to_string(Rating);
	getline(cin, r);

	cin.ignore();

	ofstream write2;
	write2.open("Products\\" + to_string(Id) + ".txt");
	write2 << Id << endl << Category << endl << Name << endl << Quantity << endl <<Seller_Id<<endl<< Price << endl << Rating << endl;
	write2.close();

	cin.ignore();
	system("cls");

}

