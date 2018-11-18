#pragma 
#include"pch.h"
#include "HeapInterface.h"
template<class ItemType>
class MaxArrayHeap :public HeapInterface<ItemType>
{
private :
	static const int ROOT_INDEX = 0;
	static const int DEFAULT_CAPACITY = 100;

	int itemCount;
	int maxItems;

	ItemType* items;

	int getLeftChild( int nodeIndex)const;
	int getRightChild( int nodeIndex)const;
	int getParentIndex(int nodeIndex)const;
	bool isLeaf(int nodeIndex) const;

	void heapRebuild(int subTreeIndex);
	void heapCreate();

public:
	MaxArrayHeap();
	MaxArrayHeap(const ItemType someArray[], const int arraySize);
	virtual ~MaxArrayHeap();

	bool isEmpty()const;
	int getNumberOfNodes()const;
	int getHeight()const;
	ItemType peekTop()const;
	bool add(const ItemType& newData);
	bool remove();
	void clear();

	void displayHeap(int index);
	

};
#include"MaxArrayHeap.cpp"

 
