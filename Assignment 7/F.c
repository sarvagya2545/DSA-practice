#include <stdio.h>

int game(char **dict, int n) {
    char lastLetter = '*';
    for(int i = 0; i < n; i++) {
        
        printf("%s\n", dict[i]);

        // set last letter as the last letter of the string. 

        // compare last letter with first letter and return output

    }
    return 0;
}

int main() {
    int t, n;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        char **dict = NULL;
        // dict = malloc(n * sizeof());
        for(int i = 0; i < n; i++) {
            scanf("%s", dict[i]);
        }

        if(game(dict, n)) { printf("Alice "); } else { printf("Bob "); }
    }

    return 0;
}