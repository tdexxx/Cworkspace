#include <iostream>
using namespace std;

int main()
{
    char ch = 'b';
    cout << ch << endl;
    cout << "char字符型变量所占内存： " << sizeof(char) << endl;
    // 字符型变量对应ASCII编码 a-97 A-65
    cout << (int)ch << endl;
    // 换行符 \n
    cout << "hello world\n";
    //反斜杠 \\0
    cout << "\\" <<endl;
    // 水平制表符 \t 作为可以整齐输出数据
    cout << "aaaa\thelloworld" << endl;
    cout << "aa\thelloworld" << endl;
    cout << "aaaaaa\thelloworld" << endl;
    cout << "\tHello" << endl;
    system("pause");
    return 0;
}