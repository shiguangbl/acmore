/*
	题目：1221是一个非常特殊的数，它从左边读和从右边读是一样的，
			编程求所有这样的四位十进制数。 
	
	取位数：得出余数，除10
		整数除10可以卡掉个位数 
	用数组存取位数
*/

#include<stdio.h>
int main(){
	int a[4+1];
	int n = 0;
	for(int i=1001;i<10000;i++){
		int j = i;
		while(j){
			a[n] = j%10;
			j = j/10;
			n++;
		}
		n = 0;
		if(a[0] == a[3]&&a[1] == a[2]){
			for(int i=0;i<4;i++)
				printf("%d",a[i]);
			printf("\n");
		}
	}
	return 0;
} 
