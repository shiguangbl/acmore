#include<stdio.h>
int main(){
	int n,m;
	int a[26];
	int temp = 'A';
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){		//根据m的大小，把数组0~m-1赋值为A-... 
		a[i] = temp;
		temp++;
	}
	for(int i=0;i<n;i++){//控制输出n行 也可以用while循环代替 
		for(int j=0;j<m;j++){		//输出当前行 
			printf("%c",a[j]);
		}
		printf("\n");
		//将数组中的数据全部向后移动一位，空出a[0]位置 
		for(int k=m-1;k>=0;k--){//要保证a[1]位置是a[0]移过去的，我的方法始终控制待移项的后一位，当k=1时进不去循环， 
//		for(int k=m-1;k>0;k--){	//而大朋方法始终控制待移项，即能进入循环 
			a[k+1] = a[k];
//			a[k] = a[k-1];
		}
		//填补a[0]位置 
		if(a[1]+1>'Z')		//防止acii码A-Z越界 
			a[0] = a[1]+1-26;
		else
			a[0] = a[1]+1;
	}
	return 0;
} 
