#include<iostream>
#include<time.h>
using namespace std;
#define SIZE 1000000
#define RANK 1000000

int arr[SIZE];

int rnk[RANK] = { 0, };
void counting_sort(int* arr,int* rank) {
	for (int i = 0; i < SIZE; i++)rank[arr[i]]++;
	int index = 0;
	for (int i = 0; i < RANK; i++) 
		for (int j = 0; j < rank[i]; j++)
			arr[index++] = i;
}
void _input(int* arr) {
	for (int i = 0; i < SIZE; i++)arr[i] = rand() % RANK;
}
void print_arr(int* arr) {
	for (int i = 0; i < SIZE; i++)cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	clock_t start;
	_input(arr);
	cout << "Before sorting\n";
	//print_arr(arr);
	//do counting sort
	start = clock();
	counting_sort(arr,rnk);
	cout << "After sorted\n";
	cout << (double)(clock() - start) << "ms\n";
	//print_arr(arr);
	return 0;
}