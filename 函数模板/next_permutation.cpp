#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	double a[]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
	int count = 0;
//	while(next_permutation(a,a+9)){
//		if(a[0]+a[1]/a[2]+(a[3]*100+a[4]*10+a[5])/(a[6]*100+a[7]*10+a[8])==10){
//			count++;
//		}
//	}
	do{
		if(a[0]+a[1]/a[2]+(a[3]*100+a[4]*10+a[5])/(a[6]*100+a[7]*10+a[8])==10){
			count++;
		}
	}while(next_permutation(a,a+9));
	printf("%d",count);
	return 0;
} 
