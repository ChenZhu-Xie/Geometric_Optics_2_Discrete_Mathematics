#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int getmin[2],value1=1,sign=1,value2=0,*b,*m,*x;            /*创造一个有两元素的一维全局数组变量getmin[2],一个累乘器,一个对换装置,一个累加器.*/
void minandAddress(int *p,int count)                        /*创造一个无返回值函数,获取一个地址和该地址下的int类地址个数*/
{
	int i;
	getmin[0]=p[0];
	getmin[1]=0;
	for(i=1;i<count;i++)
	{
		if(p[i]<getmin[0])                                  /*这里确定了最小值将是第一个最小值,因为如果之后的p[i]=getmin[0],则getmin[1]不会改变*/
		{
			getmin[0]=p[i];
			getmin[1]=i;
		}
	}
}
int maxjoint(int *p,int count)                              /*创造函数maxjoint调取一串整数,返回它们的最大公因数值*/
{
	int j,i,t,*pp=(int*)malloc(count*sizeof(int));          /*p2这个地址是共用的,为了保持p2内容(即实验者之前的输入顺序)不变,创造一个p2的复制品*/
	for(i=0;i<count;i++)                                    /*初始化p2的复制品*/
		pp[i]=p[i];
	for(j=count-1;j>0;j--)                                  /*刚开始就调换好所有相邻数据的大小顺序以便之后的辗转相除*/
	{
		for(i=0;i<j;i++)
		{
			if(pp[i]<pp[i+1])
			{
				t=pp[i];
				pp[i]=pp[i+1];
				pp[i+1]=t;
			}
		}
	}
	for(i=count-2;i>=0;i--)                                 /*由于之前是从左往右==从大到小,那么此时得从后往前轮换*/
	{
		do
		{
			t=pp[i]%pp[i+1];
			pp[i]=pp[i+1];
			pp[i+1]=t;
		}
		while (t!=0);                                       /*跳出循环后pp[i]就是pp[i]和pp[i+1]的最大公因,而剩下的所有右边的pp[i+1]会全是0*/
	}
	t=pp[0];
	free(pp);                                               /*不用的早点释放掉*/
	pp=NULL;
	return t;
}
void initialisep4(int *p4,int count)                        /*本来以为matrix函数会改变p4的排序状况,因而想设置它来每次调用它来初始化p4,多心了*/
{
	int i;
	for(i=0;i<count;i++)
		p4[i]=i;
}
void exchange(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void matrix(int *j,int min,int max,int **p3)                /*输入一组关于列的下角标j排列的地址,地址起始偏移量,地址最末偏移量,用于计算的行列式首地址*/
{
	if(min==max)                                            /*丰收的标志:该收割此次收获了*/
	{
		for(int k=0;k<=max;k++)
			value1*=p3[k][j[k]];                            /*累乘器起作用了*/
		value2+=value1*sign;                                /*累加器起作用了*/
		value1=1;                                           /*初始化累乘器*/
	}
	else
	{
		for(int i=min;i<=max;i++)
		{
			exchange(j+min,j+i);
			if(i!=min)                                      /*不和自己对换的对换称为有效对换,当有效对换一次时,排列改变奇偶性*/
				sign=-1*sign;
			matrix(j,min+1,max,p3);
			exchange(j+min,j+i);
			if(i!=min)                                      /*好东西在这里也得写,不然就成为坏东西了*/
				sign=-1*sign;
		}
	}
}
int matrixoutput(int *j,int min,int max,int **p3,int **pp3,int k)
{
	int jj,ii;
	value2=0;                                               /*初始化value2*/
	for(jj=0;jj<=max;jj++)                                  /*初始化pp3成p3的样子*/
		for(ii=0;ii<=max;ii++)
			pp3[ii][jj]=p3[ii][jj];
/*	for(ii=0;ii<=max;ii++)                                  打印原始系数矩阵
	{
		for(jj=0;jj<=max;jj++)
			printf("%4d",pp3[ii][jj]);
			printf("\n");
	}*/
	for(ii=0;ii<=max;ii++)                                  /*用b代换后的系数矩阵*/
		pp3[ii][k]=b[ii];
/*	printf("\n");                                           打印它
	for(ii=0;ii<=max;ii++)
	{
		for(jj=0;jj<=max;jj++)
			printf("%4d",pp3[ii][jj]);
			printf("\n");
	}*/
	matrix(j,min,max,pp3);
	return value2;
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
			b[x[0]]=leftovers/m[0];
		}
		else
			;                                               /*这里将不会有此else情况出现*/
	}
	else if(m[n-1]>leftovers)                         
		get(n-1,leftovers);                                 /*这个要写在n==1的后面,即得先判断是否n减来==1.所以上次的只是特殊系数的特殊算法.因为如果出现了当n==1的时候m[0]>leftovers(不知道你输入的各项系数中的最小值m[0]是多少,而leftovers有可能=1,所以有可能当n==1的时候却进入了m[0]>leftovers的流程),则会进入下一层函数,出现m[-1],访问的空间将不在范围内.此时理应进入n==1的判断的.|而上一个之所以可行是因为m[0]恒=1,而leftovers不会小于1(余数难道有小余1的?),所以会直接不满足m[0]>leftovers,然后进入n==1的流程.*/
	else
	{
		b[x[n-1]]=(leftovers-leftovers%m[n-1])/m[n-1];
		get(n-1,leftovers%m[n-1]);
	}
}
/*注:p2有count2+1个空间;有count2个数;有count2-1个ai系数;count=count2-1即系数个数;count-1即末位系数的数组序数(下标)*/
int main()
{
	char *p1=(char*)malloc(1);
	int *p2=(int*)malloc(sizeof(int)),**p3,*pp2,s,count1=0,count2=0,i,sum,j,getmax,*p4,value2copy,**pp3,flag=1,t;
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
			flag=-1;                                        /*只要输入了负号,不管输入了多少个,逗号与逗号之间的数均判定为负.*/
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
	p3=(int**)malloc((count2-1)*sizeof(int*));              /*除b以外有(count2-1)个系数,所以只需给二维数组的首地址p3分配那么多空间,因为只有那么多个非系数部分(行/一维数组)*/
	for(i=0;i<count2-1;i++)
	{
		p3[i]=(int*)malloc((count2-1)*sizeof(int));         /*除b以外有(count2-1)个系数,所以只需给一维数组的首地址p3[i]分配那么多空间,因为只有那么多个非系数部分里的非系数部分(列/一维数组里的元素)*/
		for(j=0;j<count2-1;j++)
			if(j==i)                                        /*趁此机会把非系数部分的值给赋了,和下面构成系数部分和非系数部分之内外负号调换*/
				if(p2[i]>0)
					p3[i][j]=1;
				else p3[i][j]=-1;
			else p3[i][j]=0;
		p2[i]=abs(p2[i]);                                   /*趁此机会把系数部分取绝对值,和上面构成系数部分和非系数部分之内外负号调换*/
	}
	getmax=maxjoint(p2,count2-1);                           /*在用maxjoint之前得保证系数是正的,所以p3的创造和赋值也得在之前*/
	if(p2[count2-1]%getmax!=0)
	{
		printf("您输入的多元一次不定方程无整数解。\n\n");
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
	sum=1;                                                  /*创建跳出循环的条件:只要这一群系数中有一个等于上一群(=最开始的)系数的最大公因数,则跳出*/
	pp2=(int*)malloc((count2-1)*sizeof(int));               /*复制一个p2的镜像,短暂保存当前的p2下的各地址的值*/
	minandAddress(p2,count2-1);                             /*传计算出来后保存至所开辟的两个空间里的值给getmin*/
	do                                                      /**************进入数学部分**************/
	{
		for(i=0;i<count2-1;i++)                             /*好吧,为了之后的简洁,我们还是全部初始化好了*/ 
			pp2[i]=p2[i];
		for(i=0;i<count2-1;i++)                             /*先搞定系数部分,此过程中不能动最小系数方的非系数部分*/
		{
			if(p2[i]%getmin[0]!=0)                          /***********→→→→就是这里,得把原来的p2[i]!=getmin[0]改为p2[i]%getmin[0]!=0,即从"不等于"改为"不整除"为输出方***********/
/*				pp2[i]=p2[i];                               初始化p2的复制品,将此语句放入此if下,是因为最小系数方的非系数部分只接受给予方的非系数部分,所以没必要将p2下的内容全拿给pp2*/
				p2[i]=p2[i]%getmin[0];                      /*若为非最小值,即为输出方,即系数部分输出,而非系数部分不改变;最小值方们系数部分均未改变*/
		}
		for(j=0;j<count2-1;j++)                             /*搞定非系数部分*/
		{
			for(i=0;i<count2-1;i++)
			{
				p3[getmin[1]][j]=p3[getmin[1]][j]+(pp2[i]-p2[i])/getmin[0]*p3[i][j];
			}
		}                                                   /*当p2[i]==getmin[0]&&i!=getmin[1]时,系数部分和非系数部分均不发生改变.此时并集已经为全.***********→→→→修正为:满足p2[i]%getmin[0]==0&&i!=getmin[1]的这些项的两部分均不改变************/
		minandAddress(p2,count2-1);
		if(getmin[0]==getmax)                               /***********→→→→根据修正后的观念,这句话既可以按原来的翻译,也可以翻译为:如果所有项的系数部分均能整除它们的最大公因数,那么根据理论这些项的两部分均不改变,则程序的mission已经accomplished***********/
		{
			sum=0;
			b=(int*)malloc((count2-1)*sizeof(int));         /*相当于444333中的xi*/
			for(i=0;i<count2-1;i++)
				b[i]=0;
			m=(int*)realloc(m,(count2-1)*sizeof(int));      /*初始化p2的复制品*/
			for(i=0;i<count2-1;i++)
				m[i]=p2[i];
			x=(int*)realloc(x,(count2-1)*sizeof(int));      /*用于记录下角标的跟随变化*/
			for(i=0;i<count2-1;i++)
				x[i]=i;
			for(j=count2-1-1;j>0;j--)                       /*从左往右==从小到大*/
			{
				for(i=0;i<j;i++)
				{
					if(m[i]>m[i+1])
					{
						t=m[i];
						m[i]=m[i+1];
						m[i+1]=t;
						t=x[i];                             /*当值交换时,下角标也跟着交换.*/
						x[i]=x[i+1];
						x[i+1]=t;
					}
				}
			}
			if(p2[count2-1]<0)
			{
				get(count2-1,-p2[count2-1]);
				for(i=0;i<count2-1;i++)
					b[i]=-b[i];
			}
			else
				get(count2-1,p2[count2-1]);
		}
	}
	while(sum);
	p4=(int*)malloc((count2-1)*sizeof(int));
	initialisep4(p4,count2-1);
	matrix(p4,0,count2-2,p3);
	value2copy=value2;
	pp3=(int**)malloc((count2-1)*sizeof(int*));             /*创造一个p3的copy,用于将常数项b[i]替换掉系数矩阵中的第j列矢量*/
	for(i=0;i<count2-1;i++)
		pp3[i]=(int*)malloc((count2-1)*sizeof(int));
	for(j=0;j<count2-1;j++)                                 /*输出*/
	{
		printf("x%d=%d\n",j+1,matrixoutput(p4,0,count2-2,p3,pp3,j)/value2copy);
/*		for(i=0;i<count2-1;i++)                             用于调试中检查程序运行情况.
			printf("%d",p4[i]);
		printf("\n%d\n",sign);*/
	}
	printf("\n");
	for(i=0;i<count2-1;i++)                                 /*弹出*/
	{
		free(pp3[i]);
		pp3[i]=NULL;
	}
	free(pp3);
	pp3=NULL;
	free(p4);
	p4=NULL;
	free(x);
	x=NULL;
	free(m);
	m=NULL;
	free(b);
	b=NULL;
	free(pp2);
	pp2=NULL;
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
