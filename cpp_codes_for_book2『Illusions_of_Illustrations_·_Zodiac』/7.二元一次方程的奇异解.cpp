#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int changehappens,joint;
void list(int *a1,int *a2)
{
	int max=*a1;
	changehappens=0;
	if(*a1<*a2)
	{
		*a1=*a2;
		*a2=max;
		max=*(a1+1);
		*(a1+1)=*(a2+1);
		*(a2+1)=max;
		changehappens=1;
	}
}
void maxjoint(int a1,int a2)
{
	int t;
	do
	{
		t=a1%a2;
		a1=a2;
		a2=t;
	}
	while(t!=0);
	joint=a1;
}
void main()
{
	int a[3][3],***x,i,j,*y=(int*)malloc(sizeof(int)),count,k,x1,x2,real1,real2,real1d,real2d,m1,m2,n1,n2,cishu=-1,t0;
	float t00;
	printf("请输入被测试的二元一次不定方程a1x+a2y=a3的三个系数,中间以逗号隔开,(不要输多了个逗号或其他符号)例如:'a1,a2,a3':");
	scanf("%d,%d,%d",a[0],a[1],a[2]);     /*举个例子:到这里:  3x-5y=-8  */
	alreadyreinputc:
	for(i=0;i<=2;i++)
	{
		if(a[i][0]<0)
		{
			a[i][1]=-a[i][0];
			a[i][2]=-1;
		}
		else 
		{
			a[i][1]=a[i][0];
			a[i][2]=1;
		}
	}                                     /*到这里:  3(1*x)+5(-1*y)=8(-1)  */
	list(a[0]+1,a[1]+1);                  /*这一行完毕后:  5(-1*y)+3(1*x)=8(-1)  */
	a[1][2]=-a[1][2];                     /*这一行完毕后:  5(-1*y)-3(-1*x)=8(-1)  */
	if(a[2][2]==-1)
	{
		a[2][2]=-a[2][2];
		a[0][2]=-a[0][2];
		a[1][2]=-a[1][2];
	}                                     /*到这里:  5(1*y)-3(1*x)=8(1)  */
	maxjoint(a[0][1],a[1][1]);
	if(a[2][1]%joint!=0)
	{
		printf("****************************************************************\n");
		printf("您输入的a3无法使该方程有整数解,请重新输入a3(不要输多了个逗号或其他符号):");
		goto reinputc;
	}
	cishu++;
	if(cishu>=1)                          /*如果程序已经至少运行过/经过了一次这个地方,则用realloc否则用malloc.*/
	{
		x=(int***)realloc(x,2*sizeof(int**));
		for(i=0;i<=1;i++)
			x[i]=(int**)realloc(x[i],(a[0][1]/joint+1)*sizeof(int*));
		for(i=0;i<=1;i++)
			for(j=0;j<=a[0][1]/joint;j++)
				x[i][j]=(int*)realloc(x[i][j],3*sizeof(int));
	}
	else
	{
		x=(int***)malloc(2*sizeof(int**));
		for(i=0;i<=1;i++)
			x[i]=(int**)malloc((a[0][1]/joint+1)*sizeof(int*));
		for(i=0;i<=1;i++)
			for(j=0;j<=a[0][1]/joint;j++)
				x[i][j]=(int*)malloc(3*sizeof(int));
	}
	for(i=1;i<=a[1][1]/joint;i++)         /*初始化*/
		for(j=(a[0][1]*(i-1)-a[0][1]*(i-1)%a[1][1])/a[1][1]+1;j<=(a[0][1]*i-a[0][1]*i%a[1][1])/a[1][1];j++)
		{
			x[0][j][0]=i;
			x[0][j][1]=j;
			x[0][j][2]=a[0][1]*i-a[1][1]*j;
		}
	x[0][0][0]=1;                         /*这里相当于i=1,j=0的情况,单独列出来.*/
	x[0][0][1]=0;
	x[0][0][2]=a[0][1];                   /*初始化完毕*/
	count=0;
	for(j=0;j<=a[0][1]/joint;j++)
		if(x[0][j][1]*2<a[0][1]/joint)    /*不选择限制x[0][j][0]而是限制另一个.;保留x[0][j][1]<a[0][1]/joint/2的.*/  /*这里要用<而不是<=.*/
		{
			x[1][j][0]=x[0][j][0];
			x[1][j][1]=x[0][j][1];
			x[1][j][2]=x[0][j][2];
			if(x[1][j][0]*2>a[1][1]/joint)/*标记这些不规则/不标准的小朋友,记录它们的下角标j.*/
			{
				y=(int*)realloc(y,++count*sizeof(int));
				y[count-1]=j;
			}
		}
		else
		{
			x[1][j][0]=x[0][j][0]-a[1][1]/joint;
			x[1][j][1]=x[0][j][1]-a[0][1]/joint;
			x[1][j][2]=x[0][j][2];
		}
	printf("\n(%d)x+(%d)y=%d (变换前的方程)\n",a[0][0],a[1][0],a[2][0]);    /*先打印一份我们的对照表*/
	if(changehappens)
		printf("%d(%d*y)-%d(%d*x)=%d (变换后的方程)\n\n",a[0][1],a[0][2],a[1][1],a[1][2],a[2][1]);
	else
		printf("%d(%d*x)-%d(%d*y)=%d (变换后的方程)\n\n",a[0][1],a[0][2],a[1][1],a[1][2],a[2][1]);
	if(count==0)
		for(j=0;j<=a[0][1]/joint;j++)
		{
			printf("%8d%8d%16d",x[0][j][0],x[0][j][1],x[0][j][2]);
			printf(" ------- ");
			printf("%8d%8d%16d\n",x[1][j][0],x[1][j][1],x[1][j][2]);
			if(x[1][j][2]==a[2][1]%a[0][1])
				k=j;
		}
	else
		for(j=0;j<=a[0][1]/joint;j++)
		{
			if(j>=y[0]&&j<=y[count-1])
			{
				printf("%8d%8d%16d",x[0][j][0],x[0][j][1],x[0][j][2]);
				printf(" ******* ");
				printf("%8d%8d%16d\n",x[1][j][0],x[1][j][1],x[1][j][2]);
			}
			else
			{
				printf("%8d%8d%16d",x[0][j][0],x[0][j][1],x[0][j][2]);
				printf(" ------- ");
				printf("%8d%8d%16d\n",x[1][j][0],x[1][j][1],x[1][j][2]);
			}
			if(x[1][j][2]==a[2][1]%a[0][1])
				k=j;
		}
	x1=(a[2][1]-a[2][1]%a[0][1])/a[0][1]+x[1][k][0];
	x2=x[1][k][1];
	if(abs(x1)*2>a[1][1]/joint)
	{
		printf("\n您所输入的a3使得方程的'等效最小整数解'(%d,%d)奇异,所以它现退步为了'两种等效最小整数解,的候选人'.\n\n",x1,x2);
		if(abs(x1)+abs(x2)>abs(x1-a[1][1]/joint)+abs(x2-a[0][1]/joint))
		{
			m1=x1-a[1][1]/joint;
			m2=x2-a[0][1]/joint;
		}
		else
		{
			m1=x1;
			m2=x2;
		}
		t00=(x1*a[1][1]/joint+x2*a[0][1]/joint)/(pow(a[1][1]/joint,2)+pow(a[0][1]/joint,2))-0.5;  /*t00是float型,这里不能将它赋值给整型的t0.*/
		if(t00<0)
			t00=0;
		t0=(int)t00+1-!(t00-(int)t00);   /*我在分母处加了pow运算的同时转换类型,以使得分母整个为float型.*/
		n1=x1-t0*a[1][1]/joint;
		n2=x2-t0*a[0][1]/joint;
		if(changehappens)
		{
			real1=m2/a[1][2];
			real2=m1/a[0][2];
			real1d=n2/a[1][2];
			real2d=n1/a[0][2];
		}
		else
		{
			real1=m1/a[0][2];
			real2=m2/a[1][2];
			real1d=n1/a[0][2];
			real2d=n2/a[1][2];
		}
		printf("方程在绝对值的平均数上的'等效最小整数解'为:(%d,%d),真正的最小整数解为(%d,%d),此时|%d|+|%d|最小.\n",m1,m2,real1,real2,real1,real2);
		printf("方程在离原点(0,0)的距离上的'等效最小整数解'为:(%d,%d),真正的最小整数解为(%d,%d),此时(%d)^2+(%d)^2最小.\n\n",n1,n2,real1d,real2d,real1d,real2d);
	}
	else
	{
		printf("\n您所输入的a3使得(%d,%d)成为了方程的'等效最小整数解',且它非奇异.\n\n",x1,x2);
		if(changehappens)
		{
			real1=x2/a[1][2];
			real2=x1/a[0][2];
		}
		else
		{
			real1=x1/a[0][2];
			real2=x2/a[1][2];
		}
		printf("并且方程的真正的最小整数解为:(%d,%d).\n不论从绝对值的平均数上还是离原点(0,0)的距离上,|%d|+|%d|和(%d)^2+(%d)^2均最小.\n\n",real1,real2,real1,real2,real1,real2);
	}
	printf("****************************************************************\n");
	printf("请再次输入需要测试的a3值(不要输多了个逗号或其他符号):");
	reinputc:
	scanf("%d",a[2]);
	goto alreadyreinputc;
}
