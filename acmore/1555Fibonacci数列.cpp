#include<stdio.h>
/*
同余定理 (+-*)
https://wenku.baidu.com/view/db07b26ed1f34693dbef3ea8.html
(a%c+b%c)%c = (a+b)%c
(a%c+b)%c = (a+b)%c
同余定理在计算的过程中什么时候都能进行取余 
*/ 
int main(){
	int f1,f2,temp;
	int i;
	int n,num;
	while(~scanf("%d",&n)){
		f1 = 1;
		f2 = 1;
		for(i=2;i<=n;i++){
			if(i%2 != 0){
				f1 = f1+f2;
				f1 = f1%10007;	//每得出一项就对10007取余
			}
			else{
				f2 = f2+f1;
				f2 = f2%10007;
			}
		}
		if(i%2 != 0)
			printf("%d\n",f1);
		else
			printf("%d\n",f2);
	}
	
}
