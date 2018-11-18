#include "pch.h"
#include"MaxArrayHeap.h"
#include<iostream>
#include<time.h>
#include<vector>


using namespace std;

void fillDriver(MaxArrayHeap<int>* mHeap)
{
	vector<int> uniqueRandom;
	
	
	int itemCount = 0;
	srand(time(NULL));
	while (itemCount < 100)
	{
		int number = rand() % 100 + 1;
		int count = std::count(uniqueRandom.begin(), uniqueRandom.end(), number);
		
		if ((count == 0) || (uniqueRandom.size() == 0))
		{
			uniqueRandom.push_back(number);
			itemCount++;
		}
	}
	
	for (int i = 0; i < itemCount;i++)
	{
		mHeap->add(uniqueRandom.at(i));
	}
	cout << endl;
	for (int i = 0;i < itemCount;i++)
	{
		cout << uniqueRandom.at(i) << " ";
	}
	cout << endl << endl;
}

vector<int> deleteAndStoreFifty(MaxArrayHeap<int>* mHeap)
{
	vector<int> deletedValues;
	for (int i = 0;i < 50;i++)
	{
		int value = mHeap->peekTop();
		deletedValues.push_back(value);
		mHeap->remove();
	}
	return deletedValues;
}


int main()
{
	vector<int> deletedValues;
	MaxArrayHeap<int>* mHeap = new MaxArrayHeap<int>();
	
	fillDriver(mHeap);
	
	mHeap->displayHeap(0);

	deletedValues = deleteAndStoreFifty(mHeap);
	cout << endl << endl << endl << "The fifty values deleted form the heap:"<<endl;
	for (int i = 0;i < 50;i++)
	{
		cout << deletedValues.at(i) << " ";
	}

	cout << endl << endl << "The heap after the values have been deleted: " << endl;
	mHeap->displayHeap(0);

}