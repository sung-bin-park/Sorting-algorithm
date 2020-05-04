#include <iostream>
#define SIZE 100 //define size 100
using namespace std;

void init_arr(int*);
void print_arr(int*);
void merge(int*,int,int,int);
void merge_sort(int*, int, int);

int sorted_arr[SIZE];

int main() {
	int arr[SIZE] = { 0, };
	
	//initialize array
	init_arr(arr);
	cout << "Before Sorting\n";
	print_arr(arr);
	//do merge sort
	merge_sort(arr, 0, SIZE - 1);
	cout << "After Sorting\n";
	print_arr(arr);
	return 0;
}
//initialize array for random NUM
void init_arr(int* arr) {
	for (int i = 0; i < SIZE; i++)arr[i] = rand() % 100;
}
//print array
void print_arr(int* arr) {
	for (int i = 0; i < SIZE; i++)cout << arr[i] << " ";
	cout << "\n";
}
//do_merge
void merge(int* arr, int m, int middle, int n) {
	int i = m;//left start
	int j = middle + 1;//right start
	int k = m;//index when input sorted value
	while (i <= middle && j <= n) {//input sorted value
		if (arr[i] <= arr[j])
			sorted_arr[k]=arr[i++];
		else 
			sorted_arr[k] = arr[j++];
		k++;
	}
	if (i > middle)//when already complete sorted left array
		for (int t = j; t <= n; t++)
			sorted_arr[k++] = arr[t];
	else 
		for (int t = i; t <= middle; t++)
			sorted_arr[k++] = arr[t];
	//input left sorted values
	for (int t = m; t <= n; t++)arr[t] = sorted_arr[t];
}
//do_merge_sort
void merge_sort(int* arr, int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		merge_sort(arr, m, middle);
		merge_sort(arr, middle + 1, n);
		merge(arr, m, middle, n);
	}
	else return;
}