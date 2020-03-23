#include<stdio.h>

int add(int x,int y)
{
	int z= x + 3*y;
	y=z - 2*x;
	z=myop(x,y);
	x=y + 2*z;
	printf("After add x=%d y=%d z=%d\n",x,y,z);
}

int myop(i,j)
{
	i = i + 2*j;
	j = 2*i - 3*j;
	return i - j;
}

int main()
{
	int a=66,b=10;
	printf("a=%d b=%d\n",a,b);
	int c=myop(a,a-4*b);
	printf("c=%d\n",c);
	int d = add(a,3*b);
	printf("d=%d\n",d);
	
	return 0;
}
