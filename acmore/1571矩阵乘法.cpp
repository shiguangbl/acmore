/*
	题目：
	给定一个N阶矩阵A，输出A的M次幂（M是非负整数）
	例如：
	A =
		1 2
		3 4
	A的2次幂
		7 10
		15 22
	
	
	当矩阵的行数和列数相同时，矩阵也可称为方阵
	方阵的0次幂为单位矩阵 （主对角线1，其他为0）
	当用for变量循环无法控制时，对定义其它变量加以控制 
*/ 

#include<stdio.h>
int main(){
	int init[30+1][30+1];//初始化（输入）数组 
	int anstemp[30+1][30+1];//连乘过程中，临时数组 
	int ans[30+1][30+1];
	int aut[30+1][30+1]; 
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++){//输入矩阵 
		for(int j=0;j<n;j++)
			scanf("%lld",&init[i][j]);
	}
	
	for(int i=0;i<n;i++){//将输入的矩阵放入ans中一份 
		for(int j=0;j<n;j++)
			ans[i][j] = init[i][j];
	}
	
	//初始一个单位矩阵，当矩阵（方阵）的次幂为0的时候 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(i==j){
				aut[i][j] = 1;
			}else{
				aut[i][j] = 0;
			}
	}
	
	int temp = 0;
	int k = 0,l = 0;//k控制行，l控制列 
	for(int r=2;r<=m;r++){
		
		for(int i=0;i<n*n;i++){		
			for(int j=0;j<n;j++){
				temp += ans[k][j]*init[j][l];//第k行乘以第l列
			}
			anstemp[k][l] = temp;//将结果放到临时的数组中 
			temp = 0;
			l++;
			if(l == n){//当所有列都被当前k对应乘完时，k+1 
				k++;
				l = 0;
			}
		}
		k = 0;l = 0;
		for(int i=0;i<n;i++){// 将临时数组转入ans数组中，如果不引入临时数组，会影响下次相乘的结果 
			for(int j=0;j<n;j++)
				ans[i][j] = anstemp[i][j];
		}
	}
	
	if(m==0){		//次幂为0的时候，输出单位矩阵 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d",aut[i][j]);
				if(j!=n-1)		//保证每行最后一个输出后面不带空格 
					printf(" ");
			}
			printf("\n");
		}
	}
	else {	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d",ans[i][j]);
				if(j!=n-1)		
					printf(" ");
			}
			printf("\n");
		}	
	}
	
	return 0;
} 
