
struct node {
	int num;
	char name[5];
} a[100];


bool cmp(node x,node y){
	if(x.num != y.num) return x.num>y.num;
	else return strcmp(x.name, y.name) < 0;
}

sort(a,a+100,cmp); 
