#include<stdio.h>
/*
	记住闰年的判断方式 
*/
int main(){
	int year;
	scanf("%d",&year);
	if((year%4==0)&&(year%100!=0)){
		printf("yes\n"); 
	} else if(year%400==0){
		printf("yes\n");
	}else{
		printf("no\n");
	}
	return 0;
}
