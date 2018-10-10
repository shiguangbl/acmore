/*
int 		9位数任用
long long	18位数任用 

*/

#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	long long num,temp,temp2;
	int k = 10000;
	int count = 1;
	scanf("%lld",&num);
	while(count <=6){
		if(count == 1){
			temp2 = num;//暂存num 
			num = num%100000000;
			temp = temp2/100000000;//截取暂存的num的高位，存到temp，用于输出 
		}
		else {		//截取万位及千位、百位、十位、个位 
			temp2 = num; 
			num = num%k;
			temp = temp2/k;
			k /= 10;
		}
		printf("%lld ",temp);//输出本次循环截取的位数 
		count++;
	}
	
	return 0;
}
