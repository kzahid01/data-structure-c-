#include <iostream>
using namespace std;

int findLastOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;  // Update result with current index
            low = mid + 1;  // Continue searching in the right half
        } 
        else if (arr[mid] < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    
    int result = findLastOccurrence(arr, n, target);
    if (result != -1) {
        cout << "Last occurrence of target is at index " << result << "\n";
    } else {
        cout << "Target not found\n";
    }

    return 0;
}

