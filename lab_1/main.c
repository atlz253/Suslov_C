#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int count, i, si=0;
    scanf("%hd", &count);
    unsigned short int arr[count];
    for (i=0; i<count ;i++) {
        printf("\nElement %d: ", i);
        scanf("%hd", &arr[i]);
        if (arr[si] > arr[i] || i==0) {
            si = i;
        }
    }
    printf("%d", si);
    return 0;
}
