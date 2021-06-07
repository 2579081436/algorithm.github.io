#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

const int MAX=2000;
int dp[MAX][MAX];
string s1,s2;

int min(int a,int b,int c){
	if(a<=b&&a<=c) return a;
	else if(b<=a&&b<=c) return b;
	else if(c<=a&&c<=b) return c;
}

int oper(){
	int len1=s1.length();
	int len2=s2.length();
	for(int j=0;j<=len2;j++){
		dp[0][j]=j;
	}
	for(int i=1;i<=len1;i++){
		dp[i][0]=i;
	}
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
		}
	}
	return dp[len1][len2];
}
int main(){
	cout<<"输入源串："<<endl; 
	cin>>s1;
	cout<<"输入目标串："<<endl;
	cin>>s2;
	cout<<"最小操作次数是："<< oper()<<endl;
} 
