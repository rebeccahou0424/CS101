#include <stdio.h>

int main() {
    double pi = 4.0;      // ��l�� PI ��
    int flag = 1;            // ���ƭp�ƾ�
    long ipi = 0;         // �Ÿ��ܤ� (-1, 1)
    int x = 0; // ��ǥؼЭ�

    for (int i = 3 ; i < 1000000 ; i += 2) { // �L���`���A����F���ǫ�
        if(flag == 0){
		pi += (4.0/i);
		flag++;
		}              
		
		else{
			pi -= (4.0/i);
			flag--;
		}
		
		ipi = pi * 100000;
		if(ipi == 314159){
			x = i;
			break;
		}
    }
    printf("%d %.5f", x, pi);
    return 0;
}
