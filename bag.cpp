#include<iostream>
using namespace std;
const int MAX=1000;
int dp[MAX][MAX];
int max(int a,int b){
	if(a>=b) return a;
	else return b;
}
struct good{
	int w;//重量 
	int v;//价值 
}thing[MAX]; 
int main(){
	int s,n;//s是背包容量，n是物品数量
	cin>>s>>n;
	for(int i=1;i<=n;i++){
		cin>>thing[i].w>>thing[i].v; //读入每个物品的重量和价值
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
	
	cout<<"最大价值是："<<dp[n][s];
	return 0;
} 

