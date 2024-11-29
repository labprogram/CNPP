// Write a program for congestion control using Leaky bucket algorithm.

#include<stdio.h>

int main() {
    int incoming, outgoing, buck_size, n, store = 0;

    printf("Enter bucket size, outgoing rate, and number of inputs: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);

    while (n > 0) {
        printf("Enter the incoming packet size: ");
        scanf("%d", &incoming);

        printf("Incoming packet size: %d\n", incoming);

        if (incoming <= (buck_size - store)) {
            store += incoming;
            printf("Bucket buffer size: %d out of %d\n", store, buck_size);
        } else {
            printf("Dropped %d packets\n", incoming - (buck_size - store));
            store = buck_size;
            printf("Bucket buffer size: %d out of %d\n", store, buck_size);
        }

        store = (store > outgoing) ? store - outgoing : 0; 
        printf("After outgoing, %d packets left out of %d in buffer\n", store, buck_size);

        n--;
    }

    return 0;
}
