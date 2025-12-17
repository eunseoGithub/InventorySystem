#pragma once
#include<iostream>
#include"Item.h"
using namespace std;

template<typename T>
class Inventory
{
public:
	Inventory(int _capacity = 10)
	{
		if (_capacity <= 0)
			capacity = 1;
		else
			capacity = _capacity;

		pItems = new T[capacity];
		size = 0;
	}
	~Inventory()
	{
		if (pItems != nullptr)
			delete[] pItems;
		pItems = nullptr;
	}

	void AddItem(const T& item)
	{
		if (size < capacity)
		{
			pItems[size] = item;
			size++;
		}
		else
		{
			cout << "Inventory is full!" << endl;
		}
	}
	void RemoveLastItem()
	{
		if (size == 0)
		{
			cout << "Inventory is empty" << endl;
		}
		else
		{
			size--;
		}
	}
	int GetSize() const
	{
		return size;
	}
	int GetCapacity() const
	{
		return capacity;
	}
	void PrintAllItems() const
	{
		for (int i = 0; i < size; i++)
		{
			pItems[i].PrintInfo();
		}
	}

private:
	T* pItems;
	int capacity;
	int size;
};

