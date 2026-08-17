#include<iostream>
using namespace std;

void printArr(int arr[ ] , int size) {
    for (int i{ 0 }; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void swap(int& num1 , int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void SelectionSort(int arr[ ] , int size) {
    for (int i{ 0 }; i < size - 1; i++) {
        for (int j{ i + 1 }; j < size; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[j] , arr[i]);
            }
        }
    }
}

int main( ) {
    int arr[5] = { 5,1,8,2,3 };
    int size = 5;

    cout << "Array Before Sorting : ";
    printArr(arr , size);

    SelectionSort(arr , 5);

    cout << "Array After Sorting : ";
    printArr(arr , size);

    return 0;
}