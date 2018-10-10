#include<cstdio> 
/*
最小公倍数=两整数的乘积÷最大公约数

最小公倍数：指某几个整数共有的因子中最大的一个
*/

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int c = gcd(a,b);
	printf("最大公约数：%d\n",c);
	int d = a*b/c; 
	printf("最小公倍数：%d\n",d);
	return 0;
}
