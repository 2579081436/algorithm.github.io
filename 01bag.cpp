#include<iostream>
using namespace std;
const int MAX=100;
int v[MAX];//��Ʒ��ֵ 
int w[MAX];//��Ʒ���� 
int x[MAX]={0};//0-δװ��1-��װ 
int n;//��Ʒ���� 
int m;//��������
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
			cout<<"��ֵΪ"<<v[i]<<"����Ϊ"<<w[i]<<"����Ʒװ�뱳��"<<endl;
			m-=w[i];
			total_w+=w[i];
			total_v+=v[i];
			total_n++;
			x[i]=1;
		}
	}
	cout<<"�ñ���������"<<total_n<<"����Ʒ,�ܼ�ֵΪ"<<total_v<<",������Ϊ"<<total_w<<endl;
	
	return 0;
} 
