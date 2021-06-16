#include<iostream>
using namespace std;
#define maxvalue 1000000
void MatrixChain(int p[], int len, int** m, int** s)
{
	int n = len - 1;
	for (int i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}
	for (int L = 2; L <= n; L++)
	{
		for (int i = 1; i <= n - L + 1; i++)
		{
			int j = i + L - 1;
			m[i][j] = maxvalue;
			for (int k = i; k < j; k++)
			{
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void printChain(int** s, int i, int j)
{
	if (i == j)
	{
		cout << "A" << i;
	}
	else
	{
		cout << "(";
		printChain(s, i, s[i][j]);
		printChain(s, s[i][j] + 1, j);
		cout << ")";
	}
}


int main()
{

	int p[] = { 30,35,15,5,10,20 };
	int len = sizeof(p) / sizeof(int);
	cout << len << endl;
	int** m, ** s;
	m = new int* [len];
	s = new int* [len];
	for (int i = 1; i < len; i++)
	{
		m[i] = new int[len];
		s[i] = new int[len];
	}
	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j < len; j++)
		{
			m[i][j] = 0;
			s[i][j] = 0;
		}
	}
	MatrixChain(p, len, m, s);
	printChain(s, 1, 5);

}

