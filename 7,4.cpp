#include <iostream>
using namespace std;

int findFirstOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;  // Search in the left half
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

int findLastOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;  // Search in the right half
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

int countOccurrences(int arr[], int n, int target) {
    int first = findFirstOccurrence(arr, n, target);
    if (first == -1) {
        return 0;  // Target not found
    }

    int last = findLastOccurrence(arr, n, target);
    return (last - first + 1);
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    
    int result = countOccurrences(arr, n, target);
    cout << "Number of occurrences of target: " << result << "\n";

    return 0;
}

