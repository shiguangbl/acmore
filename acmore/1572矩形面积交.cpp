/*
	题目：平面上有两个矩形，它们的边平行于直角坐标系的X轴或Y轴。对于每个矩形，
	我们给出它的一对相对顶点的坐标，请你编程算出两个矩形的交的面积。 
	
	求矩形相交面积 
	（两个矩形的左下顶点横坐标）的较大的那个m1，两个矩形的左下顶点纵坐标）的较大的那个n1
	（两个矩形的右上顶点横坐标）的较小的那个m2，两个矩形的左下顶点纵坐标）的较小的那个n2
	 如果（m2,n2）在（m1,n1）右上，说明存在相交面积 
	 根据坐标算出面积即可 
*/

#include<stdio.h>
double max(double a,double b){
	return a>b?a:b;
}
double min(double a,double b){
	return a<b?a:b;
}
int main(){
	double x1,y1,x2,y2,x3,y3,x4,y4;
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	scanf("%lf%lf%lf%lf",&x3,&y3,&x4,&y4);
	double m1 = max(min(x1,x2),min(x3,x4));
	double n1 = max(min(y1,y2),min(y3,y4));
	double m2 = min(max(x1,x2),max(x3,x4));
	double n2 = min(max(y1,y2),max(y3,y4));
	if(m2>m1&&n2>n1){
		printf("%.2lf\n",(m2-m1)*(n2-n1));
	} 
	else{
		printf("0.00\n");
	}
	return 0;
} 
