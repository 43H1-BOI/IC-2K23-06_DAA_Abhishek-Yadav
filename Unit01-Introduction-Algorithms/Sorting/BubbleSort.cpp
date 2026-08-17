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

void BubbleSort(int arr[ ] , int size) {
    for (int i{0}; i < size ; i++) {
        for (int j{0}; j < size - i - 1 ; j++) {
            if (arr[j+1] < arr[j]) {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}


/* Dry run Bubble Sort
    arr = [ 5,1,8,2,3 ]
    size = 5

    i = 0;
    {
        j = 0;
            arr[1] < arr[0]
            1 < 5

        j = 1;
            arr[2] < arr[1]
            8 < 1
                swap(8,1)

        arr = [ 5,8,1,2,3 ]
        
        j = 2;
            arr[3] < arr[2]
            2 < 1
                swap(2,1)

        arr = [ 5,8,2,1,3 ]
        
        j = 3;
            arr[4] < arr[3]
            3 < 1
                swap(3,1)

        arr = [ 5,8,2,3,1 ]

        j < size - i - 1
        j < 5 - 0 - 1
        j < 4
    }
    
    arr = [ 5,8,2,3,1 ]
    i = 1;
    {
        j = 0;
            arr[1] < arr[0]
            8 < 5
                swap(8,5)
        arr = [ 8,5,2,3,1 ]
            
        j = 1;
            arr[2] < arr[1]
            2 < 5
       
        j = 2;
            arr[3] < arr[2]
            3 < 2
                swap(3,2)

        arr = [ 8,5,3,2,1 ]

        j < size - i - 1
        j < 5 - 1 - 1
        j < 3
    }    

*/

int main( ) {
    int arr[5] = { 5,1,8,2,3 };
    int size = 5;

    cout << "Array Before Sorting : ";
    printArr(arr , size);

    BubbleSort(arr , 5);

    cout << "Array After Sorting : ";
    printArr(arr , size);

    return 0;
}