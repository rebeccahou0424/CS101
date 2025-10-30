#include <stdio.h>
int main() {
    int v = 65;
    int* p = NULL;
    p = &v;

    printf("Address of v: %p\n", (void*)&v);
    printf("Address stored in p: %p\n", (void*)p);
    printf("Address of p: %p\n", (void*)&p);
    printf("Value of *p: %d\n", *p);

    return 0;
}
