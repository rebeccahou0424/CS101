#include <stdio.h>
int main() {
    int x;
    int* ip = &x;
    *ip = 2;
    printf("%x\n", *ip);
    return 0;
}
