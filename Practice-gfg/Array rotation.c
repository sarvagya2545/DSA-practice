#include <stdio.h>

// x < y
int gcd(int x, int y) { 
    if(y == 0) return x;
    else return gcd(y, x % y);
}

void leftRotate(int *arr, int n, int d) {
    // rotate by d times
    // when d > n, there will be unneccessary rotation, so remove the unnecessary rotations
    d = d % n;
    int g_c_d = gcd(n,d);
    for(int i = 0; i < g_c_d; i++) {
        
    }

}

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
}