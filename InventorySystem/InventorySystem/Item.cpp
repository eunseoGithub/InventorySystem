#include "Item.h"

Item::Item(const string& _name, int _price)
{
	name = _name;
	price = _price;
}
void Item::PrintInfo() const
{
	cout << name << ",АЁАн : [" << price << "G]" << endl;
}

const string& Item::getName() const
{
	return name;
}
void Item::setName(const string& _name)
{
	name = _name;
}

int Item::GetPrice() const
{
	return price;
}
void Item::SetPrice(int _price)
{
	price = _price;
}