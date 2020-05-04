#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

#define DIGIT 4
#define SIZE 1000
deque<int> bucket[10];

//return units
int ret_units(int *arr, int ind,int index) {
	int temp = arr[index];
	for (int i = DIGIT-1; i > DIGIT -1 - ind; i--) temp = temp / 10;
	return temp % 10;
}
//do radix_sort
void radix_sort(int* arr) {
	for (int i = 0; i < DIGIT; i++) {
		//array into bucket
		for (int j = 0; j < SIZE; j++)
			bucket[ret_units(arr, i, j)].push_back(arr[j]);
		int index = 0;
		//arrange array
		for (int t = 0; t < 10; t++)
			while (!bucket[t].empty())
			{
				arr[index++] = bucket[t].front();
				bucket[t].pop_front();
			}
	}
}
int main() {
	int arr[SIZE];
	//input random NUM
	for (int i = 0; i < SIZE; i++)arr[i] = rand() % (int)pow(10,DIGIT);
	radix_sort(arr);
	//print array
	for (int i = 0; i < SIZE; i++)cout << arr[i] << " ";
	return 0;
}