/**Interface for the ADT heap
@file HeapInterface.h*/


#pragma once
template<class ItemType>
class HeapInterface
{
public:
	/**Sees whether the heap is empty
	@return true if the heap is empty, or false otherwise*/
	virtual bool isEmpty() const = 0;

	/**Gets the number of nodes in this heap
	@return the number of nodes in the heap*/
	virtual int getNumberOfNodes() const = 0;

	/**Gets the height of this heap
	@return the height of the heap*/
	virtual int getHeight()const = 0;

	/**Gets the data tha is in the root (top) of this heap.
	for a max heap the ata is the largest value in the heap
	for a minHeap the data is the smallest value in the heap.
	@pre the heap is not empty
	@post the root's data has been returned and the heap is unchanged
	@return the data in the root of the heap*/
	virtual ItemType peekTop() const = 0;

	/**adds a new node contaiing the given data to this heap
	@param newDAta the data fot he new node
	@post the heap consans a new node.
	@return true if the addition is succsessful or false if not. */
	virtual bool add(const ItemType& newData) = 0;

	/**removes the root node from this heap.
	@return true if removal is successful false if not*/
	virtual bool remove() = 0;

	/**Removes all nodes from this heap*/
	virtual void clear() = 0;

};