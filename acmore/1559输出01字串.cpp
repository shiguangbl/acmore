#include<stdio.h>
/*
用数组对每组数据进行临时存放，正序存放，倒序输出，第九行的代码不能放到第11行的位置 
*/
int main(){
	int a[5];
	int n;
	for(int i=0;i<32;i++){
		n = i;
		for(int j=0;j<5;j++){
			a[j]= n%2;
			n = n/2;
		}
		for(int k=4;k>=0;k--){
			printf("%d",a[k]);
		} 
		printf("\n");
	}
	return 0;
} 
