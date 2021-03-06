#ifndef QUICKSORT
#define QUICKSORT

#include <vector>

class Quicksort{
	public:
	Quicksort(int arr[], int arrSize);
	bool IsSorted(int arr[], int leftBound, int rightBound);
	
	private:
	int *left, *right, *pivot;
	void Swap(int *a, int *b);
	void Partition(int array[], int leftBound, int rightBound);
	void AssignPointers(int arr[], int leftBound, int rightBound);
	std::vector<int> GetIndexes(std::vector<int*>, int*);
};

#endif
