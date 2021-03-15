#include<stdio.h>
const int INF = 0x3f3f3f3f;
const int MAX = 100;
int d[MAX][MAX];//记录边长和更新后的最小路径
int n, m;//n是点数，m是边数
int v, u, w;//v是起点，u是终点，w是边长
void Init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) d[i][j] = 0;//对角线元素代表到自己的距离，为0
			else d[i][j] = INF;//到其余点距离初始化为无穷大
		}
	}
}
void Floyd() {
	for (int k = 1; k <= n; k++) {//k是中间点
		for (int i = 1; i <= n; i++) {//i是起点
			for (int j = 1; j <= n; j++) {//j是终点
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
