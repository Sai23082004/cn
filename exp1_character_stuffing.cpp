#include <stdio.h>
#include <string.h>

int main()
{
    char a[50], b[50], c[100];
    int i = 0, j, k, m = 0, count, l1, l2;

    printf("\nEnter the data to send: ");
    fflush(stdin);
    gets(a);  

    printf("\nEnter the delimiter: ");
    fflush(stdin);
    gets(b); 

    l1 = strlen(a);
    l2 = strlen(b);

    c[0] = 'S';  

    for (i = 0; i < l2; i++)
        c[i + 1] = b[i];

    int index = i + 1; // keep track of c[] index

    for (j = 0; j < l1; j++)
    {
        count = 0;
        for (k = 0, m = j; k < l2; k++, m++)
        {
            if (a[m] != b[k])
            {
                count = 1;
                break;
            }
        }

        if (count == 0)
        {
            for (k = l1 + l2 - 1; k >= j + l2; k--)
                a[k] = a[k - l2];

            for (k = 0; k < l2; k++)
                a[j + k] = b[k];

            j += l2 - 1;
            l1 += l2;
        }
    }

    for (k = 0; k < l1; k++)
        c[++index] = a[k];

    for (k = 0; k < l2; k++)
        c[++index] = b[k];

    c[++index] = 'E';  
    c[++index] = '\0';

    printf("\nData after stuffing: ");
    puts(c);

   
    for (j = 0; j <= l1 - l2; j++)
    {
        count = 0;
        m = j;
        for (k = 0; k < l2; k++)
        {
            if (a[m++] != b[k])
            {
                count = 1;
                break;
            }
        }

        if (count == 0)
        {
            for (k = m; k < l1; k++)
                a[k - l2] = a[k];

            l1 -= l2;
            j = -1; 
        }
    }

    printf("Data after destuffing: ");
    for (i = 0; i < l1; i++)
        printf("%c", a[i]);

    printf("\n");

    return 0;
}
