#define _CRT_SECURE_NO_DEPRECATE
/************************
*创建时间：2018 03 08
*文件类型：工程文件
*采用算法：
*作者：HtBest
*备忘：
 ************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
// #include <queue>
// #include <map>
// #include <set>
// #include <vector>
// #include <ctype.h>
// #include <math.h>
// #include <bits/stdc++.h>
using namespace std;
string Path_name,option,fn;
int n;
/* Variable explain:

*/
int main()
{
	while(1)
	{
		cin>>option;
		if(option=="end")return 0;
		if(option=="add")
		{
			printf("target path name:");
			cin>>Path_name;
	//		printf("file name:");
	//		cin>>fn;
			Path_name=Path_name+"/index.html";
	//		freopen(fn.c_str(),"r",stdin);
			freopen(Path_name.c_str(),"w",stdout);
			printf("<html>\n	<body background=\"transparent\">\n		<head>\n			<font size=2>\n				<p align=\"right\">\n					更新日期：2018/03/07\n				</p>\n			</font>\n		</head>\n");

			printf("		<!-- Code -->\n	</body>\n</html>");
			return 0;
		}
	}
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);


	return 0;
}
