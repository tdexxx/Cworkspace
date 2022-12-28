#include <iostream>
using namespace std;

int main()
{
    float f1 = 3.1415926f;
    cout << "f1=" << f1 << endl;
    double d1 = 3.1415926;
    cout << "d1=" << d1 << endl;
    cout << "float  占用内存空间为：" << sizeof(float) << endl;
    cout << "double 占用内存空间为：" << sizeof(double) << endl;
    // 科学计数法
    float f2 = 3e2;
    float f3 = 3e-2;
    cout << "f2=" << f2 << endl;
    cout << "f3=" << f3 << endl;
    system("pause");

    return 0;
}