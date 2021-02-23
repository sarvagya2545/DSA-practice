#include <stdio.h>

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void bubbleSort(int arr[], int n) {
    int swap_occurred;
    for(int j = 0; j < n - 2; j++) {

        swap_occurred = 0;

        for(int i = 0; i < n - j - 1; i++) {

            if(arr[i] > arr[i + 1]) {
                
                swap_occurred = 1;
                swap(&arr[i], &arr[i + 1]);
            }
        }

        if(!swap_occurred) {
            break;
        }
    }
}

void insertionSort(int arr[], int n) {

    // APPROACH 1
    for(int i = 0; i < n - 1; i++) {
        // take the (i+1)th element and insert it into the elements array until i, assuming them to be sorted
        for(int j = 0; j < i + 1; j++) {
            if(arr[j] > arr[i + 1]) {
                int temp = arr[i + 1];

                // right rotate the subarray from index j to i + 1
                for(int k = i + 1; k > j; k--) {
                    arr[k] = arr[k - 1];
                }

                arr[j] = temp;
            }
        }
    }

    // APPROACH 2
    // for(int i = 1; i < n - 1; i++) {

    // }
}

void merge(int arr[], int l, int mid, int r) {
    int lNo = mid - l + 1;
    int rNo = r - mid;

    int R[rNo];
    int L[lNo];

    int i,j,k;

    j = 0;
    k = 0;

    for(i = 0; i < lNo; i++) {
        L[i] = arr[l + i];
    }

    for(j = 0; j < rNo; j++)
        R[j] = arr[mid + 1 + j];

    i = l;
    j = 0;
    k = 0;

    while(j < lNo && k < rNo) {
        if(L[j] <= R[k]) {
            arr[i] = L[j];
            j++;
        } else {
            arr[i] = R[k];
            k++;
        }
        i++;
    }

    // copy the remaining elements if any
    while (j < lNo) {
        arr[i] = L[j];
        j++;
        i++;
    }

    while(k < rNo) {
        arr[i] = R[k];
        k++;
        i++;
    }
}

void mergeSort(int arr[], int l, int r) {

    if(l < r) {
        int mid = (l + r) / 2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int partition(int arr[], int l, int r) {

    int pivot = arr[l];
    int i = l, j = r;

    while(i < j) {
        do{
            i++;
        } while(arr[i] <= pivot);

        do {
            j--;
        } while (arr[j] > pivot);
        
        if(i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void quickSort(int arr[], int l, int r) {
    if(l < r) {
        int j = partition(arr, l, r);
        quickSort(arr, l, j);
        quickSort(arr, j+1, r);
    }
}

int main() {

    int arr[] = { 5,3,4,7,6,8,1,2 };
    int n = 8;

    // bubbleSort(arr, n);

    // insertionSort(arr, n);
    // mergeSort(arr, 0, n - 1);
    
    quickSort(arr, 0, n);

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}