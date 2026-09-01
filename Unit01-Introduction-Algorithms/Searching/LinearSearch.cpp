#include<iostream>
using namespace std;

int LinearSearch(int *arr , int size , int element){
    for(size_t idx ; idx < size ; idx++){
        if(arr[idx] == element) return idx;
    }
    return -1;
}

int main(){

    return 0;
}