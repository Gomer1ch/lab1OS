#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	HINSTANCE load = LoadLibrary(L"SortLib.dll");
	typedef int (*sort) (int*, int);
	if (load == NULL)
	{
		cout << "Can't load dll\n";
		cin.get();
		return 0;
	}
	sort SortD;

	SortD = (sort)GetProcAddress(load, "SortD");
	if (SortD == NULL)
	{
		cout << "Can't load function" << endl;
		FreeLibrary(load);
		return 0;
	}
    int mas[10];
    int i, a, n;
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        mas[i] = rand() % 41 - 20;
        printf(" %d ", mas[i]);
    }
	printf("\n");
    SortD(mas,10);
	for (int i = 0; i < 10; i++)
		printf(" %d ", mas[i]);
	printf("\n");
	FreeLibrary(load);
}
