#include <iostream>

using namespace std;

void inputArray(double* arr, int n, int i = 0) {
    if (i < n) {
        cin >> arr[i];
        inputArray(arr, n, i + 1);
    }
}

int countNegativeElements(double* arr, int n, int i = 0) {
    if (i >= n) return 0;
    return (arr[i] < 0 ? 1 : 0) + countNegativeElements(arr, n, i + 1);
}

int findMinIndex(double* arr, int n, int i = 0, int minIndex = -1) {
    if (i >= n) return minIndex;
    if (minIndex == -1 || abs(arr[i]) < abs(arr[minIndex])) {
        minIndex = i;
    }
    return findMinIndex(arr, n, i + 1, minIndex);
}

double sumAbsoluteAfterMin(double* arr, int n, int minIndex, int i = 0) {
    if (i >= n) 
        return 0;
    if (i > minIndex) {
        return abs(arr[i]) + sumAbsoluteAfterMin(arr, n, minIndex, i + 1);
    }
    return sumAbsoluteAfterMin(arr, n, minIndex, i + 1);
}

void saveNegativeSquares(double* arr, double* negatives, int n, int i, int& negIndex) {
    if (i >= n) return;
    if (arr[i] < 0) {
        negatives[negIndex++] = arr[i] * arr[i]; 
    }
    saveNegativeSquares(arr, negatives, n, i + 1, negIndex);
}

void bubbleSort(double* arr, int n, int i = 0) {
    if (i >= n - 1) return; 
    for (int j = 0; j < n - 1 - i; j++) {
        if (arr[j] > arr[j + 1]) {
            double temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
    bubbleSort(arr, n, i + 1); 
}

void insertSortedNegatives(double* arr, double* negatives, int n, int i = 0, int negIndex = 0) {
    if (i >= n) return;
    if (arr[i] < 0) {
        arr[i] = negatives[negIndex++]; 
    }
    insertSortedNegatives(arr, negatives, n, i + 1, negIndex);
}

void printArray(double* arr, int n, int i = 0) {
    if (i >= n) {
        cout << endl;
        return;
    }
    cout << arr[i] << " ";
    printArray(arr, n, i + 1);
}

int main() {
    int n;
    cout << "Enter the number of array elements: ";
    cin >> n;

    double* arr = new double[n];

    inputArray(arr, n);

    int negativeCount = countNegativeElements(arr, n);
    cout << "Number of negative elements: " << negativeCount << endl;

    int minIndex = findMinIndex(arr, n);
    cout << "Index of minimum absolute value element: " << minIndex << endl;

    double sumAfterMin = sumAbsoluteAfterMin(arr, n, minIndex);
    cout << "Sum of absolute values after the minimum element: " << sumAfterMin << endl;

    double* negatives = new double[negativeCount];
    int negIndex = 0;

    saveNegativeSquares(arr, negatives, n, 0, negIndex);

    bubbleSort(negatives, negativeCount);

    insertSortedNegatives(arr, negatives, n);

    cout << "Transformed array with negative elements squared and sorted:\n";
    printArray(arr, n);

    delete[] arr;
    delete[] negatives;

    return 0;
}
