#include <stdio.h>
#include <stdlib.h>
void xor_division(int a[], int g[], int m, int n, int r[], int div[]) {
    int i, j, k = 0;
    for (i = 0; i <= n; i++)
        r[i] = a[i];
    for (i = n; i <= m + n; i++) {
        if (i > n) {
            for (j = 0; j < n; j++)
                r[j] = r[j + 1];
            r[j] = a[i];
        }
        if (r[0])
            div[k++] = 1;
        else {
            div[k++] = 0;
            continue;
        }
        for (j = 0; j <= n; j++)
            r[j] = r[j] ^ g[j];
    }
}
int main() {
    int i, j, k = 0;
    int flag = 1;
    int a[50], g[20], r[20], div[50];
    int n, m;
    system("clear");
    printf("Enter degree of generator: ");
    scanf("%d", &n);
    printf("Enter the generator (in binary):\n");
    for (i = 0; i <= n; i++)
        scanf("%d", &g[i]);
    printf("Enter the degree of the frame: ");
    scanf("%d", &m);
    printf("Enter the frame (in binary):\n");
    for (i = 0; i <= m; i++)
        scanf("%d", &a[i]);
    if (m < n || g[0] == 0) {
        printf("Not a proper generator.\n");
        exit(0);
    }
    for (i = m + 1; i <= m + n; i++)
        a[i] = 0;
    xor_division(a, g, m, n, r, div);
    printf("\nQuotient is: ");
    for (j = 0; j < m + 1; j++)
        printf("%d", div[j]);
    printf("\nRemainder is: ");
    for (i = 1; i <= n; i++)
        printf("%d", r[i]);
    printf("\nTransmitted frame is: ");
    for (i = 0; i <= m; i++)
        printf("%d", a[i]);
    for (i = 1; i <= n; i++) {
        a[m + i] = r[i];  // Append CRC bits
        printf("%d", r[i]);
    }
    printf("\n");
    // Receive frame
    printf("\nEnter the degree of received frame: ");
    scanf("%d", &m);
    printf("Enter the received frame:\n");
    for (i = 0; i <= m; i++)
        scanf("%d", &a[i]);

    k = 0;
    xor_division(a, g, m - n, n, r, div);  // m - n because frame includes CRC
    printf("\nQuotient is: ");
    for (j = 0; j <= m - n; j++)
        printf("%d", div[j]);
    printf("\nRemainder is: ");
    for (i = 1; i <= n; i++)
        printf("%d", r[i]);
    flag = 1;
    for (i = 1; i <= n; i++) {
        if (r[i]) flag = 0;
    }

    if (flag)
        printf("\nNo Error Detected.\n");
    else
        printf("\nError Detected in Received Frame.\n");

    return 0;
}
