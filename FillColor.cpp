#include<iostream>
using namespace std;

const int MAX=1000;
int n;//顶点数 
int m;//颜色数
int c[MAX][MAX];//邻接矩阵，0、1表示两点之间是否连通
int color[MAX];//初始值0,1-m代表颜色 
bool OK(int k){
	for(int i=1;i<k;i++){
		if(c[k][i]==1 && color[i]==color[k])
			return false;//如果两点相邻且颜色相同，返回FALSE 
	}
	return true;
}
void FillColor(){
	int flag=0;
	for(int i=1;i<=n;i++)
		color[i]=0;//初始化 
	int k=1;
	while(k>=1){
		color[k]=color[k]+1;
		while(color[k]<=m){
			if(OK(k)) break;
			else color[k]=color[k]+1;			
		}
		if(color[k]<=m&&k==n){
			for(int i=1;i<=n;i++){
				cout<<color[i]<<" ";//输出 
			}
			cout<<endl;
			flag=1;//表示存在涂色方法 
		}
		else if(color[k]<=m&&k<n){
			k++;//继续向下 
		}
		else{
			color[k]=0;
			k=k-1;//回溯 
		}
	}
	if(flag==0){
		cout<<"NO"<<endl;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];//记录顶点之间是否相邻 
		}
	}
	cout<<"填色可能："<<endl; 
	FillColor(); 
	return 0;
} 
