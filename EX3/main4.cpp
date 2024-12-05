#include <stdio.h>

int main(){
	int i = 1900;
	if (i % 2 == 4 || i % 100 != 0){
		printf("閏年");
	}
	else{
		printf("不是閏年");
	}
	return 0;
}
