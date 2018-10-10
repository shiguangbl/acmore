#include<stdio.h>
#include<string.h>
#include<math.h>
/*
	scanf("%s",a)  gets(a)两个为字符输入，输入中间不能加空格（否则代表输入结束） 
	%lld 控制输出 long long类型的数据
	%ld  控制输出 long 类型的数据
	%lf  控制输出 double双精度浮点数
	%f   控制输出 float单精度浮点数 
	
	引入math.h 调用pow(m,n)函数
		用于计算m^n 
	
	注意换行\n 
*/
int main(){
	char a[8+1];
	int b[8+1]; 	//用于存放由字符转化为数字的数据 
	scanf("%s",a);
//	gets(a);
	for(int i=0;i<strlen(a);i++){//字符到数字的转化过程 
		if(a[i]>='0'&&a[i]<='9')
			b[i] = a[i]-'0';
		if(a[i]>='A'&&a[i]<='F')
			b[i] = a[i]-'A'+10;
	} 
	int j = 0;		//j用来控制指数 
	long long ans = 0;
	for(int i=strlen(a)-1;i>=0;i--){
		ans += b[i]*pow(16,j);
		j++;
	}
	printf("%lld\n",ans);
	return 0;
} 
