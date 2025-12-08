#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << "Even numbers in the array are: ";
    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) { // Check if the number is even
            cout << arr[i] << " ";
        }
    }

    return 0;
}
