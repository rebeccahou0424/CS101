#include <stdio.h>

int main() {
    FILE* fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    int ra;
    char rb;
    float rc;

    for (int i = 0; i < 3; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (int i = 0; i < 3; i++)
        printf("%c ", b[i]);
    printf("\n");

    for (int i = 0; i < 3; i++)
        printf("%f ", c[i]);
    printf("\n");

    return 0;
}