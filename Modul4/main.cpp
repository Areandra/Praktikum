#include <iostream>
using namespace std;

// Fungsi Bubble Sort
void bubblesort(int arr[], int n) {
    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - i - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi Insertion Sort
void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            } else {
                break;
            }
        }
    }
}

// Fungsi Selection Sort
void selectionsort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Fungsi Merge untuk Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi Merge Sort
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Fungsi utama (main)
int main() {
    int arr[] = {7, 3, 8, 5, 2, 1, 4, 6};
    int lenarr = sizeof(arr) / sizeof(arr[0]);

    // Bubble Sort
    int bubbleArr[lenarr];
    copy(arr, arr + lenarr, bubbleArr);
    bubblesort(bubbleArr, lenarr);
    cout << "Bubble Sort: ";
    for (int i = 0; i < lenarr; i++)
        cout << bubbleArr[i] << " ";
    cout << "\n";

    // Insertion Sort
    int insertionArr[lenarr];
    copy(arr, arr + lenarr, insertionArr);
    insertionsort(insertionArr, lenarr);
    cout << "Insertion Sort: ";
    for (int i = 0; i < lenarr; i++)
        cout << insertionArr[i] << " ";
    cout << "\n";

    // Selection Sort
    int selectionArr[lenarr];
    copy(arr, arr + lenarr, selectionArr);
    selectionsort(selectionArr, lenarr);
    cout << "Selection Sort: ";
    for (int i = 0; i < lenarr; i++)
        cout << selectionArr[i] << " ";
    cout << "\n";

    // Merge Sort
    int mergeArr[lenarr];
    copy(arr, arr + lenarr, mergeArr);
    mergesort(mergeArr, 0, lenarr - 1);
    cout << "Merge Sort: ";
    for (int i = 0; i < lenarr; i++)
        cout << mergeArr[i] << " ";
    cout << "\n";

    return 0;
}
