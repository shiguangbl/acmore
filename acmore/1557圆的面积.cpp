#include<stdio.h>
#include<math.h>
#define pi acos(-1.0)
/*
	π的精度问题
	问题：单精度用%f,双精度用%lf,格式控制符不对，也会运行不通过 
*/
int main(){
	int r;
	scanf("%d",&r);
	printf("%.7lf",pi*r*r);
	return 0;
} 
