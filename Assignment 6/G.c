#include <stdio.h>
int Min(int a, int b) {
    return a < b ? a : b;
}

int hammingDistance(int a, int b) {
    int x = a ^ b;
    int set = 0;
    while(x > 0) {
        set += x & 1;
        x >>= 1;
    }

    return set;
}

int solution(int *tree, int num1, int num2, int n) {
    if(2 * num1 + 1 < n && 2 * num1 + 2 < n && 2 * num2 + 1 < n && 2 * num2 + 2 < n){
        if(tree[2 * num1 + 1] == -1) tree[2 * num1 + 1] = tree[num1];
        if(tree[2 * num1 + 2] == -1) tree[2 * num1 + 2] = tree[num1];
        if(tree[2 * num2 + 1] == -1) tree[2 * num2 + 1] = tree[num2];
        if(tree[2 * num2 + 2] == -1) tree[2 * num2 + 2] = tree[num2];
        int min = hammingDistance(tree[2 * num1 + 1], tree[2 * num2 + 1]);
        for(int i = 1; i < 3; i++) 
            for(int j = 1; j < 3; j++)
                min = Min(hammingDistance(tree[2 * num1 + i], tree[2 * num2 + j]), min);
        return min; 
    } else {
        return -1;
    }
}

int main() {
    int N, a, b;
    scanf("%d %d %d", &N, &a, &b);

    int tree[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &tree[i]);
    }

    int locA = -1, locB = -1;

    for(int i = 0; i < N; i++) {
        if(tree[i] == a)
            locA = i;
        else if(tree[i] == b)
            locB = i;
    }

    if(locA == -1 || locB == -1)
        printf("-1");
    else
        printf("%d", solution(tree, locA, locB, N));
}
