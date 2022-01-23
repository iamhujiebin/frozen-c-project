#include <stdio.h>
#include "my.h"

#define MAX(a,b) a>b?a:b
#define SQ(y) (y)*y

int main(){
	int n = 100;
	char c = '@';
	float money = 93.96;
	printf("n=%d,c=%c,money=%f\n",n,c,money);
	int sum2 = sum(1,2);
	printf("sum=%d\n",sum2);
	printf("max=%d\n",MAX(11,12));
	printf("sq=%d\n",SQ(n+1));
	printf("sq=%d\n",del(1000));
	printf("sq=%d\n",del2(1000));
	printf("sq=%d\n",del3(1000));
	return 0;
}
