#include <stdio.h>  //io头文件用于调用 printf函数
#include <stdlib.h>   //lib头文件用于调用system函数

//主函数
int main()
{
  
  printf("hello world\n");  //打印hello world   \n为换行符
  system("pause");  //暂停运行，否则直接运行完程序会直接关闭窗口（vscode需要，其他编译器看情况） 
}
