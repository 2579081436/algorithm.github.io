#include<stdio.h>
#include<memory.h>
const int MAXN = 1000;
const int INF = 0x3f3f3f3f;
int n, m;
int w[MAXN][MAXN], d[MAXN], visited[MAXN];
int fa[MAXN];
void Init() {
	memset(visited, 0, sizeof(visited));
	memset(fa, -1, sizeof(fa));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) w[i][j] = 0;
			else w[i][j] = INF;
		}
	}
}
void Prim() {
	for (int i = 1; i <= n; i++) {
		if (w[1][i] != INF) fa[i] = 1;
		d[i] = w[1][i];
	}
	while (1) {
		int min = INF;
		int k = -1;
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && d[i] < min) {
				min = d[i];
				k = i;
			}
		}
		if (k == -1) break;
		visited[k] = 1;
		for (int i = 1; i <= n;i++) {
			if (!visited[i] && d[i] > w[k][i]) {
				d[i] = w[k][i];
				fa[i] = k;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (fa[i] == -1) printf("不存在最小生成树\n");
		else  ans += d[i];	
	}
	printf("最小生成树的权值为:%d\n", ans);
}
void Find() {
	for (int i = 1; i <= n; i++) {
		if (fa[i] != -1 && fa[i] == i) printf("从%d出发\n", i);
		else if (fa[i] != -1) printf("%d --> %d 长度为%d\n", fa[i], i,d[fa[i],i]);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	int u, v, we;
	Init();
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &u, &v, &we);
		w[u][v] = w[v][u] = we;
	}
	Prim();
	Find();
}
