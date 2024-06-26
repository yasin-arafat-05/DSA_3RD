#include <iostream>
using namespace std;

#define yasin {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

void quicksort(int arr[], int BEG, int END);

int main() {
    yasin;
    int arr[5] = {8, 6, 9, 4, 5};
    int size = 5;

    quicksort(arr, 0, size - 1);

    cout << "sorted array: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

void quicksort(int arr[], int BEG, int END) {
    if (BEG >= END) return;

    int LEFT = BEG, RIGHT = END, LOC = BEG;

    // Partitioning phase
    while (LOC < RIGHT) {
        while (LOC < RIGHT && arr[LOC] <= arr[RIGHT]) {
            RIGHT--;
        }
        if (LOC == RIGHT) break;
        if (arr[LOC] > arr[RIGHT]) {
            swap(arr[LOC], arr[RIGHT]);
            LOC = RIGHT;
        }

        while (LEFT < LOC && arr[LEFT] <= arr[LOC]) {
            LEFT++;
        }
        if (LOC == LEFT) break;
        if (arr[LEFT] > arr[LOC]) {
            swap(arr[LOC], arr[LEFT]);
            LOC = LEFT;
        }
    }

    // Recursion phase
    quicksort(arr, BEG, LOC - 1); // Sort the sub-array with elements less than the pivot
    quicksort(arr, LOC + 1, END); // Sort the sub-array with elements greater than the pivot
}
