#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int *m=(int*)malloc(sizeof(int)),countk=0,count1,*x=(int*)malloc(sizeof(int));
int maxjoint(int count)                                     /*创造函数maxjoint调取一串整数,返回它们的最大公因数值*/
{
	int j,i,t,*pp=(int*)malloc(count*sizeof(int));
	for(j=count-1;j>0;j--)                                  /*刚开始就调换好所有相邻数据的大小顺序以便之后的辗转相除*/
	{
		for(i=0;i<j;i++)
		{
			if(m[i]>m[i+1])
			{
				t=m[i];
				m[i]=m[i+1];
				m[i+1]=t;
			}
		}
	}
	for(i=0;i<count;i++)                                    /*初始化m的复制品*/
		pp[i]=m[i];
	for(i=0;i<=count-2;i++)                                 /*由于之前是从左往右==从小到大,那么此时得从前往后轮换*/
	{
		do
		{
			t=pp[i+1]%pp[i];
			pp[i+1]=pp[i];
			pp[i]=t;
		}
		while (t!=0);                                       /*跳出循环后m[i]就是m[i]和m[i+1]的最大公因,而剩下的所有右边的m[i+1]会全是0*/
	}
	t=pp[count-2+1];
	free(pp);                                               /*不用的早点释放掉*/
	pp=NULL;
	return t;
}
void get(int n,int leftovers)
{
	if(leftovers==0)
	{
		int i;
		for(i=0;i<n;i++)
			x[i]=0;
		for(i=0;i<count1;i++)
			printf("%d ",x[i]);
		printf("\n");
		countk=countk+1;
	}
	else if(n==1)                                           /*这个东西逻辑上最好在leftovers==0的后面,但事实上我们的算法允许它们交换位置.因为可能当n==2的时候,进入该函数的else里后,发现x[1]取j的最大值时,余数leftovers-m[1]*j==0,这样会出现进入下一层函数get(1,0),此时我们希望的是先判断leftovers是否等于0,因为已经找到一个合理解了.而如果此时先判断n==1,由于leftovers==0,所以条件leftovers%m[0]==0恒为真,使得x[0]=leftovers/m[0];语句达到和for(i=0;i<n;i++) x[i]=0;语句相同的初始化x[0]为0的效果,并且其他之后剩下的语句均一样.这样以另一个判断标准判断其为有效非负整数解组,让人感到有点odd,奇怪.但从逻辑上似乎也说得通,所以在我们的算法上是行得通的.*/
	{
		if(leftovers%m[0]==0)
		{
			x[0]=leftovers/m[0];
			for(int i=0;i<count1;i++)
				printf("%d ",x[i]);
			printf("\n");
			countk=countk+1;
		}
		else
			;                                               /*什么都不做.至于为什么第一个空x0不必要每次都赋值为0,是因为如果1.在此之前有x0=0的整数解,那么x0会被赋值为0|2.如果在此的时候才有x0=某某某的整数解,那么x0直接被赋值为某某某就行了|3.如果在此的时候仍没找到整数解,那么不输出就行了,保留上一个x0值没有任何问题,反正下一个整数解出来的时候,要么x0=0,输出;要么x0=某某某,然后输出*/
	}
	else if(m[n-1]>leftovers)                         
		get(n-1,leftovers);                                 /*这个要写在n==1的后面,即得先判断是否n减来==1.所以上次的只是特殊系数的特殊算法.因为如果出现了当n==1的时候m[0]>leftovers(不知道你输入的各项系数中的最小值m[0]是多少,而leftovers有可能=1,所以有可能当n==1的时候却进入了m[0]>leftovers的流程),则会进入下一层函数,出现m[-1],访问的空间将不在范围内.此时理应进入n==1的判断的.|而上一个之所以可行是因为m[0]恒=1,而leftovers不会小于1(余数难道有小余1的?),所以会直接不满足m[0]>leftovers,然后进入n==1的流程.*/
	else
	for(int j=(leftovers-leftovers%m[n-1])/m[n-1];j>=0;j--) /*满足leftovers不等于0且n不等于1且m[n-1]不大于leftovers的才是可继续分解的.*/
	{
		x[n-1]=j;
		get(n-1,leftovers-m[n-1]*j);
	}
}
int main()
{
	char s,*p1=(char*)malloc(1);
	int *p2=(int*)malloc(sizeof(int)),count2=0,sum,i;
	printf("请像这样(请不要输入非整数和0和负整数)输入多元一次不定方程\na1x1+a2x2+...+anxn=b 的系数 'a1,a2,a3,a4,...b,' 后，按enter键:\n\n");
	s=getchar();                                            /*创造一个scanf函数用于实现我的功能,刚开始就需要值进来,所以不用dowhile*/
	while(s!='\n')
	{
		if(s<=57&&s>=48)
		{
			count1++;                                       /*统计输入了多少个"假·数字"进来*/
			*(p1+count1-1)=s;                               /*将s的值放入距离p1共(count1-1)的地址对应的内容里,即放入上一步所创建的多出来的那个空间中*/
			p1=(char*)realloc(p1,count1+1);                 /*将p1的空间扩张至(假·数字个数+1)个字节,预备下一次输入。这条语句会"初始化"p1的值*/
		}
		else if(s==',')                                     /*即使输入了负数,也会被默认为正数*/
		{
			sum=0;                                          /****************************************************初始化sum值,为了下面的循环*/
			for(i=0;i<=count1-1;i++)
				sum=sum+(*(p1+i)-'0')*(int)pow(10,count1-1-i);
			count1=0;p1=(char*)realloc(p1,1);               /****************************************************初始化count1值和p1拥有的地址量,均是为了下一次循环的第一个if*/
			count2++;                                       /*统计输入了多少个"真·数字"进来*/
			*(p2+count2-1)=sum;                             /*将sum的值放入距离p2共(count2-1)的地址对应的内容里*/
			p2=(int*)realloc(p2,(count2+1)*sizeof(int));    /*将p2的空间扩张至(真·数字个数+1)个整数空间,预备下一次输入。最后它会像p1一样总会空出一个空间,不过不影响我们的继续,所以循环外不用改小一格它*/
		}
		s=getchar();
	}
	if(count2-1<2)
	{
		printf("\n********你输入得太少了!有解无解和解是多少都能自己算的出来了!********\n\n!");
		return 0;
	}
	m=(int*)realloc(m,(count2-1)*sizeof(int));
	for(i=0;i<count2-1;i++)                                 /*初始化p2的复制品*/
		m[i]=p2[i];
	if(p2[count2-1]%maxjoint(count2-1)!=0)
	{
		printf("您输入的多元一次不定方程无整数解。\n\n");
		free(p2);
		p2=NULL;
		free(p1);
		p1=NULL;
		return 0;
	}
	count1=count2-1;
	for(i=count2-2;i>=0;i--)                                /*把大于n的所有后面的项给删掉*/
		if(m[i]>p2[count2-1])
		{
			m=(int*)realloc(m,i*sizeof(int));
			count1=i;                                       /*记录最后的m中的空格数*/
		}
	x=(int*)realloc(x,count1*sizeof(int));
	for(i=0;i<count1;i++)
		x[i]=0;                                             /*上一个程序不需要初始化xi也可以,因为由于m(imax)=n,在第一次执行函数get的时候,由于n能整除m(imax)=n,使得leftovers带进下一个get函数中,会使得之前的各个xi均=0;但是这一个程序没有这个优越性,所以得初始化值*/
	printf("\n");
	for(i=0;i<count1;i++)
		printf("%d ",m[i]);
	printf("%d ",p2[count2-1]);
	printf("\n\n");
	get(count1,p2[count2-1]);
	printf("\n");
	printf("如上所示,共有%d组解",countk);
	printf("\n\n");
}
