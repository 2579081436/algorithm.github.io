#include<stdio.h>
const int INF = 0x3f3f3f3f;
const int MAX = 100;
int d[MAX][MAX];//��¼�߳��͸��º����С·��
int n, m;//n�ǵ�����m�Ǳ���
int v, u, w;//v����㣬u���յ㣬w�Ǳ߳�
void Init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) d[i][j] = 0;//�Խ���Ԫ�ش����Լ��ľ��룬Ϊ0
			else d[i][j] = INF;//�����������ʼ��Ϊ�����
		}
	}
}
void Floyd() {
	for (int k = 1; k <= n; k++) {//k���м��
		for (int i = 1; i <= n; i++) {//i�����
			for (int j = 1; j <= n; j++) {//j���յ�
				if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	Init();
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &v, &u, &w);
		d[v][u] = w;
	}
	Floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%-4d", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}
