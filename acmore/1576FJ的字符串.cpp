/*
	题目：FJ在沙盘上写了这样一些字符串：
			A1 = “A”
			A2 = “ABA”
			A3 = “ABACABA”
			A4 = “ABACABADABACABA” 
	方法一：使用数组进行存
	方法二：利用二叉树的结构进行中序遍历 
*/ 

#include<cstdio>
#include<cstring> 
#include<cmath>
#include<algorithm>
using namespace std;
char a[100000000+1];
int main(){
	int n;
	scanf("%d",&n);
	a[0] = '0';//给a[0]进行一个初始化，否则strlen()测出的结果不准确 
	a[1] = 'A';
	
	for(int i='B';i<='B'+n-2;i++){
		a[strlen(a)] = i;	
		int k = strlen(a);
		for(int j=strlen(a)-2;j>0;j--){//将数组后一半存上前半段的倒序 
			a[k] = a[j];
			k++;
		}
	}
	for(int i=1;i<strlen(a);i++){
		printf("%c",a[i]);
	}
	printf("\n");
	return 0;
} 
/*
//利用二叉树的中序遍历 
void Print(int n){  
    if(n==1){  
        printf("A");  
        return ;  
    }  
    else {  
        Print(n-1);  
        printf("%c",'A'+n-1);  
        Print(n-1);  
    }  
}  
int main(){  
    int n; scanf("%d",&n);  
    Print(n);  
}  */
