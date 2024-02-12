#pragma once
#include "Customer.h"
#include "Functions.h"
#include "NewCart.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Customer::regestration()
{
    cout << "Enter your name: ";
    std::cin >> std::ws;
    getline(cin, name);
    cout << "Enter your address: ";
    std::cin >> std::ws;
    getline(cin, address);
    cout << "Enter your ID: ";
    cin >> ID;
    while (true) {
        cout << "Enter your phone number: ";
        std::cin >> std::ws;
        getline(cin, phoneNumber);
        char check[10] = { '0','1','2','3','4','5','6','7','8','9' };
        int found = 0;
        if (phoneNumber.length() == 11)
        {
            for (int i = 0; i < phoneNumber.length(); i++) {
                for (int j = 0; j <= 9; j++) {
                    if (phoneNumber[i] == check[j]) {
                        found++;
                    }
                }
            }
            if (found != phoneNumber.length()) {
                cout << "Your number must be only numbers, Please try again." << endl;
            }
            else {
                break;
            }

        }
        else
        {
            cout << "Your phone number must contains 11 number, Please try again." << endl;
        }
    }

    while (true) {
        cout << "Enter your E_mail: ";
        std::cin >> std::ws;
        getline(cin, email);
        string mail = "@gmail.com";
        string mail_1 = "@i_cloud.com";
        string mail_2 = "@yahoo.com";
        string mail_3 = "@hotmail.com";
        if (email.find(mail) != string::npos || email.find(mail_1) != string::npos || email.find(mail_2) != string::npos
            || email.find(mail_3) != string::npos) {
            break;
        }
        else {
            cout << "Please enter a valid E_mail for example: @xxxxx.com" << endl;
        }
    }
    ofstream write;
    write.open("Customers\\" + name + ".txt");
    write << name << "\n" << address << "\n" << ID << "\n" << phoneNumber << "\n" << email << "\n";
    write.close();

    ofstream writeMail;
    writeMail.open("Customers/Emails.txt", ios::out | ios::app);
    writeMail << email << endl;
    writeMail.close();

    system("cls");
}

void Customer::login() {
    string l_mail;
    string lines;
    bool checkMail = false;
    int count = 0;
    while (!checkMail && count < 3) {
        cout << "Enter your E_mail: ";
        cin >> l_mail;
        ifstream read;
        read.open("Customers/Emails.txt", ios::app);
        while (getline(read, lines)) {
            if (l_mail == lines) {
                checkMail = true;
                break;
            }
            else {
                checkMail = false;
            }
        }
        read.close();
        if (checkMail) {
            cout << "Login successful" << endl;
            break;
        }
        else {
            cout << "invalid E_mail, Please try again." << endl;
            count++;
        }
    }
    if (count == 3) {
        system("cls");
        cout << "Your E_mail doesn't exist, Please sign up" << endl;
        regestration();
    }

}

void Customer::add_cart()
{
    cart.AddToCart();
}

