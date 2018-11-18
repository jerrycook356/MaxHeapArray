#include"pch.h"
#include "PreCondViolatedExcep.h"
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

template<class ItemType>
MaxArrayHeap<ItemType>::MaxArrayHeap() :itemCount(0)
{
	items = new ItemType[DEFAULT_CAPACITY];
	for (int i = 0; i < DEFAULT_CAPACITY;i++)
	{
		items[i] = 0;
	}
}//end default constructor

template<class ItemType>
MaxArrayHeap<ItemType>::MaxArrayHeap(const ItemType someArray[], const int arraySize) :
	itemCount(arraySize), maxItems(2 * arraySize)
{
	items = new ItemType[2 * arraySize];

	for (int i = 0; i < itemCount;i++)
		items[i] = someArray[i];
	heapCreate();
}

template<class ItemType>
MaxArrayHeap<ItemType>::~MaxArrayHeap()
{
	delete items;
	items = nullptr;
}

template<class ItemType>
bool MaxArrayHeap<ItemType>::isEmpty()const
{
	return itemCount == 0;
}

template<class ItemType>
void MaxArrayHeap<ItemType>::heapCreate()
{
	for (int i = itemCount;i > 0; i/2)
	{
		heapRebuild(i);
	}
}

template<class ItemType>
int MaxArrayHeap<ItemType>::getNumberOfNodes()const
{
	return itemCount;
}

template<class ItemType>
int MaxArrayHeap<ItemType>::getHeight()const
{
	return (log2(itemCount) + 1);
}

template<class ItemType>
ItemType MaxArrayHeap<ItemType>::peekTop()const
{
	if (isEmpty())
		throw PreCondViolatedExcep("Attemepted to peak into an empty heap");
	return items[0];
}

template<class ItemType>
bool MaxArrayHeap<ItemType>::add(const ItemType& newData)
{
	int newDataIndex = itemCount;
	items[newDataIndex] = newData;
	
	

	while (newDataIndex > 0 && newData > items[getParentIndex(newDataIndex)])
	{
		items[newDataIndex] = items[getParentIndex(newDataIndex)];
		newDataIndex = getParentIndex(newDataIndex);
	}
	items[newDataIndex] = newData;
	itemCount++;
	return true;
}

template<class ItemType>
bool MaxArrayHeap<ItemType>::remove()
{
	items[0] = items[itemCount-1];
	itemCount--;
	heapRebuild(0);
	return true;
}

template<class ItemType>
void MaxArrayHeap<ItemType>::clear()
{
	for (int i = 0; i < itemCount;i++)
	{
		remove();
	}
}

template<class ItemType>
void MaxArrayHeap<ItemType>::heapRebuild(int subTreeIndex)
{
	int largerChildIndex;
	int rightChildIndex;

	if (!isLeaf(subTreeIndex))
	{
		largerChildIndex = getLeftChild(subTreeIndex);
		if (items[getRightChild(subTreeIndex)] < itemCount+1)
		{
			rightChildIndex = getRightChild(subTreeIndex);
			if (items[rightChildIndex] > items[largerChildIndex])
				largerChildIndex = rightChildIndex;
		}
		if (items[subTreeIndex] < items[largerChildIndex])
		{
			ItemType temp = items[subTreeIndex];
			items[subTreeIndex] = items[largerChildIndex];
			items[largerChildIndex] = temp;
			heapRebuild(largerChildIndex);
		}
	}

}

template<class ItemType>
int MaxArrayHeap<ItemType>::getLeftChild(int nodeIndex)const
{
	try
	{
		int index = (2 * nodeIndex) + 1;
		return index;
	}
	catch (exception)
	{
		return -1;
	}
}

template<class ItemType>
int MaxArrayHeap<ItemType>::getRightChild(int nodeIndex)const
{
	try 
	{
		int index = (2 * nodeIndex) + 2;
		return index;
	}
	catch (exception)
	{
		return -1;
	}
}

template<class ItemType>
int MaxArrayHeap<ItemType>::getParentIndex(int nodeIndex)const
{
	return (nodeIndex - 1)/2;
}

template<class ItemType>
bool MaxArrayHeap<ItemType>::isLeaf(int nodeIndex)const
{
	return (getLeftChild(nodeIndex) > itemCount + 1);
}

template<class ItemType>
void MaxArrayHeap<ItemType>::displayHeap(int index)
{
	cout << endl;
	cout << "max heap = ";
	for (int i = 0;i < itemCount;i++)
	{
		
		cout << " " << items[i];

	}
	
}


