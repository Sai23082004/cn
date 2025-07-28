#include <stdio.h>
#include <string.h>

int main() {
    int i, k, a, count = 0;
    char c[100];

    printf("\nEnter the data to be sent (only 0s and 1s): ");
    fgets(c,sizeof(c),stdin);

    a = strlen(c);


    for (i = 0; i < a; i++) {
        if (c[i] == '1') {
            count++;
            if (count == 5) {
                for (k = a; k > i + 1; k--) {
                    c[k] = c[k - 1];
                }
                c[i + 1] = '0';  
                a++;
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    printf("Data after bit stuffing: %s\n", c);


    count = 0;
    for (i = 0; i < a; i++) {
        if (c[i] == '1') {
            count++;
            if (count == 5) {
                for (k = i + 1; k < a; k++) {
                    c[k] = c[k + 1]; 
                }
                a--;
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    printf("Data after de-stuffing: %s\n", c);

    return 0;
}
