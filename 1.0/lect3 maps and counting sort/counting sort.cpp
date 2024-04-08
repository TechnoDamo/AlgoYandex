#include <iostream>
using namespace std;

// отсортируем массив методом сортировки подсчетом
void countingSort(int a[], int min, int max, int n) {
    int k = max - min + 1;
    int *count = new int[k];
    for (int i = 0; i < n; i++) {
        count[max - a[i]]++;
    }
    for (int i = 0; i <= max - min; i++) {
        for (int j = 0; j < count[i]; j++) {
            a[i+j] = min + i;
        }
    }
    delete[] count;
}

void printArr(int a[], int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    printArr(a, 10);
    countingSort(a, 1, 10, 10);
    printArr(a, 10);
    return 0;
}
