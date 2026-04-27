#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    // TODO:
    // Create temporary arrays
    // Copy data
    // Merge sorted halves back into arr

    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    //create temporary array
    vector<int> leftArr(leftSize), rightArr(rightSize);

    //copies data into the sub arrays
    for (int i = 0; i < mid; ++i) leftArr[i] = arr[left + i];
    for (int j = mid + 1; j < right; ++j) rightArr[j] = arr[mid + j + 1];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize){
    if (leftArr[i] <= rightArr[j]){
        arr[k] = leftArr[i];
        ++i;
    } else {
        arr[k] = rightArr[j];
        ++j;
    }
    ++k;
}

    //remaining values get dumped into the end of the sorted array
    while (i < leftSize) arr[k++] = leftArr[i++];
    while (j < rightSize) arr[k++] = rightArr[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // TODO:
        // Find middle
        // Recursively sort left half
        // Recursively sort right half
        // Merge both halves

        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid); //recursion for sorting left half

        mergeSort(arr, mid + 1, right); //recursion for sorting right half

        merge(arr, left, mid, right); //merging sorted halves
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};
    int n = 10;

    cout << "Before Sorting: ";
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    display(arr, n);

    return 0;
}
