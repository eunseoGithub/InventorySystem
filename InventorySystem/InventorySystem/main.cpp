#include<iostream>

#include "Inventory.h"
#include "Item.h"

using namespace std;

int main()
{
	Inventory<Item>* inven = new Inventory<Item>(3);
	
	inven->AddItem(Item("item1" ,1));
	inven->AddItem(Item("item2", 4));
	inven->AddItem(Item("item3", 200));

	inven->PrintAllItems();
	cout << "Item capacity : " << inven->GetCapacity() <<" size : " << inven->GetSize() << endl;
	
	inven->AddItem(Item("item4", 20));
	cout << "Item capacity : " << inven->GetCapacity() << " size : " << inven->GetSize() << endl;
	
	cout << "item sorting" << endl;
	inven->SortItems();
	inven->PrintAllItems();

	cout << "New Inventory Init" << endl;
	Inventory<Item>* inven2 = new Inventory<Item>(*inven);
	inven2->PrintAllItems();
	
	cout << "Assign function" << endl;
	Inventory<Item>* inven3 = new Inventory<Item>();
	inven3->Assign(*inven2);
	inven3->PrintAllItems();

	if (inven != nullptr)
		delete inven;
	
	if (inven2 != nullptr)
		delete inven2;
	

	return 0;
}