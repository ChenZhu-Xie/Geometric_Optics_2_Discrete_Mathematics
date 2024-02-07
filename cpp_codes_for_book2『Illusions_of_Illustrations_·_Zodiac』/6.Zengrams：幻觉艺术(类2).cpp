#include<stdio.h>
#include<math.h>
int getmin[2];
void minandAddress(int a,int b)
{
	getmin[0]=a;
	getmin[1]=0;
	if(b<getmin[0])
	{
		getmin[0]=b;
		getmin[1]=1;
	}
}
int maxjoint(int a,int b)
{
	int t,p[2];
	p[0]=a;
	p[1]=b;
	if(p[0]<p[1])
	{
		t=p[0];
		p[0]=p[1];
		p[1]=t;
	}
	do
	{
		t=p[0]%p[1];
		p[0]=p[1];
		p[1]=t;
	}
	while (t!=0);
	t=p[0];
	return t;
}
void main()
{
	int a[2],b[2],x[2][2]={{1,0},{0,-1}},value,x0,y0,joint,A,B,flag=1;
	printf("请像这样输入相对来说的,被移动的尺子的最小分度值a和被观察的尺子的最小分度值b,之间以逗号隔开'a,b':");
	scanf("%d,%d",a,b);
	A=a[0];
	B=b[0];
	joint=maxjoint(a[0],b[0]);
	minandAddress(a[0],b[0]);
	do
	{
		a[1]=a[0];
		b[1]=b[0];
		if(a[0]%getmin[0]!=0)
			a[0]=a[0]%getmin[0];
		if(b[0]%getmin[0]!=0)
			b[0]=b[0]%getmin[0];
		if(getmin[1]==0)
		{
			x[0][0]=x[0][0]+(b[1]-b[0])/getmin[0]*x[1][0];
			x[0][1]=x[0][1]+(b[1]-b[0])/getmin[0]*x[1][1];
		}
		else
		{
			x[1][0]=x[1][0]+(a[1]-a[0])/getmin[0]*x[0][0];
			x[1][1]=x[1][1]+(a[1]-a[0])/getmin[0]*x[0][1];
		}
		minandAddress(a[0],b[0]);
		if(getmin[0]==joint)
			break;
	}
	while(1);
	value=x[0][0]*x[1][1]-x[0][1]*x[1][0];
	if(getmin[1]==0)
	{
		y0=-x[1][0]/value;
		x0=x[1][1]/value;
	}
	else
	{
		y0=x[0][0]/value;
		x0=-x[0][1]/value;
	}
	if(y0<0)                                      /*这里不写≤是为了让当y0=0时,flag=1而不是0*/
		flag=-1;
	if(abs(y0)<=A/joint/2)
		printf("\nVmax=%d*V相\nVmin=%d*V相\n\n",(flag*A*B/joint-B*y0)/joint,-B*y0/joint);
	else
		printf("\n这个情况应该是不会出现的- -.\n\n");
}

/*  这是之前的结尾部分。

	if(abs(x0)<=B/joint/2)
		printf("\nVmax=%d*V相\nVmin=%d*V相\n\n",(flag*A*B/joint-B*y0)/joint,-B*y0/joint);
	else
	{
		printf("\n这个情况在不是a=b即%d=%d的时候,应该是不会出现的- -.\n",A,B);
		printf("\nVmax=%d*V相\nVmin=%d*V相\n\n",(flag*A*B/joint-B*y0)/joint,-B*y0/joint);
	}

*/

/*  这是现在的结尾部分。

	if(abs(y0)<=A/joint/2)
		printf("\nVmax=%d*V相\nVmin=%d*V相\n\n",(flag*A*B/joint-B*y0)/joint,-B*y0/joint);
	else
		printf("\n这个情况应该是不会出现的- -.\n\n");

*/
