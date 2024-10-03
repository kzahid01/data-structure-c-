#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        cout << "Active range: ";
        for (int i = low; i <= high; ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    
    int result = binarySearch(arr, n, target);
    if (result != -1) {
        cout << "Target found at index " << result << "\n";
    } else {
        cout << "Target not found\n";
    }

    return 0;
}

