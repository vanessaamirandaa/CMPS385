//
//  main.cpp
//  Data Structures
//
#include <iostream>
using namespace std;

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is at mid
        if (arr[mid] == target)
            return mid;
        // If target is smaller, ignore right half
        else if (arr[mid] > target)
            right = mid - 1;
        // If target is larger, ignore left half
        else
            left = mid + 1;
    }

    // Target not found
    return -1;
}

int main() {
    // Sorted array (required for binary search)
    int arr[] = {3, 8, 15, 23, 42, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter a number to search: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
