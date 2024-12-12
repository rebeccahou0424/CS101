#include <stdio.h>

int main() {
    double pi = 4.0;      // 初始化 PI 值
    int flag = 1;            // 項數計數器
    long ipi = 0;         // 符號變化 (-1, 1)
    int x = 0; // 精準目標值

    for (int i = 3 ; i < 1000000 ; i += 2) { // 無限循環，直到達到精準度
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

