#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int getmin[2],b[2],m[2],z[2],changehappens;                  /*创造一个有两元素的一维全局数组变量getmin[2]*/
void list(int *a1,int *a2)
{
	int min=*a1;
	changehappens=0;
	if(*a1>*a2)
	{
		*a1=*a2;
		*a2=min;
		min=*(a1+1);
		*(a1+1)=*(a2+1);
		*(a2+1)=min;
		changehappens=1;
	}
}
void minandAddress(int p2,int p22,int addressp2)
{
	getmin[0]=p2;
	getmin[1]=addressp2;
	if(p22<getmin[0])
	{
		getmin[0]=p22;
		getmin[1]=addressp2-2;
	}
}
int maxjoint(int p2,int p22)                                /*创造函数maxjoint调取一对值,返回它们的最大公因数值*/
{
	int t,p[2];
	p[0]=p2;
	p[1]=p22;
	if(p[0]<p[1])                                           /*调换数据的大小顺序以便之后的辗转相除*/
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
	while (t!=0);                                           /*跳出循环后p[0]就是*p2和*pp2的最大公因*/
	t=p[0];
	return t;
}
void get(int n,int leftovers)
{
	if(leftovers==0)
	{
	}
	else if(n==1)                                           /*这个东西逻辑上最好在leftovers==0的后面,但事实上我们的算法允许它们交换位置.因为可能当n==2的时候,进入该函数的else里后,发现x[1]取j的最大值时,余数leftovers-m[1]*j==0,这样会出现进入下一层函数get(1,0),此时我们希望的是先判断leftovers是否等于0,因为已经找到一个合理解了.而如果此时先判断n==1,由于leftovers==0,所以条件leftovers%m[0]==0恒为真,使得x[0]=leftovers/m[0];语句达到和for(i=0;i<n;i++) x[i]=0;语句相同的初始化x[0]为0的效果,并且其他之后剩下的语句均一样.这样以另一个判断标准判断其为有效非负整数解组,让人感到有点odd,奇怪.但从逻辑上似乎也说得通,所以在我们的算法上是行得通的.*/
	{
		if(leftovers%m[0]==0)
		{
			b[z[0]]=leftovers/m[0];
		}
		else
			;                                               /*这里将不会有此else情况出现:不会除不尽.*/
	}
	else if(m[n-1]>leftovers)                         
		get(n-1,leftovers);                                 /*这个要写在n==1的后面,即得先判断是否n减来==1.所以上次的只是特殊系数的特殊算法.因为如果出现了当n==1的时候m[0]>leftovers(不知道你输入的各项系数中的最小值m[0]是多少,而leftovers有可能=1,所以有可能当n==1的时候却进入了m[0]>leftovers的流程),则会进入下一层函数,出现m[-1],访问的空间将不在范围内.此时理应进入n==1的判断的.|而上一个之所以可行是因为m[0]恒=1,而leftovers不会小于1(余数难道有小余1的?),所以会直接不满足m[0]>leftovers,然后进入n==1的流程.*/
	else
	{
		b[z[n-1]]=(leftovers-leftovers%m[n-1])/m[n-1];
		get(n-1,leftovers%m[n-1]);
	}
}
/*************************************************/
int main()
{
	char *p1=(char*)malloc(1);
	int *p2=(int*)malloc(sizeof(int)),**p3,*p22,**p33,pp2[2],s,count1=0,count2=0,i,sum,k,value2copy,**x,**y,*p222,*pp22,flag=1,t,a[3][2],c[2][2],x1,x2,xi1,xi2;
	printf("请像这样(请不要输入0和非整数)输入多元一次不定方程\na1x1+a2x2+...+anxn=b 的系数 'a1,a2,a3,a4,...b,' 后，按enter键:\n\n");
	s=getchar();                                            /*创造一个scanf函数用于实现我的功能,刚开始就需要值进来,所以不用dowhile*/
	while(s!='\n')
	{
		if(s<=57&&s>=48)
		{
			count1++;                                       /*统计输入了多少个"假·数字"进来*/
			*(p1+count1-1)=s;                               /*将s的值放入距离p1共(count1-1)的地址对应的内容里,即放入上一步所创建的多出来的那个空间中*/
			p1=(char*)realloc(p1,count1+1);                 /*将p1的空间扩张至(假·数字个数+1)个字节,预备下一次输入。这条语句会"初始化"p1的值*/
		}
		else if(s=='-')
			flag=-1;
		else if(s==',')
		{
			sum=0;                                          /****************************************************初始化sum值,为了下面的循环*/
			for(i=0;i<=count1-1;i++)
				sum=sum+(*(p1+i)-'0')*(int)pow(10,count1-1-i);
			if(flag==-1)
			{
				sum=-sum;
				flag=1;
			}
			count1=0;p1=(char*)realloc(p1,1);               /****************************************************初始化count1值和p1拥有的地址量,均是为了下一次循环的第一个if*/
			count2++;                                       /*统计输入了多少个"真·数字"进来*/
			*(p2+count2-1)=sum;                             /*将sum的值放入距离p2共(count2-1)的地址对应的内容里*/
			p2=(int*)realloc(p2,(count2+1)*sizeof(int));    /*将p2的空间扩张至(真·数字个数+1)个整数空间,预备下一次输入。最后它会像p1一样总会空出一个空间,不过不影响我们的继续,所以循环外不用改小一格它*/
		}
		s=getchar();
	}
	printf("\n");
	if(count2-1<2)
	{
		printf("\n********你输入得太少了!有解无解和解是多少都能自己算的出来了!********\n\n!");
		return 0;
	}
	p3=(int**)malloc((count2-1)*sizeof(int*));              /*从a0到an-1的非系数部分:x0到xn-1*/
	for(i=0;i<count2-1;i++)
		p3[i]=(int*)malloc(2*sizeof(int));                  /*现在每个子地址只开辟两个空间了,每对新创造的最小公倍数和右系数只构成一个二元一次不定式,两个系数,两个非系数部分.这里只给x所在的非系数部分分配空间.*/
	pp22=(int*)malloc((count2-1)*sizeof(int));              /*创造pp22来复制p2,保留它们的原始值,以后有用。并且要在它们的负号消失之前及时得到最原始的信息.不能丢失此负号信息.*/
	for(i=0;i<=count2-1-1;i++)
		pp22[i]=p2[i];
/*************************************************/
	for(i=0;i<=1;i++)                                       /*先初始化a0和a1的系数部分和非系数部分,这里可以沿用之前的语法,之后就不行了*/
	{
		for(k=0;k<=1;k++)
			if(k==i)
				if(p2[i]>0)
					p3[i][k]=1;
				else p3[i][k]=-1;
			else p3[i][k]=0;
		p2[i]=abs(p2[i]);
	}
/*************************************************/
	if(count2-1>2)
	{
		p22=(int*)malloc((count2-1-2)*sizeof(int));         /*从b0到bn-3的系数部分,这是模仿p2创造的,但是p2还包含有b以及一个空空间.*/
		p33=(int**)malloc((count2-1-2)*sizeof(int*));       /*从b0到bn-3的非系数部分:y0到yn-3*/
		for(i=0;i<count2-1-2;i++)
			p33[i]=(int*)malloc(2*sizeof(int));             /*其子地址也只开辟两个空间*/
	}
	else                                                    /*城乡结合部:综合最初(k=n-3)与最末(k=-1)二阶式子的语句,具体而微的程序雏形.*/
	{
		if(p2[count2-1]%maxjoint(p2[0],p2[1])!=0)
		{
			printf("您输入的多元一次不定方程无整数解。\n\n");
			free(pp22);
			pp22=NULL;
			for(i=0;i<count2-1;i++)
			{
				free(p3[i]);
				p3[i]=NULL;
			}
			free(p3);
			p3=NULL;
			free(p2);
			p2=NULL;
			free(p1);
			p1=NULL;
			return 0;
		}
		x=(int**)malloc((count2-1)*sizeof(int*));
		sum=1;
		minandAddress(p2[1],p2[0],1);
		do
		{
			pp2[0]=p2[0];                                   /*保留值*/ 
			pp2[1]=p2[1];
			if(p2[0]%getmin[0]!=0)
				p2[0]=p2[0]%getmin[0];
			if(p2[1]%getmin[0]!=0)
				p2[1]=p2[1]%getmin[0];
			if(getmin[1]==1-2)
			{
				p3[0][0]=p3[0][0]+(pp2[1]-p2[1])/getmin[0]*p3[1][0];
				p3[0][1]=p3[0][1]+(pp2[1]-p2[1])/getmin[0]*p3[1][1];
			}
			else 
			{
				p3[1][0]=p3[1][0]+(pp2[0]-p2[0])/getmin[0]*p3[0][0];
				p3[1][1]=p3[1][1]+(pp2[0]-p2[0])/getmin[0]*p3[0][1];
			}
			minandAddress(p2[1],p2[0],1);
			if(getmin[0]==maxjoint(p2[1],p2[0]))
				sum=0;
		}
		while(sum);
		value2copy=p3[0][0]*p3[1][1]-p3[0][1]*p3[1][0];
		x[1]=(int*)malloc((count2-1)*sizeof(int));
		x[0]=(int*)malloc((count2-1)*sizeof(int));
		if(pp22[0]<0)                                       /*insert 第二部分首*/
		{
			a[0][0]=-pp22[0];
			a[0][1]=-1;
		}
		else
		{
			a[0][0]=pp22[0];
			a[0][1]=1;
		}
		if(pp22[1]<0)
		{
			a[1][0]=-pp22[1];
			a[1][1]=-1;
		}
		else
		{
			a[1][0]=pp22[1];
			a[1][1]=1;
		}
		list(a[0],a[1]);
		a[1][1]=-a[1][1];
		for(i=0;i<2;i++)
			c[i][1]=a[i][1];                                /*insert 第二部分,部分尾:保留原非系数部分的符号.*/
		if(pp22[0]*pp22[1]>0)                               /*这里才是真迹:如果系数异号,则规定它们的最大公因数为负值.*/
			flag=maxjoint(p2[1],p2[0]);
		else
			flag=-maxjoint(p2[1],p2[0]);
		x[1][count2-2]=pp22[0]/flag;
		x[0][count2-2]=-pp22[1]/flag;
		for(i=0;i<2;i++)                                    /*新的替代品__始端*/
			b[i]=0;
		for(i=0;i<2;i++)
			m[i]=p2[i];
		for(i=0;i<2;i++)
			z[i]=i;
		if(m[0]>m[1])
		{
			t=m[0];
			m[0]=m[1];
			m[1]=t;
			t=z[0];											/*当值交换时,下角标也跟着交换.*/
			z[0]=z[1];
			z[1]=t;
		}
		if(p2[count2-1]<0)
		{
			get(2,-p2[count2-1]);
			for(i=0;i<2;i++)
				b[i]=-b[i];
		}
		else
			get(2,p2[count2-1]);
		for(i=count2-3;i>=0;i--)
		{
			x[1][i]=(p3[0][0]*b[1]-b[0]*p3[1][0])/value2copy;
			x[0][i]=(b[0]*p3[1][1]-p3[0][1]*b[1])/value2copy;
			if(p2[count2-1]<0)                              /*insert 第二部分,部分首.*/
			{
				a[2][0]=-p2[count2-1];
				a[2][1]=-1;
			}
			else
			{
				a[2][0]=p2[count2-1];
				a[2][1]=1;
			}
			if(a[2][1]==-1)
			{
				a[2][1]=-a[2][1];
				a[0][1]=-a[0][1];
				a[1][1]=-a[1][1];
			}
/*	if(changehappens)
		printf("%d(%d*y)-%d(%d*x)=%d (变换后的方程)\n\n",a[0][0],a[0][1],a[1][0],a[1][1],a[2][0]);
	else
		printf("%d(%d*x)-%d(%d*y)=%d (变换后的方程)\n\n",a[0][0],a[0][1],a[1][0],a[1][1],a[2][0]);  */
			if(changehappens)
			{
				x1=x[1][i]*a[0][1];
				x2=x[0][i]*a[1][1];
			}
			else
			{
				x1=x[0][i]*a[0][1];
				x2=x[1][i]*a[1][1];
			}
			if(x1*2<=-a[1][0]/getmin[0])                        /*新的判断标准和对应的执行标准*/
			{
				xi1=a[1][0]/getmin[0]/2-(-x1+a[1][0]/getmin[0]/2)%(a[1][0]/getmin[0]);    /*本身是-xi1=(-x1+a[1][0]/getmin[0]/2)%(a[1][0]/getmin[0])-a[1][0]/getmin[0]/2*/
				xi2=x2+a[0][0]/getmin[0]*((-x1+a[1][0]/getmin[0]/2)-(-x1+a[1][0]/getmin[0]/2)%(a[1][0]/getmin[0]))/(a[1][0]/getmin[0]);
			}
			else
			{
				xi1=(x1+a[1][0]/getmin[0]/2)%(a[1][0]/getmin[0])-a[1][0]/getmin[0]/2;
				xi2=x2-a[0][0]/getmin[0]*((x1+a[1][0]/getmin[0]/2)-(x1+a[1][0]/getmin[0]/2)%(a[1][0]/getmin[0]))/(a[1][0]/getmin[0]);
				if(xi1*2==-a[1][0]/getmin[0])
				{
					xi1=xi1+a[1][0]/getmin[0];
					xi2=xi2+a[0][0]/getmin[0];
				}
			}
/*	printf("方程的等效随机解为(%d,%d),方程的等效下奇异解为(%d,%d),等价于反方程的上奇异解(%d,%d).\n\n",x1,x2,xi1,xi2,-xi2,-xi1);  */
			if(abs(xi1)+abs(xi2)>abs(xi1+a[1][0]/getmin[0])+abs(xi2+a[0][0]/getmin[0]))
			{
				xi1=xi1+a[1][0]/getmin[0];
				xi2=xi2+a[0][0]/getmin[0];
			}
			if(changehappens)
			{
				x[0][i]=xi2/a[1][1];
				x[1][i]=xi1/a[0][1];
			}
			else
			{
				x[0][i]=xi1/a[0][1];
				x[1][i]=xi2/a[1][1];
			}
			for(t=0;t<2;t++)
				a[t][1]=c[t][1];                            /*insert 第二部分,部分尾:还原a[0][1]和a[1][1].*/
		}                                                   /*新的替代品__末端*/
		printf("x%d=",1);
		for(i=count2-2;i>=1;i--)
			printf("%dt%d+",x[0][i],i);
		printf("%d",x[0][0]);
		printf("\n");
		for(k=1;k<=count2-2;k++)
		{
			printf("x%d=",k+1);
			for(i=count2-1-k;i>=1;i--)
				printf("%dt%d+",x[k][i],i);
			printf("%d",x[k][0]);
			printf("\n");
		}
		printf("\n");
		free(x[0]);
		x[0]=NULL;
		free(x[1]);
		x[1]=NULL;
		free(x);
		x=NULL;
		free(pp22);
		pp22=NULL;
		for(i=0;i<count2-1;i++)
		{
			free(p3[i]);
			p3[i]=NULL;
		}
		free(p3);
		p3=NULL;
		free(p2);
		p2=NULL;
		free(p1);
		p1=NULL;
		return 0;
	}
/*************************************************/
	p22[0]=maxjoint(p2[0],p2[1]);                           /*没办法,任何设计都有局限,这里多出了一些周期之外的东西,加上上面的,有两部分周期之外的,这里除了这第一句话,相当于下面循环中k=0的时候的.*/
	p33[0][0]=1;
	p33[0][1]=0;
	p3[2][0]=0;
	if(p2[2]>0)
		p3[2][1]=1;
	else p3[2][1]=-1;
	p2[2]=abs(p2[2]);
/*************************************************/
	for(k=1;k<=count2-1-3;k++)
	{
		p22[k]=maxjoint(p2[k+1],p22[k-1]);
		p33[k][0]=1;                                        /*p22[k]由于是上一对系数的最大公因数,恒>0,所以直接p33[k][0]=1,剩下的=0,以及不用取系数的绝对值了*/
		p33[k][1]=0;
		p3[k+2][0]=0;
		if(p2[k+2]>0)
			p3[k+2][1]=1;
		else p3[k+2][1]=-1;
		p2[k+2]=abs(p2[k+2]);
	}
/*************************************************/
	if(p2[count2-1]%maxjoint(p2[count2-2],p22[count2-4])!=0)
	{
		printf("您输入的多元一次不定方程无整数解。\n");
		for(i=0;i<count2-1-2;i++)
		{
			free(p33[i]);
			p33[i]=NULL;
		}
		free(p33);
		p33=NULL;
		free(p22);
		p22=NULL;
		free(pp22);
		pp22=NULL;
		for(i=0;i<count2-1;i++)
		{
			free(p3[i]);
			p3[i]=NULL;
		}
		free(p3);
		p3=NULL;
		free(p2);
		p2=NULL;
		free(p1);
		p1=NULL;
		return 0;
	}
	x=(int**)malloc((count2-1)*sizeof(int*));
	y=(int**)malloc((count2-1-2)*sizeof(int*));
	p222=(int*)malloc((count2-1-2)*sizeof(int));            /*创造p222来复制p22,保留它们的原始值,以后有用,注:由于p22全是正的,所以p222也全是正的.*/
	for(i=0;i<=count2-1-3;i++)
		p222[i]=p22[i];
/*************************************************/         /*相当于k=n-3*/
	sum=1;
	minandAddress(p2[count2-1-3+2],p22[count2-1-3],count2-1-3+2);
	do
	{
		pp2[0]=p22[count2-1-3];                             /*保留值*/ 
		pp2[1]=p2[count2-1-3+2];
		if(p22[count2-1-3]%getmin[0]!=0)
			p22[count2-1-3]=p22[count2-1-3]%getmin[0];
		if(p2[count2-1-3+2]%getmin[0]!=0)
			p2[count2-1-3+2]=p2[count2-1-3+2]%getmin[0];
		if(getmin[1]==count2-1-3)
		{
			p33[count2-1-3][0]=p33[count2-1-3][0]+(pp2[1]-p2[count2-1-3+2])/getmin[0]*p3[count2-1-3+2][0];
			p33[count2-1-3][1]=p33[count2-1-3][1]+(pp2[1]-p2[count2-1-3+2])/getmin[0]*p3[count2-1-3+2][1];
		}
		else 
		{
			p3[count2-1-3+2][0]=p3[count2-1-3+2][0]+(pp2[0]-p22[count2-1-3])/getmin[0]*p33[count2-1-3][0];
			p3[count2-1-3+2][1]=p3[count2-1-3+2][1]+(pp2[0]-p22[count2-1-3])/getmin[0]*p33[count2-1-3][1];
		}
		minandAddress(p2[count2-1-3+2],p22[count2-1-3],count2-1-3+2);
		if(getmin[0]==maxjoint(p2[count2-1-3+2],p22[count2-1-3]))
			sum=0;
	}
	while(sum);
	value2copy=p33[count2-1-3][0]*p3[count2-1-3+2][1]-p33[count2-1-3][1]*p3[count2-1-3+2][0];
	x[count2-1-3+2]=(int*)malloc(2*sizeof(int));
	y[count2-1-3]=(int*)malloc(2*sizeof(int));
	if(p222[count2-1-3]<0)                                  /*insert 第二部分首*/
	{
		a[0][0]=-p222[count2-1-3];
		a[0][1]=-1;
	}
	else
	{
		a[0][0]=p222[count2-1-3];
		a[0][1]=1;
	}
	if(pp22[count2-1-3+2]<0)
	{
		a[1][0]=-pp22[count2-1-3+2];
		a[1][1]=-1;
	}
	else
	{
		a[1][0]=pp22[count2-1-3+2];
		a[1][1]=1;
	}
	list(a[0],a[1]);
	a[1][1]=-a[1][1];
	for(i=0;i<2;i++)
		c[i][1]=a[i][1];                                    /*insert 第二部分,部分尾:保留原非系数部分的符号.*/
	if(pp22[count2-1-3+2]>0)                                /*这里本来是判断p222[count2-1-3]*pp22[count2-1-3+2]>0,但由于p222[count2-1-3]本身就已经人为规定>0了,所以能让程序跑快点就让它跑快点嘛.*/
		flag=maxjoint(p2[count2-1-3+2],p22[count2-1-3]);
	else
		flag=-maxjoint(p2[count2-1-3+2],p22[count2-1-3]);
	x[count2-1-3+2][1]=p222[count2-1-3]/flag;
	y[count2-1-3][1]=-pp22[count2-1-3+2]/flag;
	for(i=0;i<2;i++)										/*新的替代品__始端*/
		b[i]=0;
	m[0]=p22[count2-1-3];                                   /*细微的差别*/
	m[1]=p2[count2-1-3+2];
	for(i=0;i<2;i++)
		z[i]=i;
	if(m[0]>m[1])
	{
		t=m[0];
		m[0]=m[1];
		m[1]=t;
		t=z[0];												/*当值交换时,下角标也跟着交换.*/
		z[0]=z[1];
		z[1]=t;
	}
	if(p2[count2-1]<0)
	{
		get(2,-p2[count2-1]);
		for(i=0;i<2;i++)
			b[i]=-b[i];
	}
	else
		get(2,p2[count2-1]);
	{
		x[count2-1-3+2][0]=(p33[count2-1-3][0]*b[1]-b[0]*p3[count2-1-3+2][0])/value2copy;
		y[count2-1-3][0]=(b[0]*p3[count2-1-3+2][1]-p33[count2-1-3][1]*b[1])/value2copy;
		if(p2[count2-1]<0)                                  /*insert 第二部分,部分首.*/
		{
			a[2][0]=-p2[count2-1];
			a[2][1]=-1;
		}
		else
		{
			a[2][0]=p2[count2-1];
			a[2][1]=1;
		}
		if(a[2][1]==-1)
		{
			a[2][1]=-a[2][1];
			a[0][1]=-a[0][1];
			a[1][1]=-a[1][1];
		}
		if(changehappens)
		{
			x1=x[count2-1-3+2][0]*a[0][1];
			x2=y[count2-1-3][0]*a[1][1];
		}
		else
		{
			x1=y[count2-1-3][0]*a[0][1];
			x2=x[count2-1-3+2][0]*a[1][1];
		}
		if(x1*2<=-a[1][0]/getmin[0])                        /*新的判断标准和对应的执行标准*/
		{
			xi1=a[1][0]/getmin[0]/2-(-x1+a[1][0]/getmin[0]/2)%(a[1][0]/getmin[0]);    /*本身是-xi1=(-x1+a[1][0]/getmin[0]/2)%(a[1][0]/getmin[0])-a[1][0]/getmin[0]/2*/
			xi2=x2+a[0][0]/getmin[0]*((-x1+a[1][0]/getmin[0]/2)-(-x1+a[1][0]/getmin[0]/2)%(a[1][0]/getmin[0]))/(a[1][0]/getmin[0]);
		}
		else
		{
			xi1=(x1+a[1][0]/getmin[0]/2)%(a[1][0]/getmin[0])-a[1][0]/getmin[0]/2;
			xi2=x2-a[0][0]/getmin[0]*((x1+a[1][0]/getmin[0]/2)-(x1+a[1][0]/getmin[0]/2)%(a[1][0]/getmin[0]))/(a[1][0]/getmin[0]);
			if(xi1*2==-a[1][0]/getmin[0])
			{
				xi1=xi1+a[1][0]/getmin[0];
				xi2=xi2+a[0][0]/getmin[0];
			}
		}
		if(abs(xi1)+abs(xi2)>abs(xi1+a[1][0]/getmin[0])+abs(xi2+a[0][0]/getmin[0]))
		{
			xi1=xi1+a[1][0]/getmin[0];
			xi2=xi2+a[0][0]/getmin[0];
		}
		if(changehappens)
		{
			y[count2-1-3][0]=xi2/a[1][1];
			x[count2-1-3+2][0]=xi1/a[0][1];
		}
		else
		{
			y[count2-1-3][0]=xi1/a[0][1];
			x[count2-1-3+2][0]=xi2/a[1][1];
		}
		for(t=0;t<2;t++)
			a[t][1]=c[t][1];                                /*insert 第二部分,部分尾:还原a[0][1]和a[1][1].*/
	}														/*新的替代品__末端*/
/*************************************************/
	for(k=count2-1-3-1;k>=0;k--)
	{
		sum=1;
		minandAddress(p2[k+2],p22[k],k+2);
		do
		{
			pp2[0]=p22[k];                                  /*保留值*/ 
			pp2[1]=p2[k+2];
			if(p22[k]%getmin[0]!=0)
				p22[k]=p22[k]%getmin[0];
			if(p2[k+2]%getmin[0]!=0)
				p2[k+2]=p2[k+2]%getmin[0];
			if(getmin[1]==k)
			{
				p33[k][0]=p33[k][0]+(pp2[1]-p2[k+2])/getmin[0]*p3[k+2][0];
				p33[k][1]=p33[k][1]+(pp2[1]-p2[k+2])/getmin[0]*p3[k+2][1];
			}
			else
			{
				p3[k+2][0]=p3[k+2][0]+(pp2[0]-p22[k])/getmin[0]*p33[k][0];
				p3[k+2][1]=p3[k+2][1]+(pp2[0]-p22[k])/getmin[0]*p33[k][1];
			}
			minandAddress(p2[k+2],p22[k],k+2);
			if(getmin[0]==maxjoint(p2[k+2],p22[k]))
				sum=0;
		}
		while(sum);
		value2copy=p33[k][0]*p3[k+2][1]-p33[k][1]*p3[k+2][0];
		x[k+2]=(int*)malloc((count2-1-k-1)*sizeof(int));
		y[k]=(int*)malloc((count2-1-k-1)*sizeof(int));
		if(p222[k]<0)                                       /*insert 第二部分首*/
		{
			a[0][0]=-p222[k];
			a[0][1]=-1;
		}
		else
		{
			a[0][0]=p222[k];
			a[0][1]=1;
		}
		if(pp22[k+2]<0)
		{
			a[1][0]=-pp22[k+2];
			a[1][1]=-1;
		}
		else
		{
			a[1][0]=pp22[k+2];
			a[1][1]=1;
		}
		list(a[0],a[1]);
		a[1][1]=-a[1][1];
		for(i=0;i<2;i++)
			c[i][1]=a[i][1];                                /*insert 第二部分,部分尾:保留原非系数部分的符号.*/
		if(pp22[k+2]>0)
			flag=maxjoint(p2[k+2],p22[k]);
		else
			flag=-maxjoint(p2[k+2],p22[k]);
		x[k+2][count2-1-k-2]=p222[k]/flag;
		y[k][count2-1-k-2]=-pp22[k+2]/flag;
		m[0]=p22[k];                                        /*新的替代品__始端;细微的差别;只有它们能写在外面;那么现在开始放在里面的许多与i无关的i得改为t*/
		m[1]=p2[k+2];
		for(i=0;i<2;i++)
			z[i]=i;
		if(m[0]>m[1])
		{
			t=m[0];
			m[0]=m[1];
			m[1]=t;
			t=z[0];											/*当值交换时,下角标也跟着交换.*/
			z[0]=z[1];
			z[1]=t;
		}
		for(i=count2-1-k-3;i>=0;i--)
		{
			for(t=0;t<2;t++)                                /*结构改变了,(从这开始都)它跑里面来了,每次使用都需要初始化b.*/
				b[t]=0;
			if(y[k+1][i]<0)                                 /*这里本该写作y[k+1][i]*p222[k+1]<0的*/
			{
				get(2,-p222[k+1]*y[k+1][i]);
				for(t=0;t<2;t++)
					b[t]=-b[t];
			}
			else
				get(2,p222[k+1]*y[k+1][i]);
			x[k+2][i]=(p33[k][0]*b[1]-b[0]*p3[k+2][0])/value2copy;
			y[k][i]=(b[0]*p3[k+2][1]-p33[k][1]*b[1])/value2copy;
			if(y[k+1][i]<0)                                 /*insert 第二部分,部分首.*/
			{
				a[2][0]=-y[k+1][i]*p222[k+1];
				a[2][1]=-1;
			}
			else
			{
				a[2][0]=y[k+1][i]*p222[k+1];
				a[2][1]=1;
			}
			if(a[2][1]==-1)
			{
				a[2][1]=-a[2][1];
				a[0][1]=-a[0][1];
				a[1][1]=-a[1][1];
			}
			if(changehappens)
			{
				x1=x[k+2][i]*a[0][1];
				x2=y[k][i]*a[1][1];
			}
			else
			{
				x1=y[k][i]*a[0][1];
				x2=x[k+2][i]*a[1][1];
			}
			if(x1*2<=-a[1][0]/p222[k+1])                    /*新的判断标准和对应的执行标准*/
			{
				xi1=a[1][0]/p222[k+1]/2-(-x1+a[1][0]/p222[k+1]/2)%(a[1][0]/p222[k+1]);    /*本身是-xi1=(-x1+a[1][0]/p222[k+1]/2)%(a[1][0]/p222[k+1])-a[1][0]/p222[k+1]/2*/
				xi2=x2+a[0][0]/p222[k+1]*((-x1+a[1][0]/p222[k+1]/2)-(-x1+a[1][0]/p222[k+1]/2)%(a[1][0]/p222[k+1]))/(a[1][0]/p222[k+1]);
			}
			else
			{
				xi1=(x1+a[1][0]/p222[k+1]/2)%(a[1][0]/p222[k+1])-a[1][0]/p222[k+1]/2;
				xi2=x2-a[0][0]/p222[k+1]*((x1+a[1][0]/p222[k+1]/2)-(x1+a[1][0]/p222[k+1]/2)%(a[1][0]/p222[k+1]))/(a[1][0]/p222[k+1]);
				if(xi1*2==-a[1][0]/p222[k+1])
				{
					xi1=xi1+a[1][0]/p222[k+1];
					xi2=xi2+a[0][0]/p222[k+1];
				}
			}
			if(abs(xi1)+abs(xi2)>abs(xi1+a[1][0]/p222[k+1])+abs(xi2+a[0][0]/p222[k+1]))
			{
				xi1=xi1+a[1][0]/p222[k+1];
				xi2=xi2+a[0][0]/p222[k+1];
			}
			if(changehappens)
			{
				y[k][i]=xi2/a[1][1];
				x[k+2][i]=xi1/a[0][1];
			}
			else
			{
				y[k][i]=xi1/a[0][1];
				x[k+2][i]=xi2/a[1][1];
			}
			for(t=0;t<2;t++)
				a[t][1]=c[t][1];                            /*insert 第二部分,部分尾:还原a[0][1]和a[1][1].*/
		}                                                   /*新的替代品__末端*/
	}
/*************************************************/         /*相当于k=-1*/
	sum=1;
	minandAddress(p2[1],p2[0],1);
	do
	{
		pp2[0]=p2[0];                                       /*保留值*/ 
		pp2[1]=p2[1];
		if(p2[0]%getmin[0]!=0)
			p2[0]=p2[0]%getmin[0];
		if(p2[1]%getmin[0]!=0)
			p2[1]=p2[1]%getmin[0];
		if(getmin[1]==1-2)
		{
			p3[0][0]=p3[0][0]+(pp2[1]-p2[1])/getmin[0]*p3[1][0];
			p3[0][1]=p3[0][1]+(pp2[1]-p2[1])/getmin[0]*p3[1][1];
		}
		else 
		{
			p3[1][0]=p3[1][0]+(pp2[0]-p2[0])/getmin[0]*p3[0][0];
			p3[1][1]=p3[1][1]+(pp2[0]-p2[0])/getmin[0]*p3[0][1];
		}
		minandAddress(p2[1],p2[0],1);
		if(getmin[0]==maxjoint(p2[1],p2[0]))
			sum=0;
	}
	while(sum);
	value2copy=p3[0][0]*p3[1][1]-p3[0][1]*p3[1][0];
	x[1]=(int*)malloc((count2-1)*sizeof(int));
	x[0]=(int*)malloc((count2-1)*sizeof(int));
	if(pp22[0]<0)                                           /*insert 第二部分首*/
	{
		a[0][0]=-pp22[0];
		a[0][1]=-1;
	}
	else
	{
		a[0][0]=pp22[0];
		a[0][1]=1;
	}
	if(pp22[1]<0)
	{
		a[1][0]=-pp22[1];
		a[1][1]=-1;
	}
	else
	{
		a[1][0]=pp22[1];
		a[1][1]=1;
	}
	list(a[0],a[1]);
	a[1][1]=-a[1][1];
	for(i=0;i<2;i++)
		c[i][1]=a[i][1];                                    /*insert 第二部分,部分尾:保留原非系数部分的符号.*/
	if(pp22[0]*pp22[1]>0)                                   /*这里才是真迹:如果系数异号,则规定它们的最大公因数为负值.*/
		flag=maxjoint(p2[1],p2[0]);
	else
		flag=-maxjoint(p2[1],p2[0]);
	x[1][count2-2]=pp22[0]/flag;
	x[0][count2-2]=-pp22[1]/flag;
	for(i=0;i<2;i++)										/*新的替代品__始端;同样,只有它们能写在外面;*/
		m[i]=p2[i];
	for(i=0;i<2;i++)
		z[i]=i;
	if(m[0]>m[1])
	{
		t=m[0];
		m[0]=m[1];
		m[1]=t;
		t=z[0];												/*当值交换时,下角标也跟着交换.*/
		z[0]=z[1];
		z[1]=t;
	}
	for(i=count2-3;i>=0;i--)
	{
		for(t=0;t<2;t++)
			b[t]=0;
		if(y[0][i]<0)
		{
			get(2,-p222[0]*y[0][i]);
			for(t=0;t<2;t++)
				b[t]=-b[t];
		}
		else
			get(2,p222[0]*y[0][i]);
		x[1][i]=(p3[0][0]*b[1]-b[0]*p3[1][0])/value2copy;
		x[0][i]=(b[0]*p3[1][1]-p3[0][1]*b[1])/value2copy;
		if(y[0][i]<0)                                       /*insert 第二部分,部分首.*/
		{
			a[2][0]=-y[0][i]*p222[0];
			a[2][1]=-1;
		}
		else
		{
			a[2][0]=y[0][i]*p222[0];
			a[2][1]=1;
		}
		if(a[2][1]==-1)
		{
			a[2][1]=-a[2][1];
			a[0][1]=-a[0][1];
			a[1][1]=-a[1][1];
		}
		if(changehappens)
		{
			x1=x[1][i]*a[0][1];
			x2=x[0][i]*a[1][1];
		}
		else
		{
			x1=x[0][i]*a[0][1];
			x2=x[1][i]*a[1][1];
		}
		if(x1*2<=-a[1][0]/p222[0])                          /*新的判断标准和对应的执行标准*/
		{
			xi1=a[1][0]/p222[0]/2-(-x1+a[1][0]/p222[0]/2)%(a[1][0]/p222[0]);    /*本身是-xi1=(-x1+a[1][0]/p222[0]/2)%(a[1][0]/p222[0])-a[1][0]/p222[0]/2*/
			xi2=x2+a[0][0]/p222[0]*((-x1+a[1][0]/p222[0]/2)-(-x1+a[1][0]/p222[0]/2)%(a[1][0]/p222[0]))/(a[1][0]/p222[0]);
		}
		else
		{
			xi1=(x1+a[1][0]/p222[0]/2)%(a[1][0]/p222[0])-a[1][0]/p222[0]/2;
			xi2=x2-a[0][0]/p222[0]*((x1+a[1][0]/p222[0]/2)-(x1+a[1][0]/p222[0]/2)%(a[1][0]/p222[0]))/(a[1][0]/p222[0]);
			if(xi1*2==-a[1][0]/p222[0])
			{
				xi1=xi1+a[1][0]/p222[0];
				xi2=xi2+a[0][0]/p222[0];
			}
		}
		if(abs(xi1)+abs(xi2)>abs(xi1+a[1][0]/p222[0])+abs(xi2+a[0][0]/p222[0]))
		{
			xi1=xi1+a[1][0]/p222[0];
			xi2=xi2+a[0][0]/p222[0];
		}
		if(changehappens)
		{
			x[0][i]=xi2/a[1][1];
			x[1][i]=xi1/a[0][1];
		}
		else
		{
			x[0][i]=xi1/a[0][1];
			x[1][i]=xi2/a[1][1];
		}
		for(t=0;t<2;t++)
			a[t][1]=c[t][1];                                /*insert 第二部分,部分尾:还原a[0][1]和a[1][1].*/
	}                                                       /*新的替代品__末端*/
/*************************************************/
	printf("x%d=",1);
	for(i=count2-2;i>=1;i--)
		printf("%dt%d+",x[0][i],i);
	printf("%d",x[0][0]);
	printf("\n");
	for(k=1;k<=count2-2;k++)
	{
		printf("x%d=",k+1);
		for(i=count2-1-k;i>=1;i--)
			printf("%dt%d+",x[k][i],i);
		printf("%d",x[k][0]);
		printf("\n");
	}
	printf("\n");
/*************************************************/
	free(x[0]);
	x[0]=NULL;
	free(x[1]);
	x[1]=NULL;
	for(k=0;k<=count2-1-3-1;k++)
	{
		free(y[k]);
		y[k]=NULL;
		free(x[k+2]);
		x[k+2]=NULL;
	}
	free(y[count2-1-3]);
	y[count2-1-3]=NULL;
	free(x[count2-1-3+2]);
	x[count2-1-3+2]=NULL;
	free(p222);
	p222=NULL;
	free(y);
	y=NULL;
	free(x);
	x=NULL;
	for(i=0;i<count2-1-2;i++)
	{
		free(p33[i]);
		p33[i]=NULL;
	}
	free(p33);
	p33=NULL;
	free(p22);
	p22=NULL;
	free(pp22);
	pp22=NULL;
	for(i=0;i<count2-1;i++)
	{
		free(p3[i]);
		p3[i]=NULL;
	}
	free(p3);
	p3=NULL;
	free(p2);
	p2=NULL;
	free(p1);
	p1=NULL;
}
/*pp22是p2的复制品,保留了它的符号,是纯a类系数;然后p2符号一点点地全为正了,且用pp2记录了p2和p2、p2和pp2的最大公因数的b类系数;p222是p22的复制品,即是一系列b类系数和最大公因数;p2与p2、p2与p22之后会进行超级辗转相除,丢失信息,pp22和p222的价值便体现出来了:原始的二元一次不定方程们的3个系数.*/
/*p222[k]x+pp22[k+2]y=y[k+1][i]*p222[k+1]*/
/*p22[k]x+p2[k+2]y=|y[k+1][i]*p222[k+1]|*/
/*m[z[1]]是超级辗转相除后的p2与p2、p2与p22中的较大的系数,b[z[1]]是它的非系数部分,即超级辗转后的全正系数方程的解.*/
