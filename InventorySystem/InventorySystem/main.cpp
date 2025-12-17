#include<iostream>

#include "Inventory.h"
#include "Item.h"

using namespace std;

int main()
{
	Inventory<Item>* inven = new Inventory<Item>(3);
	
	inven->AddItem(Item("item1" ,100));
	inven->AddItem(Item("item2", 200));
	inven->AddItem(Item("item3", 300));

	inven->PrintAllItems();
	if (inven != nullptr)
		delete inven;
	inven = nullptr;
	return 0;
}