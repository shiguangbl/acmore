/*
题目： 1：两个字符串长度不等。比如 Beijing 和 Hebei
		2：两个字符串不仅长度相等，而且相应位置上的字符完全一致(区分大小写)
		3：两个字符串长度相等，相应位置上的字符仅在不区分大小写的前提下才能达到完全一致
		4：两个字符串长度相等，但是即使是不区分大小写也不能使这两个字符串一致。
		判断两字符串关系并输出所属的类的编号
注意：换行\n 
*/

#include<stdio.h>
#include<string.h> 
int main(){
	char a[1000];
	char b[1000];
	scanf("%s",a);
	scanf("%s",b);
	int ans;
	if(strlen(a)==strlen(b)){	//如果一开始长度就不等，直接1 
		int i;
		for(i=0;i<strlen(a);i++){		
			if((a[i] != b[i])&&(a[i]-32 !=b[i])&&(a[i]+32 != b[i]))//如果发现两个字符不区分大小写还不相等，直接跳出循环，此时i<strlen(a) 
				break;
			if((a[i]-32 ==b[i])||(a[i]+32 == b[i])){	//如果发现有不区分大小写才相等的字符，将ans = 3 
				ans = 3;
			}
		}
		if(i == strlen(a)){//两字符串完全比较完毕 
			if(ans != 3)	//如果过程中没有被赋值为3，就赋值为2 
				ans = 2;
		}else {
			ans = 4;		//未比较完，即中间出现完全不相等的字符 
		}
	}
	else{
	
		ans = 1;
	}
	printf("%d\n",ans);
	 
	return 0;
} 
