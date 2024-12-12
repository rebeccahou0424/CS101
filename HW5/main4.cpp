#include <stdio.h>

int swapThousandsAndOnes(int num) {
    // �p�G�Ʀr�p�󵥩�0�A������^
    if (num <= 0) {
        return num;
    }

    // �����U��Ʀr
    int tenThousands = num / 10000;

    // �����d��Ʀr
    int thousands = (num / 1000) % 10;

    // �����Ӧ�Ʀr
    int ones = num % 10;

    // �����ʦ�M�Q��Ʀr
    int hundreds = (num / 100) % 10;
    int tens = (num / 10) % 10;

    // ���s�զX�Ʀr
    int result = tenThousands * 10000 + ones * 1000 + tens * 100 + hundreds * 10 + thousands;

    return result;
}

int main() {
    int testCases[] = {12345, 123, 12, 1};
    int numCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int j = 0; j < numCases; j++) {
        int originalNum = testCases[j];
        int swappedNum = swapThousandsAndOnes(originalNum);
        
        printf("��l�Ʀr: %d\n", originalNum);
        printf("�մ���Ʀr: %d\n\n", swappedNum);
    }

    return 0;
}