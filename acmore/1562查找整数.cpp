#include<stdio.h>
/*
	题目：给出一个包含n个整数的数列，问整数a在数列中的第一次出现是第几个。

	相等跳出循环，否则置为-1
	注意：输出要换行 \n 
*/
int main(){
	int n;
	scanf("%d",&n);
	int a[1000+1]; 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int temp;
	int local;
	scanf("%d",&temp);
	for(int i=1;i<=n;i++){
		if(a[i]==temp){
			local = i;
			break;
		}
		local = -1; 
	}
	printf("%d\n",local);
	return 0;
}
