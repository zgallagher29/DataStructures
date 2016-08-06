#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

//get data
void read(int A[], int n)
{
	int i;
	int temp;
	for (i = 0; i < n; i++){
		cout << "Enter a number:" << endl;
		cin >> temp;
		A[i] = temp;
	}
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
	int number= 0;
	cout << "Welcome! How big would you like the array to be?" << endl;
	
	cin >> number;

	int *A= new int[number];
	read(A, number);
	cout << "Which number do you want to search for? " << endl;
	int k = 0;
	cin >> k;
	cout << "Here is your data: ";
	display(A, number);
	cout << "  " << endl;
	cout << "Fibo Search: " << endl;
	cout << k << " is at index: ";
	cout << Fibonacci_Search(A, number, k) << endl;
	cout << "---------------------" << endl;
	cout << "Binary Search" << endl;
	cout << k << " is at index: ";
	cout << Binary_Search(A, number, k) << endl;
	//ask user how big she/he wants the array
	//have them enter numbers, recall binary and fib need to be 
	//ask the user what number to search for
	//in ascending order to test unlike Sequential
	//print out the index that the number is located
	for (int i = 0; i < number; i++){
		delete[] &A[i];
	}
	return 0;

}
int fibo(int n){
	

	if (n == 0||n==1){
		return 1;
		
	}
	else{
		return (fibo(n - 1) + fibo(n - 2));
	}

}
int Fibonacci_Search(int A[], int n, int key){
	int f1, f2, mid, t, j, f;
	j = 1;
	while (fibo(j) <= n){ 
		j++; }
	f = fibo(j);
	f1 = fibo(j - 2);
	f2 = fibo(j - 3);
	mid = n - f1 + 1;

	while (key != A[mid]){
		
		
		if (mid<0 || key>A[mid]){
			if (f1 == 1) {
				return -1; }
			mid = mid + f2;
			f1 = f1 - f2;
			f2 = f2 - f1;
		}
		else{
			if (f2 == 0){
				return -1;

			}
			mid = mid - f2;
			t = f1 - f2;
			f1 = f2;
			f2 = t;
	
		}
		
	}

	 return mid;
}
int Binary_Search(int A[], int n, int key){

	int low = 0, high = n - 1, mid;
	while (low <= high){
		mid = (low+high) / 2;
		
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
