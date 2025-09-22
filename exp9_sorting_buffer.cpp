#include <stdio.h>
#include <stdlib.h>
struct frame {
    int fslno;         // Frame sequence number
    char finfo[20];    // Frame information
};
struct frame arr[10];
int n;

void sort() {
    int i, j, ex;
    struct frame temp;
    for (i = 0; i < n; i++) {
        ex = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].fslno > arr[j+1].fslno) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                ex++;
            }
        }
        if (ex == 0) break;  // early stop if already sorted
    }
}
int main() {
    int i;
    printf("\nEnter the number of frames: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter Frame %d sequence number: ", i+1);
        scanf("%d", &arr[i].fslno);
        printf("Enter Frame %d information: ", i+1);
        scanf("%s", arr[i].finfo);
    }
    printf("\nFrames received (unsorted):\n");
    for (i = 0; i < n; i++)
        printf("%d\t%s\n", arr[i].fslno, arr[i].finfo);
    sort();
    printf("\nFrames after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d\t%s\n", arr[i].fslno, arr[i].finfo);
    return 0;
}
