#include <stdio.h>

int main() {
    int n = 5;
    int arr[n];

    // for(int i = 0; i < 5; i++) {
        
    // }

    for(int i = 1; i < n - 1; i++) {
        int j;
        for(j = 0; j < i; j++) {
            if(arr[j] > arr[i])	{
                break;
            }
        }
        int temp = arr[i];
        int ctr = i;
        while( ctr > j ) {
            arr[ctr] = arr[ctr - 1];
        }
        arr[ctr] = temp;
    }
}