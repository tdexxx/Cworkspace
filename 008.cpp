#include <iostream>
using namespace std;
#include <string>

int main()
{
    //创建bool数据类型
    bool flag = true;//true代表真
    cout << flag << endl;
    flag = false;//false为假
    cout << flag << endl;
    //本质上 1代表真 0 代表假
    //查看bool类型所占内存空间
    cout << "输出bool类型所占内存空间：" << sizeof(bool) << endl;
    system("pause");

    return 0;
}