#include <stdio.h>
#include <math.h> // �ϥ� fabs() �p�⵴���

int main() {
    double pi = 0.0;      // ��l�� PI ��
    int x = 1;            // ���ƭp�ƾ�
    int sign = 1;         // �Ÿ��ܤ� (-1, 1)
    double target = 3.14159; // ��ǥؼЭ�
    double precision = 0.000005; // ��ǫ׽d��]�p�� 0.000005�^

    for (x = 0; ; x++) { // �L���`���A����F���ǫ�
        double term = 4.0 / (2 * x + 1); // �p����e��
        pi += sign * term;               // �ھڲŸ��֥[����
        sign = -sign;                    // �Ÿ�����

        // �P�_�p��X�� PI �O�_��Ǩ�ؼЭ�
        if (fabs(pi - target) < precision) {
            break; // �p�G�F���ǫסA���X�j��
        }
    }

    printf("�p��X�� PI �Ȭ��G%.5f\n", pi);
    printf("�һݪ��̤p���� x ���G%d\n", x + 1);

    return 0;
}
