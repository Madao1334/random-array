#include<iostream>
#include<time.h>
using namespace std;
bool check_number(int*arr,int s,int m)             //проверка:"Есть ли число n в первых m элементах массива" 
{
	for (int i=0; i < m; i++)
	{
		if (arr[i] == s)
			return true;
	}
	return false;
}
void transposition(int m, int n, int* arr)        // транспозиция элементов в массиве
{
	int s=arr[m];
	int t = arr[n];
	arr[m] = t;
	arr[n] = s;
}
void trans_min(int* arr, int n, int m)       //перестановка с минимальными элементом в массиве которая начинается с m-го элемента
{
	int s = 1000000;
	int s_1 = 0;
	int i = m;
	for (i; i < n; i++)
	{
		if (arr[i] < s)
		{
			s = arr[i];
			s_1 = i;
		}
	}
	transposition(m, s_1, arr);
}    // транспозиция минимального элемента
void sort(int* arr,int n)                                 //Сортировка массива
{
	for (int i = 0; i < n; i++)
	{
	     trans_min(arr, n, i);
	}
}
void inverse_array(int* arr, int n)       //переворачивание массива (для сортировки по убыванию)
{
	int s = n/2;
	for (int i = 0; i < s; i++)
	{
		transposition(i, n - 1 - i, arr);
	}
}
int** genetaion_random_array(int n)          //функция задачи 
{
	srand(time(NULL));
	int** M;
	M = new int*[n];
	int* L = new int[n];
	int bound = 0;                                 
	for (int i = 0; i < n; i++)
	{
		do
		{
			L[i] = rand() % 20+ 1;
			bound++;
		} while (check_number(L, L[i], i) == true and bound<1000000);
	}
	cout << "LLL=" << " ";
	for (int i = 0; i < n; i++)
	{
		cout << L[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		M[i] = new int[L[i]];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < L[i]; j++)
		{
			M[i][j] = rand()%1000;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i% 2 == 0)
		{
			sort(M[i],L[i]);
		}
		else
		{
			sort(M[i], L[i]);
			inverse_array(M[i], L[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < L[i]; j++)
		{
			cout << M[i][j] << " ";
		}
		cout << "\n";
	}
	return M;
}
int main()
{
	int** M = genetaion_random_array(15);
	getchar;
	return 0;
}
