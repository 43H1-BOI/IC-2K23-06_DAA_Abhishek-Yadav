#include<iostream>
using namespace std;

int BinarySearch(int *arr , int size , int element){
    int start{0} , end{size-1} , mid;
    while(start <= end){
        mid = ( start + end ) / 2;

        if(arr[mid] == element ) {
            return mid;
        } else if(arr[mid] < element){
            start = mid + 1;
        } else { // if(arr[mid] > element){
            end = mid - 1;
        }
    }

    return -1;
}

int BinarySearchRecc(int *arr , int start , int end , int element){
    // edge case
    if(start > end) return -1;

    int mid = (start+end)/2;
    if(arr[mid] == element) return mid;
    
    if(arr[mid] > element){
        // search left half
        return BinarySearchRecc(arr , start , mid - 1 , element);
    } else {
        // search right half
        return BinarySearchRecc(arr , mid + 1 , end , element);
    }
}

// 0  1  2  3  4  5  6  7  8 
// 1  3  4  5  7  8  9  11 13
// 6

int main(){



    return 0;
}