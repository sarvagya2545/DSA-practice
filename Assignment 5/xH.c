#include<stdio.h>
int maxheap[100000],minheap[100000],lmax=0,lmin=0;

void minheapify_down() {
  int cur=0;
  while(cur<lmin && (2*cur+1 < lmin && (minheap[cur] > minheap[2*cur +1]))||
        (2*cur+2 < lmin && (minheap[cur]> minheap[2*cur+2])) ) {
    if(minheap[2*cur+1] < minheap[2*cur+2] || (2*cur + 2)>=lmin) {
      int temp = minheap[2*cur+1];
      minheap[2*cur+1] = minheap[cur];
      minheap[cur]=temp;
      cur = 2*cur + 1;
    } else {
      int temp = minheap[2*cur+2];
      minheap[2*cur+2] = minheap[cur];
      minheap[cur]=temp;
      cur = 2*cur + 2;
    }
  }
}

void maxheapify_down() {
  int cur=0;
  while(cur < lmax && (2*cur+1 < lmax && (maxheap[cur] < maxheap[2*cur +1]))||(2*cur+2 < lmax && (maxheap[cur]< maxheap[2*cur+2])) ) {
    if(maxheap[2*cur+1] > maxheap[2*cur+2] || (2*cur + 2)>=lmax) {
      int temp = maxheap[2*cur+1];
      maxheap[2*cur+1] = maxheap[cur];
      maxheap[cur]=temp;
      cur = 2*cur + 1;
    } else {
      int temp = maxheap[2*cur+2];
      maxheap[2*cur+2] = maxheap[cur];
      maxheap[cur]=temp;
      cur = 2*cur + 2;
    }
  }
}

void minheapify_up() {
    int cur = lmin-1;
    while(minheap[cur]< minheap[(cur-1)/2]) {
        int temp = minheap[cur];
        minheap[cur]= minheap[(cur-1)/2];
        minheap[(cur-1)/2] = temp;
        cur = (cur-1)/2;
    }
}

void maxheapify_up() {
    int cur = lmax-1;
  
    while(maxheap[cur]> maxheap[(cur-1)/2]) {
        int temp = maxheap[cur];
        maxheap[cur]=maxheap[(cur-1)/2];
        maxheap[(cur-1)/2] = temp;
        cur = (cur-1)/2;
    }
}
 
float findMedian(){
    float median;
    if((lmax+lmin)%2 == 0) {
        int max = maxheap[0];
        int min = minheap[0];
        median = (max + min) / 2;
    } else {
        median = maxheap[0];   
    }
    return median;
}

void insert(int num) {
    if(lmax==0 && lmin==0) {
        maxheap[lmax++]= num;
    } else if(lmin==0 && lmax!=0) {
        if(num < maxheap[0]) {
            int temp = maxheap[0];
            maxheap[0]= num;
            minheap[lmin++]= temp;
        } else {
            minheap[lmin++]=num;
        }
    } else if(lmax!=0 && lmin!=0) {
        int i;
        if(lmax > lmin) {
            if(num < maxheap[0]) { 
                    minheap[lmin++]=maxheap[0];
                    minheapify_up();
                    maxheap[0]=num;
                    maxheapify_down();
                } else {
                    minheap[lmin++]=num;
                    minheapify_up();
                }
        } else if(lmin >= lmax) {
            if(num > minheap[0]) {
                maxheap[lmax++]=minheap[0];
                maxheapify_up();
                minheap[0]=num;
                //lmin = lmin-1;
                minheapify_down();
            } else {
                maxheap[lmax++]=num;
                maxheapify_up();
            }
        } else {
            if(num > minheap[0]) {
                minheap[lmin++]=num;
                minheapify_up();
            } else {
                maxheap[lmax++]=num;
                maxheapify_up();
            }
        }
    }
}
 
int main() {
    int N,t,a;
    scanf("%d",&N);
    t=N;
    while(t>0) {
        scanf("%d",&a);
        insert(a);
        int x = findMedian();
        printf("%d ",x);
        t--;
    }
    return 0; 
}