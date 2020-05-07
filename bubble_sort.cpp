#include<iostream>
#define SWAP(x,y){x=x+y;y=x-y;x=x-y;}
#define SIZE 1000
using namespace std;
void input_data(int* arr) {
	for (int i = 0; i < SIZE; i++)arr[i] = rand() % 10000;
}
void bubble_sort(int* arr) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE - 1; j++)if (arr[j] > arr[j + 1])SWAP(arr[j], arr[j + 1]);
}

int main() {
	int data[SIZE];
	input_data(data);
	cout << "before sorting\n";
	bubble_sort(data);
	cout << "after sorted\n";
	for (int i = 0; i < SIZE; i++)cout << data[i] << " ";
}