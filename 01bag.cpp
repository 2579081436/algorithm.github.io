#include<iostream>
using namespace std;
const int MAX=100;
int v[MAX];//物品价值 
int w[MAX];//物品重量 
int x[MAX]={0};//0-未装，1-已装 
int n;//物品数量 
int m;//背包容量
int total_w=0;
int total_v=0;
int total_n=0;
int sorting(int x[],int v[],int w[],int m,int n){
	double a[MAX];
	for(int i=0;i<n;i++){
		a[i]=v[i]*1.0/w[i];
	}
	int t=n-1;
	int kk,k,t1,t2;
	while (t > 0){
        kk = 0;
        for (int j = 0; j < t; j++){		
            if (a[j] < a[j + 1]){
                t1 = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t1;
                
                t2 = w[j];
                w[j] = w[j + 1];
                w[j + 1] = t2;
                kk = j;
            }
		}
        t = kk;
    }
} 
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>v[i]>>w[i];
	}
	sorting(x,v,w,m,n); 
	for(int i=0;i<n;i++){
		if(w[i]<=m){
			cout<<"价值为"<<v[i]<<"重量为"<<w[i]<<"的物品装入背包"<<endl;
			m-=w[i];
			total_w+=w[i];
			total_v+=v[i];
			total_n++;
			x[i]=1;
		}
	}
	cout<<"该背包共放入"<<total_n<<"个物品,总价值为"<<total_v<<",总重量为"<<total_w<<endl;
	
	return 0;
} 
