/*
	二进制B
	八进制O
	十进制D 
	十六进制H
	
	定义大数组要放在main函数外边 
	
	其他内容如下 
*/
#include<stdio.h>
#include<string.h>

char h[100000+1]; 		//十六进制数组 
int h2[100000+1];		//十六进制转化为数字后的数组 
int o[300000+3];		//八进制数组 
int b[400000+4];		//二进制数组 
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",h);
		for(int i=0;i<strlen(h);i++){//字符到数字的转化过程 
			if(h[i]>='0'&&h[i]<='9')
				h2[i] = h[i]-'0';
			if(h[i]>='A'&&h[i]<='F')
				h2[i] = h[i]-'A'+10;
		}
		int j = 0;		//控制并记录b数组的长度 
		int m;			//用于临时存放当前h2数组的值 
		int temp; 		//用于颠倒顺序 

		for(int i=0;i<strlen(h);i++){//把十六进制转化为二进制 
			m = h2[i];
			for(int k=0;k<4;k++){//37初始转换到b数组时为1100 1110
				b[j] = m%2;
				m = m/2;
				j+=1;
			}	
			
			temp = b[j-1];
			b[j-1] = b[j-4];
			b[j-4] = temp;
			
			temp = b[j-2];
			b[j-2] = b[j-3];//   颠倒后为正序0011 0111 
			b[j-3] = temp;
		}
		
		int k = 0;			//控制并记录o数组的长度
		while(j>2){			//将二进制转化为八进制 
			o[k] = b[j-1]+b[j-2]*2+b[j-3]*4;
			k++;
			j-=3;
		}
							//高位剩余位数不足三位，相当于进行补零处理 
		if(j==2)
			o[k] = b[1]+b[0]*2;
		if(j==1)
			o[k] = b[0];
			
		int flag = 0;
		for(int p=k;p>=0;p--){		//过滤八进制的高位0
			if(o[p]==0&&flag == 0); //例如071 输出就是71，也就是从第一个不为零的数字开始输出 
			
			else{
				printf("%d",o[p]);
				flag = 1;	
			}
		}
		printf("\n");
	}
	return 0;
} 
