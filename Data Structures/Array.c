#include <stdio.h>

struct IntArray
{
    int* container;
    int length;
    void (*push)(const struct IntArray*);
};

void push(struct IntArray a) {
    int p = a.container;
}

int main() {
    
    return 0;
}