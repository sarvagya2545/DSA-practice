#include <stdio.h>
int seatsOccupied = 0, maxSeatsOccupied = 0;

int main() {
    int t, n, x;

    scanf("%d", &t);

    while(t--) {
        char c;
        scanf("%c %d", &c, &n);

        switch(c) {
            case 'E': 
                seatsOccupied += n;
                break;
            case 'L':
                x = n;
                while(x--) {
                    int i;
                    scanf(" %d", &i);
                }
                seatsOccupied -= n;
                break;
            default:
                break;            
        }

        maxSeatsOccupied = maxSeatsOccupied < seatsOccupied ? seatsOccupied : maxSeatsOccupied;
        printf("seats occupied -> %d\n", seatsOccupied);
        printf("max seats occupied -> %d\n", maxSeatsOccupied);
    }

    printf("%d", maxSeatsOccupied);

    return 0;
}