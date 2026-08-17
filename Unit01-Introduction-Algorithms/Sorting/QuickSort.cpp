#include<bits/stdc++.h>
#include "QuickSort.h"

using namespace std;

void swap(int& x , int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void QuickSort(int arr[ ] , int start , int end) {
    if (start >= end) { // Base Case
        return;
    }

    int pIndex = start; // correct index of pivotElement
    int pivotElement = arr[end]; // element to be placed on correct position

    for (int i = start; i < end; i++) {
        if (arr[i] < pivotElement) {
            swap(arr[i] , arr[pIndex]);
            pIndex++;
        }
    }

    // swapping elemnt at pIndex with pivotElement
    swap(arr[pIndex] , arr[end]);

    // 1st SubArray
    QuickSort(arr , start , pIndex - 1);

    // 2nd SubArray
    QuickSort(arr , pIndex + 1 , end);

}