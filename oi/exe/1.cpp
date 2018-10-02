#define _CRT_SECURE_NO_DEPRECATE
/************************
*创建时间：2018 08 30
*文件类型：源代码文件
*题目来源：
*当前状态：
*备忘录：
*作者：HtBest
************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
// #include <sys/wait.h>
// #include <sys/types.h>
// #include <unistd.h>
using namespace std;
namespace IO 
{
	#define SIZE 1
	char s[SIZE+1];
	int T=0,end=0;
	int in()
	{
		T=0;
		return end=fread(s,1,SIZE,stdin);
	}
	int read(int &a)
	{
		int i=a=0,flag=1;
		while(1)
		{
			if(T==end&&!in())return i;
			if(s[T]=='\r'||s[T]=='\n'||s[T]==' ')
			{
				if(i)return i;
			}
			else if(s[T]=='-')flag=-1;
			else ++i,a=flag*(flag*a*10+s[T]-'0');
			++T;
		}
	}
	int get_word(char a[])
	{
		int i=0;
		while(1)
		{
			if(T==end&&!in()){a[i]=0;return i;}
			a[i++]=s[T];
			
			++T;
		}
	}
	int read(char a[])
	{
		int i=0;
		while(1)
		{
			if(T==end&&!in())return i;
			if(s[T]=='\r'||s[T]=='\n'||s[T]=='	'||s[T]==27)
			{
				if(i)return i;
			}
			else if(s[T]!=' '||i)
			{
				a[i++]=s[T];
				a[i]=0;
			}
			++T;
		}
	}
}
using IO::read;
using IO::get_word;
struct PAGES 
{
	char real_file[100],show_file[100];
	int _r,_s;
}page[10000];
struct Char 
{
	char a[100000];
	int flag;
	char operator [] (int x) const
	{
		return a[x];
	}
	Char(string x="")
	{
		int len=x.length();
		for(int i=0;i<len;++i)a[i]=x[i];
		flag=0;
	}
}s;
bool operator == (Char &a,Char &b) 
{
	int len=strlen(b.a),T=0;
	while(len--)
	{
		if(a[a.flag+T]!=b[T])return false;
		++T;
	}
	return true;
}
int _page;
/* Variable explain:

*/
void read()
{
	get_word(s.a);
	return;
}
void print()
{
	for(int i=_page;i;--i)
	{
		printf("&ensp;&ensp;&ensp;&ensp;\n<a href=\"%s\">\n",page[i].show_file);
		printf("	<iframe src=\"%s\" frameborder=\"0\" name=\"iframe_a\" width=\"40%c\" height=\"20%c\"></iframe>\n",page[i].real_file,'%','%');
		printf("	<<查看详情\n</a>\n\n");
		if(i==1||((_page-i)&1))puts("<hr/>\n");
	}
}
void format()
{
	Char key1,key2;
	key1=Char("<a href=");
	key2=Char("<iframe src=");
	int &T=s.flag,f1,f2;
	while(s[T])
	{
		if(f1==1&&f2&&s[T]!='\"')//预读1，且开启读入通道
		{
			page[_page].show_file[page[_page]._r++]=s[T];
		}
		if(f1==3&&f2&&s[T]!='\"')//预读2，且开启预读通道
		{
			page[_page].real_file[page[_page]._s++]=s[T];
		}
		if((f1==1||f1==3)&&s[T]=='\"')
		{
			if(f1==1&&f2)f1=2;//进入休眠
			if(f1==3&&f2)f1=4;//进入下一轮
			f2^=1;
		}
		if(s==key1)//进入预读1模式
			++_page,f1=1;
		if(s==key2)//进入预读2模式
			f1=3;
		++T;
	}
	for(int i=1;i<=_page>>1;++i)
	{
		swap(page[i],page[_page-i+1]);
	}
}
int main()
{
	int start;
	char ls1[1000],ls2[1000];
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	printf("正在读入源代码文件\n");
	read();
	printf("读入完毕\n");
	// Char ls1;
	// ls1.a[0]=ls1.a[1]=s.a[0]=s.a[1]=s.a[2]='h';
	// ls1.a[2]=s.a[3]=0;
	// ls1.flag=s.flag=0;
	// printf("%d %d",ls1==s,s==ls1);
	format();
	freopen("/dev/tty","r",stdin);
	printf("请输入第一个文件的序号：");
	scanf("%d",&start);
	puts("请输入文件名：");
	while(1)
	{
		read(ls1);
		if(ls1==(string)"end")break;
		
		sprintf(page[++_page].real_file,"./%05d/index.pdf",start);
		sprintf(page[_page].show_file,"./%05d/show.html",start);
		sprintf(ls2,"mkdir %05d",start);
		system(ls2);
		sprintf(ls2,"cp %s ./%05d/index.pdf",ls1,start);
		system(ls2);
		sprintf(ls2,"cp show.html ./%05d/show.html",start++);
		system(ls2);
	}
	print();
	printf("%d\n",_page);
	return 0;
}


/*

&ensp;&ensp;&ensp;&ensp;
<a href="./00005/show.html">
	<iframe src="./00005/index.pdf" frameborder="0" name="iframe_a" width="40%" height="20%"></iframe>
	<<查看详情
</a>
&ensp;&ensp;&ensp;&ensp;
<a href="00002/show.html">
	<iframe src="00002/index.html" frameborder="0" name="iframe_a" width="40%" height="20%"></iframe>
	<<查看详情
</a>
<hr/>

*/