#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int w[300],c[300],f[300010];//w[i]�ǵ�i����Ʒ�ļ�ֵ��
//c[i]�ǵ�i����Ʒ��������f[i]�Ǵ�������Ϊiʱװ�µ���Ʒ����ֵ 
int V,N;//V�Ǵ������������N����Ʒ���� 
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
