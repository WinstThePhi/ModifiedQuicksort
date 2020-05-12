#include <iostream>
#include <vector>
#include "quicksort.hpp"

int *left, *right, *pivot;

Quicksort::Quicksort(int arr[], int arrSize){
	if(IsSorted(arr, 0, arrSize - 1)){
		std::cout << "The numbers are already sorted." << std::endl;
	}
	else{
        std::vector<int*> allPivots;
		allPivots.push_back(arr - 1);
		AssignPointers(arr, 0, arrSize - 1);
		Partition(arr, 0, arrSize - 1);
		allPivots.push_back(pivot);
		int *origPivot = pivot;
		while(!IsSorted(arr, 0, origPivot - arr)){
			for(int idx = 0; idx < (int) allPivots.size() - 1; idx++){
				if(IsSorted(arr, allPivots[idx] - arr + 1, allPivots[idx + 1] - arr - 1)){
					continue;
				}
				else{
					Partition(arr, allPivots[idx] - arr + 1, allPivots[idx + 1] - arr - 1);
					allPivots.insert(allPivots.begin() + idx + 1, pivot);
					idx = 0;
				}
			}
		}
		allPivots.clear();
		allPivots.push_back(origPivot);
		allPivots.push_back(arr + arrSize - 1);
		while(!IsSorted(arr, origPivot - arr + 1, arrSize - 1)){
			for(int idx = 0; idx < (int) allPivots.size() - 1; idx++){
				if(IsSorted(arr, allPivots[idx] - arr + 1, allPivots[idx + 1] - arr)){
					continue;
				}
				else{
					Partition(arr, allPivots[idx] - arr + 1, allPivots[idx + 1] - arr);
					allPivots.insert(allPivots.begin() + idx + 1, pivot);
					idx = 0;
				}
			}
		}
	}
}

void Quicksort::Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

bool Quicksort::IsSorted(int arr[], int leftBound, int rightBound){
	if((rightBound - leftBound) == 0){
		return true;
	}
	else{
		for(int i = leftBound; i < rightBound; i++){
			if(arr[i + 1] >= arr[i]){
				continue;
			}
			else{
				return false;
			}
		}
		return true;
	}
}

void Quicksort::Partition(int array[], int leftBound, int rightBound){
	AssignPointers(array, leftBound, rightBound);
	if(IsSorted(array, leftBound, rightBound)){
		return;
	}
	else{
		std::vector<int*> leftE, rightE;
		while(left < right){
			while(*left <= *pivot && (left - array) < rightBound){
				if(left > right){
					break;
				}
				else if(*left == *pivot){
					leftE.push_back(left);
				}
				left++;
			}
			while(*right >= *pivot && (right - array) > leftBound){
				if(left > right){
					break;
				}
				else if(*right == *pivot){
					rightE.push_back(right);
				}
				right--;
			}
			if(leftE.size() > 0 && GetIndexes(leftE, left).size() > 0 && right > left){
				for(int w = 0; w < (int) GetIndexes(leftE, left).size(); w++){
					leftE[GetIndexes(leftE, left)[w]] = right;
				}
			}
			else if(rightE.size() > 0 && GetIndexes(rightE, right).size() > 0 && right > left){
				for(int w = 0; w < (int) GetIndexes(rightE, right).size(); w++){
					rightE[GetIndexes(rightE, right)[w]] = left;
				}
				
			}
			if(right < left){
				break;
			}
			Swap(left, right);
		}
		if(rightE.size() > 0 && GetIndexes(rightE, right).size() > 0){
			for(int w = 0; w < (int) GetIndexes(rightE, right).size(); w++){
				rightE[GetIndexes(rightE, right)[w]] = pivot;
			}
		}
		if(leftE.size() > 0 && GetIndexes(leftE, right).size() > 0){
			for(int w = 0; w < (int) GetIndexes(leftE, right).size(); w++){
				leftE[GetIndexes(leftE, right)[w]] = pivot;
			}
		}
		Swap(pivot, right);
		pivot = right;
		//equal to pivot left of pivot
		for(long unsigned int i = 0; i < leftE.size(); i++){
			if((pivot - (i + 1)) >= array){
				Swap(leftE[i], pivot - (i + 1));
			}
			else{
				break;
			}
		}
		//equal to pivot right of pivot
		for(long unsigned int i = 0; i < rightE.size(); i++){
			if(pivot + (i + 1) <= array + rightBound){
				Swap(rightE[i], pivot + (i + 1));
			}
			else{
				break;
			}
		}
		leftE.clear();
		rightE.clear();
	}
}

void Quicksort::AssignPointers(int arr[], int leftBound, int rightBound){
	pivot = arr + leftBound;
	left = pivot + 1;
	right = arr + rightBound;
}

std::vector<int> Quicksort::GetIndexes(std::vector<int*> vec, int* num){
	std::vector<int> indexes;
	for(int i = 0; i < (int) vec.size(); i++){
		if(vec[i] == num){
			indexes.push_back(&vec[i] - &vec[0]);
		}
		else
			continue;
	}
	return indexes;
}