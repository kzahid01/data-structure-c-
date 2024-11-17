#include <iostream>
using namespace std;

void selectionSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
        cout << "After iteration " << i + 1 << ": ";
        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[5] = {12, 4, 7, 9, 3};
    int size = 5;

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSortDescending(arr, size);

    cout << "Sorted array in descending order: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

