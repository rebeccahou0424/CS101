#include <stdio.h>

int main() {
    int i = 1; 
    while (i <= 81) { 
        int row = (i - 1) / 9 + 1; // �p���ơ]�ĴX�C�^
        int col = (i - 1) % 9 + 1; // �p��C�ơ]�ĴX��^

        printf("%d*%d=%2d ", row, col, row * col); // �L�X���k���G
        if (col == 9) { // ��F�C�檺�̫�@�C�ɴ���
            printf("\n");
        }

        i++; // �e�i��U�@�Ӧ�m
    }
    return 0;
}
