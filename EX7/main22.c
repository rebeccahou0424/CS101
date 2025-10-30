#include <stdio.h>
int main() {
    int x = 2;
    int* ip = &x;

    printf("%x\n", ip);  // 印出位址
    printf("%x\n", *ip); // 印出值 2
    return 0;
}
