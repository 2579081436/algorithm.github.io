#include<stdio.h>
const int INF = 0x3f3f3f3f;
const int MAX = 1000;
int n, m;//n是点数，m是边数
int v, u, w;//v是起点，u是终点，w是边长
int visited[MAX];//标记是否已是最小路径
int dis[MAX];//记录最小路径
int we[MAX][MAX];//记录边长
void Init() {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;//初始时各点都未访问，最小路径尚未确定
		dis[i] = INF;//路径初始化无穷大
	}
}
void Dijkstra() {
	dis[1] = 0;
	int min_length;
	int k;//k是当前的中间点
	for (int i = 1; i <= n; i++) {
		min_length = INF;
		for (int j = 1; j <= n; j++) {
			if (visited[j] == false && dis[j] < min_length) {//某点到起点最小路径未确定且是当前未确定的最小路径时
				min_length = dis[j];
				k = j;
			}
		}
		visited[k] = true;//更新
		for (int j = 1; j <= n; j++) {
			if (we[k][j]!=0 && visited[j] == false && dis[j] > dis[k] + we[k][j])
				dis[j] = dis[k] + we[k][j];
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	Init();
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &v, &u, &w);
		we[v][u] = w;
	}
	Dijkstra();
	for (int i = 1; i <= n; i++) {
		printf("a - >%c的最短路径是：%d\n", i+96, dis[i]);
	}
	return 0;
}
