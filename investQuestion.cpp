#include<iostream>
#include<vector>

using namespace std;

int main() {

	int m, n;	//m��Ͷ�����Ǯ����n��Ͷ�����Ŀ��
	int k, x;
	int xk, Tp = 0;	//xk�������k����ĿͶ���Ǯ��  0<=tmp<=j;temp����һ��ѭ���е�Ǯ��
	cout << "Ͷ�����Ǯ����Ͷ�����Ŀ����";
	cin >> m >> n;
	vector<vector<int>> f(n, vector<int>(m + 1));	//f[i][x], 0<i<=n,0<=x<=m,��i����ĿͶ��x��ԪǮʱ������
	vector<vector<int>> F(n, vector<int>(m + 1));	//F[i][x]����x��ԪǮͶ�뵽ǰi����Ŀ����������
	
	for (k = 0; k < n; ++k) {
		f[k][0] = 0;	//ÿ����ĿͶ��0Ԫʱ������Ϊ0Ԫ
	}
	for (k = 0; k < n; ++k) {
		for (x = 1; x < m + 1; ++x) {
			cin >> f[k][x];
		}
	}
	
	for (x = 0; x < m + 1; ++x) {
		F[0][x] = f[0][x];	//��һ����Ŀ��Ͷ��0-m��ԪǮ������������f[0][0-m]
	}
	for (k = 1; k < n; ++k) {				//�� k����Ŀ
		for (x = 0; x < m + 1; ++x) {		//k����Ŀ������x��Ԫ
			for (xk = 0; xk <= x; ++xk) {	//��k����Ŀ����xk��Ԫ
				Tp = F[k - 1][x - xk] + f[k][xk];
				if (Tp > F[k][x])
					F[k][x] = Tp;
			}
		}
	}
	cout << "������棺" << F[n - 1][m] << endl;
}
