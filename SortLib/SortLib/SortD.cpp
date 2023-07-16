#include <iostream>
extern "C" __declspec(dllexport) void SortD(int *mas, int m) 
{
    int i, a, n;
    n = 1;
    while (n)
    {
        n = 0;
        for (i = 0; i < m; i++)
        {
            if (mas[i] < mas[i + 1])
            {
                n = 1;
                a = mas[i + 1]; mas[i + 1] = mas[i];
                mas[i] = a;
            }
        }
    }
}