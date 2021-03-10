//#include<bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1000;
int n, m;
struct graph
{
    int u, v, cost;
};
graph d[maxn];

int cmp(graph x, graph y) {
    if (x.cost < y.cost) return 1;
    return 0;
}
int fa[maxn];
int findfa(int a)
{
    if (fa[a] != a) fa[a] = findfa(fa[a]);
    return fa[a];
}//寻找祖宗节点

void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}

int unionn(int a, int b)
{
    int faa = findfa(a);
    int fab = findfa(b);
    if (faa != fab) {
        fa[faa] = fab;
        return 1;
    }
    return 0;
}//联通两个节点的祖宗节点

void kruskal() {
    sort(d, d + m, cmp);
    int count = n;
    int ans = 0;
    for (int i = 0; i < m && count>1; i++) {
        if (unionn(d[i].u, d[i].v)) {
            printf("%d --> %d 长度为%d\n", d[i].u, d[i].v, d[i].cost);
            ans += d[i].cost;
            count--;
        }
    }
    if (count == 1)
        printf("最小生成树的权值和为%d\n", ans);
    else
        printf("不存在最小生成树\n");
}
int main()
{
    scanf("%d %d", &n, &m);
    init();
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &d[i].u, &d[i].v, &d[i].cost);
    }
    kruskal();
}