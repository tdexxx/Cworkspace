//编写函数，重复打印给定字符n次，n由输入数字确定
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	char a;//单个字符 
	int time;//次数 
	cout<<"please input a char and the times:"<<endl;
	cin>>a>>time;
	vector<char>v;
	for(;time>0;--time)
	{
		v.push_back(a);//压入time个字符 
	}
	for(vector<char>::size_type t= 0;t<v.size();++t)
	{
		cout<<v[t];//输出time个字符 
	}
    system("pause");
	return 0;
}