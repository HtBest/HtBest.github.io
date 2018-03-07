#define _CRT_SECURE_NO_DEPRECATE
/************************
*创建时间：2018 03 03
*文件类型：源代码文件
*题目来源：NOIP
*采用算法：DP
*备忘：
*作者：HtBest
 ************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n,k,p,nowh[50],newh[50],color,cost;
long long ans;
/* Variable explain:
n:客栈个数 
k:客栈颜色 
p:期望消费 
a:每个客栈信息
nowh:在最后一个可用咖啡馆之前的客栈个数
newh:在最后一个可用咖啡馆之后的客栈个数 
ans:储存答案
lastc:储存最后一个旅馆位置 
*/

void read()
{
	freopen("hotel.in","r",stdin);
	freopen("hotel.out","w",stdout);
	scanf("%d%d%d",&n,&k,&p);
}
int main()
{
	read();
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&color,&cost);
		if(cost<=p)
			for(int j=0;j<k;++j)
				nowh[j]+=newh[j],newh[j]=0;
		ans+=nowh[color];
//		printf("%d色房子为答案贡献%d\n",color,nowh[color]);		
		if(cost<=p)nowh[color]++;
		else newh[color]++;
	}
	printf("%lld",ans);
	return 0;
}