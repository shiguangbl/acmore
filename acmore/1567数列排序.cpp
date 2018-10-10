/*
	sort(,)的使用，第一个参数数组起始位置（数组名）
		第二个参数为尾指针的下一个位置（数组名+待排元素的个数） 
	加两个头
		 #include <algorithm>
		 using namespace std;
*/

#include<stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int a[200+1];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n); 
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
} 
