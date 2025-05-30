#include <iostream>
using namespace std;

int main() {
    int arr[5];

    // Accept 5 elements
    cout << "Enter 5 elements into the array:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": ";
        cin >> arr[i];
    }

    int index;
    cout << "\nEnter index to access (0-4): ";
    cin >> index;

    try {
        if (index < 0 || index > 4) {
            throw out_of_range("Index out of bounds! Valid range is 0 to 4.");
        }
        cout << "Element at index " << index << " is: " << arr[index] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}