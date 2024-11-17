#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= high && arr[i] > pivot) i++;
        while (arr[j] < pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

int main() {
    int arr[7] = {10, 3, 7, 4, 2, 9, 1};
    int size = 7;

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

