#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int n, vector<int> &arr) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];  // The element to be inserted
        int j = i - 1;

        // Shifting larger elements one position to the right
        for (; j >= 0; j--) {
            if (arr[j] > temp) {
                // shift
                arr[j + 1] = arr[j];
            } else {
                // ruk jao
                break;
            }
        }

        // Insert the element in the correct position
        arr[j + 1] = temp;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    insertionSort(n, arr);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
