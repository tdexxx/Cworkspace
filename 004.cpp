#include <iostream>
using namespace std;

int main()
{
    short num1 = 10;
    cout << "short占用内存空间为：" << sizeof(num1) << endl;
    cout << "int占用内存空间为：" << sizeof(int) << endl;
    cout << "long占用内存空间为：" << sizeof(long) << endl;
    cout << "long long占用内存空间为：" << sizeof(long long) << endl;
    system("pause");

    return 0;
}