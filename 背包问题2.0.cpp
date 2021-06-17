#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int w[300],c[300],f[300010];//w[i]是第i种物品的价值，
//c[i]是第i种物品的重量，f[i]是袋子容量为i时装下的物品最大价值 
int V,N;//V是袋子最大容量，N是物品种数 
int main(){
    scanf("%d%d",&V,&N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d",&w[i],&c[i]);
    }
    for(int i=1; i<=N; i++)
        for(int j=w[i]; j<=V; j++)
            f[j]=max(f[j],f[j-w[i]]+c[i]);

	printf("max=%d\n",f[V]);
    return 0;
}
