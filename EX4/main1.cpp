#include <stdio.h>

int main() {
    int n = 7;
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n + i - 1; j++) { 
            if (j <= n - i) {
                printf(" "); // �L�Ů�
            } else if ((j - (n - i)) % 2 == 1) { 
                printf("%d", i); // �L�Ʀr
            } else {
                printf(" "); // �L�Ʀr�������Ů�
            }
        }
        printf("\n");
    }
    return 0;
}
