#include<iostream>
using namespace std;
const int MAX=1000;
int dp[MAX][MAX];
int max(int a,int b){
	if(a>=b) return a;
	else return b;
}
struct good{
	int w;//���� 
	int v;//��ֵ 
}thing[MAX]; 
int main(){
	int s,n;//s�Ǳ���������n����Ʒ����
	cin>>s>>n;
	for(int i=1;i<=n;i++){
		cin>>thing[i].w>>thing[i].v; //����ÿ����Ʒ�������ͼ�ֵ
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			if(j<thing[i].w) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j - thing[i].w] + thing[i].v); 
		}
	}
	
	cout<<"����ֵ�ǣ�"<<dp[n][s];
	return 0;
} 

