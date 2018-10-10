/*
	题目： 
	输入1234567009时
	输出用汉语拼音表示： 
		shi er yi san qian si bai wu shi liu wan qi qian ling jiu


int 		9位数任用
long long	18位数任用 

*/

#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

void pinyin(int p,int &q){
	if(q == 1){
		printf(" ");
	}else{
		q = 1;
	}
	switch(p){
		case 0:printf("ling");
			break;
		case 1:printf("yi");
			break;
		case 2:printf("er");
			break;
		case 3:printf("san");
			break;
		case 4:printf("si");
			break;
		case 5:printf("wu");
			break;
		case 6:printf("liu");
			break;
		case 7:printf("qi");
			break;
		case 8:printf("ba");
			break;
		case 9:printf("jiu");
			break;
		case 10:printf("shi");
			break;	
		case 11:printf("bai");
			break;
		case 12:printf("qian");
			break;
		case 13:printf("wan");
			break;
		case 14:printf("yi");
			break;
	}
}

int main(){
	long long num,temp,ans;
	int k = 10000;	//用来取万位及万位以下的位数 
	int count = 1;
	int q = 0;	//用来控制输出结果的空格 
	int lastnum = 0;
	scanf("%lld",&num);
	if(num == 0){
		pinyin(0,q);
	}  
	while(num){		//num为零直接跳出循环 ，num为取余数 
		if(count==1){//控制取出亿位数字 
			temp = num;
			num = num%100000000;
			ans = temp/100000000;
		}
		else {	//控制取出万、千、百、十、个位数字 
			temp = num;
			num = num%k;
			ans = temp/k;
			k /= 10;
		}
		
		if(ans>=10&&count<3){//控制输出万位和亿位（大于10） 
			int temp2 = ans,a[5];
			int i=0;
			while(temp2){
				a[i] = temp2%10;
				temp2 = temp2/10;
				i++;
			}
			i--;//i多加了一位，要减一 
			while(i>0){//将各个位数进行输出 
				if(a[i]||a[i-1]){//保证两个及两个以上零，仅输出一个 
					if(i==1&&a[i]==1){//例：使12输出为si er 而不是 yi shi er ，及仅仅输出si 数字1不输出 
						pinyin(10,q);
					}else{			//数字，位都输出 
						pinyin(a[i],q);
						if(a[i])
							pinyin(i+9,q);
					}
				}
				i--;
			}
			if(a[i])//将最后一位（个位）输出 
				pinyin(a[i],q);
			if(count == 1)
				pinyin(14,q);
			else
				pinyin(13,q);
		
		}else if(lastnum||ans){//控制输出万位和亿位（小于10）以及千、百、十、个位数字 
			if(ans==1&&count==5){
				pinyin(10,q);
			}else{				//趟数count 唯一对应 位数 1--亿位  
				pinyin(ans,q);
				if(count==1&&ans)
					pinyin(14,q);
				if(count==2&&ans)
					pinyin(13,q);
				if(count==3&&ans)
					pinyin(12,q);
				if(count==4&&ans)
					pinyin(11,q);
				if(count==5&&ans)
					pinyin(10,q);
				}
		}
		lastnum = ans;//记录上一个数，用来检测，连续出现两个及以上个零时，仅输出一个 
		count++;
	}
	printf("\n");
	return 0;
}
