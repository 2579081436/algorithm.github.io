#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAX=100;
string X="BCAD",Y="BAC";
int C[MAX][MAX];
int B[MAX][MAX];
string str="";
void LCS(string X,int x_len,string Y,int y_len){
	if(x_len==0||y_len==0) return ;
	for(int i=0;i<=x_len;i++){
		C[i][0]=0;
	}
	for(int j=0;j<=y_len;j++){
		C[0][j]=0;
	}
	for(int i=1;i<=x_len;i++){
		for(int j=1;j<=y_len;j++){
			if(X[i-1]==Y[j-1]){
				C[i][j]=C[i-1][j-1]+1;
				B[i][j]=2;
			}
			else{
				C[i][j]=max(C[i][j-1],C[i-1][j]);
				if(C[i][j]==C[i][j-1]) B[i][j]=1;
				else B[i][j]=0;
			}
		}
	}	
}
void find(int i,int j){
	if(i==0||j==0) return ;
	if(B[i][j]==0) find(i-1,j);
	else if(B[i][j]==1) find(i,j-1);
	else if(B[i][j]==2){
		str=str+X[i-1];
	 	find(i-1,j-1);
	}
}
int main(){
	LCS(X,4,Y,3);
	find(4,3);
	reverse(str.begin(), str.end());
	cout<<str; 
	return 0;
} 
