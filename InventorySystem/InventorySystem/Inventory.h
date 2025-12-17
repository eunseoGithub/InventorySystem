#pragma once
#include<iostream>
#include<algorithm>
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
	Inventory(const Inventory<T>& other)
	{
		capacity = other.capacity;
		size = other.size;
		pItems = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			pItems[i] = other.pItems[i];
		}
		cout << "Inventory Copy Finish" << endl;
	}
	~Inventory()
	{
		if (pItems != nullptr)
			delete[] pItems;
		pItems = nullptr;
	}

	void AddItem(const T& item)
	{
		if(size >= capacity)
		{
			cout << "Inventory size Up!" << endl;
			Resize(capacity * 2);
			
		}
		pItems[size] = item;
		size++;
		cout <<"AddItem : " << item.getName() << ", [" << item.GetPrice() << "G]" << endl;
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
	void Assign(const Inventory<T>& other)
	{
		if (this == &other)
			return;

		T* newItems = new T[other.capacity];

		copy(other.pItems, other.pItems + other.size, newItems);

		delete[] pItems;

		pItems = newItems;
		capacity = other.capacity;
		size = other.size;
	}
	void Resize(int newCapacity)
	{
		T* tmp = new T[newCapacity];
		copy(pItems, pItems + capacity, tmp);
		
		delete[] pItems;
		pItems = tmp;
		
		capacity = newCapacity;
	}
	void SortItems()
	{
		sort(pItems, pItems + size, [](const T& a, const T& b)
			{
				return a.GetPrice() < b.GetPrice();
			});
	}
private:
	T* pItems;
	int capacity;
	int size;
};

