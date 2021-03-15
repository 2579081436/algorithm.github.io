#include<stdio.h>
const int INF = 0x3f3f3f3f;
const int MAX = 1000;
int n, m;//n�ǵ�����m�Ǳ���
int v, u, w;//v����㣬u���յ㣬w�Ǳ߳�
int visited[MAX];//����Ƿ�������С·��
int dis[MAX];//��¼��С·��
int we[MAX][MAX];//��¼�߳�
void Init() {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;//��ʼʱ���㶼δ���ʣ���С·����δȷ��
		dis[i] = INF;//·����ʼ�������
	}
}
void Dijkstra() {
	dis[1] = 0;
	int min_length;
	int k;//k�ǵ�ǰ���м��
	for (int i = 1; i <= n; i++) {
		min_length = INF;
		for (int j = 1; j <= n; j++) {
			if (visited[j] == false && dis[j] < min_length) {//ĳ�㵽�����С·��δȷ�����ǵ�ǰδȷ������С·��ʱ
				min_length = dis[j];
				k = j;
			}
		}
		visited[k] = true;//����
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
		printf("a - >%c�����·���ǣ�%d\n", i+96, dis[i]);
	}
	return 0;
}
