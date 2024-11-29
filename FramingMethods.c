// Implement the data link layer farming methods such as Character Count, Character Stuffing and Bit Stuffing method.


// Character Count

#include <stdio.h>
#include <string.h>
#define MAX_MESSAGE_LENGTH 100

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char framedMessage[MAX_MESSAGE_LENGTH + 10];

    printf("Enter a message to frame using Character Count method:\n");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    int messageLength = strlen(message);
    sprintf(framedMessage, "%d%s", messageLength, message);

    printf("\nFramed Message: %s\n", framedMessage);

    return 0;
}


// Character Stuffing

#include <stdio.h>
#include <string.h>

int main() {
    char a[30], fs[50] = "", t[3], sd, ed, x[3], s[3], d[3], y[3];
    int i;

    printf("Enter characters to be stuffed: ");
    scanf("%s", a);

    printf("Enter a character that represents the starting delimiter: ");
    scanf(" %c", &sd);

    printf("Enter a character that represents the ending delimiter: ");
    scanf(" %c", &ed);

    x[0] = s[0] = sd;
    x[1] = s[1] = sd;
    x[2] = s[2] = '\0';

    y[0] = d[0] = ed;
    y[1] = d[1] = ed;
    y[2] = d[2] = '\0';

    strcat(fs, x);

    for (i = 0; i < strlen(a); i++) {
        t[0] = a[i];
        t[1] = '\0';
        if (t[0] == sd)
            strcat(fs, s);
        else if (t[0] == ed)
            strcat(fs, d);
        else
            strcat(fs, t);
    }

    strcat(fs, y);
    printf("\nAfter stuffing: %s\n", fs);

    return 0;
}


// Bit Stuffing

#include <stdio.h>

int main() {
    int a[20], b[30], i, j = 0, k, count, n;

    printf("Enter frame length: ");
    scanf("%d", &n);

    printf("Enter input frame (0's & 1's only): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    i = 0;
    while (i < n) {
        if (a[i] == 1) {
            b[j] = a[i];
            count = 1;

            for (k = i + 1; a[k] == 1 && k < n && count < 5; k++) {
                j++;
                b[j] = a[k];
                count++;
            }

            if (count == 5) {
                j++;
                b[j] = 0;
            }
            i = k;
        } else {
            b[j] = a[i];
            i++;
        }
        j++;
    }

    printf("After stuffing the frame is: ");
    for (i = 0; i < j; i++) {
        printf("%d", b[i]);
    }
    printf("\n");

    return 0;
}
