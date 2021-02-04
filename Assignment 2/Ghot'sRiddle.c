#include <stdio.h>

// implementation of f(x)
int F(int x) {
  int cnt = 0;
  // arr[0] < arr[1] to be maintained 
  int arr[2] = {-1,-1};
  for(int i = 2; i < x; i++) {
    if(x%i == 0) {
      cnt++;
      if(arr[0] == -1)
        arr[0] = i;
      else if(arr[1] == -1){
        if(i > arr[0]) {
          arr[1] = i;
        } else {
          arr[1] = arr[0];
          arr[0] = i;
        }
      } else {
        if(i > arr[0] && i > arr[1]) {
          arr[0] = arr[1];
          arr[1] = i;
        }

        if(i > arr[0] && i < arr[1]) {
          arr[0] = i;
        }

        // if i < arr[0] we don't want to mutate the array
      }
    }
  }

  if(cnt >= 2)
    return F(arr[0]) + F(arr[1]);

  return x;
}

int main() {

  int N;
  scanf("%d", &N);

  printf("%d", F(N));
}