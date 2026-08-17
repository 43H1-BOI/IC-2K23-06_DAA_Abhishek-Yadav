# Sorting :
- ## Bubble Sort
```cpp
void swap(int& num1 , int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void BubbleSort(int *arr , int size) {
    for (int i{0}; i < size ; i++) {
        for (int j{0}; j < size - i - 1 ; j++) {
            if (arr[j+1] < arr[j]) {
                swap(arr[j] , arr[j+1]);
            }
        }
    }
}
```
---
- ## Recursive Bubble Sort

---
- ## Selection Sort
```cpp
void SelectionSort(int *arr , int size) {
    for (int i{ 0 }; i < size - 1; i++) {
        for (int j{ i + 1 }; j < size; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[j] , arr[i]);
            }
        }
    }
}
```
- ## Insertion Sort
- ## Recursive Insertion Sort
- ## Merge Sort
- ## Quick Sort