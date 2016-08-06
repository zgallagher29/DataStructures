#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

//get data
void read(int A[], int n)
{
	int i;
	for (i = 0; i<n; i++)
		cin >> A[i];
}

//show data
void display(int A[], int n)
{
	int i;
	for (i = 0; i<n; i++)
		cout << A[i] << " ";
}


int fibo(int n);
int Fibonacci_Search(int A[], int n, int key);
int Binary_Search(int A[], int n, int key);


int main(){
	cout << "Welcome! How big would you like the array to be?" << endl;
	int sizeOfArray=0;
	cin >> sizeOfArray;

	int A[sizeOfArray];
	for (int i = 0; i < sizeOfArray; i++){
		cout << "Enter a number" << endl;
		cin >> A[i];
	}


	cout << "Fibo Search: " << endl;


	cout << "Binary Search" << endl;
	//ask user how big she/he wants the array
	//have them enter numbers, recall binary and fib need to be 
	//ask the user what number to search for
	//in ascending order to test unlike Sequential
	//print out the index that the number is located
	return 0;
}
int fibo(int n){
	if (n <= 1){
		return n;

	}
	else{
		return (fibo(n - 1) + fibo(n - 2));
	}

}
int Fibonacci_Search(int A[], int n, int key){
	int f1, f2, mid, t, j, f;
	j = 1;
	while (fibo(j) <= n) j++;
	f = fibo(j);
	f1 = fibo(j - 2);
	f2 = fibo(j - 3);
	mid = n - f1 + 1;
	while (key != A[mid]){
		if (mid<0 || key>A[mid]){
			if (f1 == 1) return -1;
			mid = mid + f2;
			f1 = f1 - f2;
			f2 = f2 - f1;
		}
	}

}
int Binary_Search(int A[], int n, int key){

	int low = 0, high = n - 1, mid;
	while (low <= high){
		mid = (ligh + high) / 2;
		mid((first + last) / 2);
		if (A[mid] == key){
			return mid;

		}
		else if (key < A[mid]){
			high = mid - 1;

		}
		else{
			low = mid + 1; 

		}
	}
	return -1; 

}
