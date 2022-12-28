#include <stdio.h>
#include <windows.h>
int main()
{
    unsigned int a = 0, b = 0, c = 0, m = 0;
    scanf("%u %u %u", &a, &b, &c);
    if (a > b)
    {
        if (a > c)
            m = a;
        else
            m = c;
    }
    else if (c > b)
        m = c;
    else
        m = b;
    printf("%d", m);
    system("pause");
    return 0;
}