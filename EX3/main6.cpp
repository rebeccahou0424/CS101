#include <stdio.h>

int main(){
	int i = 3000;
	if(i <= 1500){
		printf("70¤¸");
	}
	else{
		int n = i - 1500;
		if(n % 100){
			int h = ((n/100)+1) * 10;
			printf("%d¤¸", 70 + h);
		}
		else{
			printf("%d¤¸", 70 + (n/100)*10);
		}
	}
	return 0;
}
