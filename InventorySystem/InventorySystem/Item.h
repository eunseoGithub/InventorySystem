#pragma once
#include <iostream>
#include<string>

using namespace std;
class Item
{
public:
	Item() : name(""), price(0) {}
	Item(const string& _name, int _price);
	void PrintInfo() const;

	const string& getName() const;
	void setName(const string& _name);

	int GetPrice() const;
	void SetPrice(int _price);

private:
	string name;
	int price;
};

