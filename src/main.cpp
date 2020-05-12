#include <iostream>

//for file input
#include <fstream>

#include "quicksort.hpp"

int RandomNumber();

int main(){
	std::cout << "How many whole numbers do you want to input?" << std::endl;
	int num;
	std::cin >> num;
	int arr[num];
	std::cout << "Input the numbers you want to input one by one: " << std::endl;
	for(int c = 0; c < num; c++){
		std::cin >> arr[c];
	}
	std::ofstream fout;
	fout.open("output.txt");
	if(!fout){
		std::cerr << "Failed to open the file" << std::endl;
		return -1;
	}
	Quicksort sort(arr, num);
	for(int i : arr){
		fout << i << std::endl;
	}
	
	return 0;
}
