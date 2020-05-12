#include <iostream>

//for random
#include <cstdlib>
#include <ctime>

//for file input
#include <fstream>

#include "quicksort.hpp"

int RandomNumber();

int main(){
	/*std::cout << "How many whole numbers do you want to input?" << std::endl;
	int num;
	std::cin >> num;
	int arr[num];
	std::cout << "Input the numbers you want to input one by one: " << std::endl;
	for(int c = 0; c < num; c++){
		std::cin >> arr[c];
	}*/
	std::ofstream fout;
	fout.open("input.in");
	if(!fout){
		std::cerr << "Failed to open the file" << std::endl;
		return -1;
	}
	int arr[15];
	srand(time(0));
	for(int c = 0; c < 5000; c++){
		for(int i = 0; i < 15; i++){
			arr[i] = RandomNumber();
		}
		std::cout << "\n";
		Quicksort sort(arr, 15);
		for(int i : arr){
			std::cout << i << "\t";
			if(!sort.IsSorted(arr, 0, 14)){
				fout << i << std::endl;
			}
		}
		std::cout << "\n";
	}
	fout.close();
	return 0;
}

int RandomNumber(){
	int temp = (rand()%50);
	return temp;
}
