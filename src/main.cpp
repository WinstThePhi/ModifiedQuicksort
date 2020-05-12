#include <iostream>
#include <cstdlib>
#include <ctime>
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
	int arr[10];
	srand(time(0));
	for(int c = 0; c < 1000; c++){
		for(int i = 0; i < 10; i++){
			arr[i] = RandomNumber();
		}
		std::cout << "\n";
		Quicksort sort(arr, 10);
		for(int i : arr){
			std::cout << i << "\t";
		}
		std::cout << "\n";
	}
	return 0;
}

int RandomNumber(){
	int temp = (rand()%50);
	return temp;
}
