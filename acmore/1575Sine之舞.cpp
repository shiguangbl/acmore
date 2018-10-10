/*
	题目：	An=sin(1–sin(2+sin(3–sin(4+...sin(n))...)
			Sn=(...(A1+n)A2+n-1)A3+...+2)An+1
			输出Sn
			
	思路：写出前几项找规律，拼串输出，Sn调An
	
	A1 = sin(1)
	A2 = sin(1-sin(2))
	A3 = sin(1-sin(2+sin(3)))
	
	S1 = A1+1
	S2 = (A1+2)A2+1
	S3 = ((A1+3)A2+2)A3+1
*/

#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

void An(int n){
	for(int i=1;i<=n-1;i++){
		printf("sin(%d",i);
		if(i%2){	//奇负偶正 
			printf("-");
		}else{
			printf("+");
		}
	}
	printf("sin(%d",n);
	for(int i=1;i<=n;i++){
		printf(")");
	}
} 

void Sn(int n){
	for(int i=1;i<=n-1;i++){
		printf("(");
	}
	for(int i=1;i<=n;i++){
		An(i);
		printf("+%d",n-i+1);
		if(i!=n){
			printf(")");
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
//	An(n);
//	printf("\n");
	Sn(n);
	printf("\n");
	return 0;
} 
