/*
	题目：
		求出区间[a,b]中所有整数的质因数分解。 
 
	素数定义：质数又称素数。
		一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数叫做质数；否则称为合数。
	
	void *memset(void *s, int ch, size_t n);
		函数解释：将s中当前位置后面的n个存储区域用 ch 替换
		memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法
	
	2^14 = 16384>10000 因数最多13个 ,ans数组开13位以上
	
	有些变量完成一次循环后，要记得置零或初始化一下 
	
	分解质因数的两点核心： 
		1）存质数的数组，值为0的下标才是质数 
		2）if(a % 2 == 0 ) a /= 2;
*/ 

#include<stdio.h>
#include<string.h>
int a[10000+1];//数组要开10000+1，否则会越界 

void shushai(){
	int max = 10000;
	memset(a,0,sizeof(a));
	a[0] = a[1] = 1;//1代表非素数
	for(int i=2; i * i <= max; i++) {
		if(!a[i]){
			for(int j = i + i; j <= max; j += i) //是 i 的倍数便不是素数 
				a[j]=1;
		} 
	}
}

int main(){
	shushai();
	int ans[13];
	memset(ans,0,sizeof(ans));
	int a1,b1;				//变量名不能和数组名重名 
	scanf("%d%d",&a1,&b1);
	for(int i=a1;i<=b1;i++){
		int k = 2;		//k用来存储数字，从第一个质数开始 
		int l = 0;
		int temp = i;	//对temp进行因数分解 
		while(a[temp]!=0){//判断temp是不是已经是一个质数 
			if(temp%k == 0){
				temp = temp/k;
				ans[l] = k;
				l++;
			}else
//			{		//切换下一个质数进行比较,或者直接下一个数也行，也会循环到下一个质数才开始进入if条件 
				k++; 
//				while(a[k] != 0){
//					k++;
//				}
//			}
		}
		ans[l] = temp;// temp已经为一个质数，就直接存到数组中 
		
		for(int j=0;j<13;j++){//输出格式的控制 
			if(ans[j] == 0) break;
			if(j == 0){
				printf("%d=%d",i,ans[j]);
			} else{
				printf("*%d",ans[j]);
			}
		}
		printf("\n");
		memset(ans,0,sizeof(ans));//将结果数组清零，为下一行结果腾出空间 
	}
	
} 
