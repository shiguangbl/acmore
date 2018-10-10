/*
题目：给出n个数，找出这n个数的最大值，最小值，和。

#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	double a[10000+1];
	for(int i=0;i<n;i++){
		scanf("%lf",&a[i]);	
	}
	int max = 0;	//最大数 
	int min = 0;	//最小数 
	double sum = a[0]; 
	for(int i=1;i<n;i++){
		if(a[max]<a[i])
			max = i;
		if(a[min]>a[i])
			min = i;
		sum += a[i];
	}
	printf("%.f\n%.f\n%.f\n",a[max],a[min],sum);
	return 0;
} 
*/
/*
	考虑输入的数据是不是都是整数，上面数组定义为double
	注意：-2.6用 %.lf 输出为-3 
*/
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int  a[10000+1];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);	
	}
	int max = 0;	//最大数 
	int min = 0;	//最小数 
	int sum = a[0]; 
	for(int i=1;i<n;i++){
		if(a[max]<a[i])
			max = i;
		if(a[min]>a[i])
			min = i;
		sum += a[i];
	}
	printf("%d\n%d\n%d\n",a[max],a[min],sum);
	return 0;
} 
