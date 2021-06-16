#include<iostream>
using namespace std;

const int MAX=1000;
int n;//������ 
int m;//��ɫ��
int c[MAX][MAX];//�ڽӾ���0��1��ʾ����֮���Ƿ���ͨ
int color[MAX];//��ʼֵ0,1-m������ɫ 
bool OK(int k){
	for(int i=1;i<k;i++){
		if(c[k][i]==1 && color[i]==color[k])
			return false;//���������������ɫ��ͬ������FALSE 
	}
	return true;
}
void FillColor(){
	int flag=0;
	for(int i=1;i<=n;i++)
		color[i]=0;//��ʼ�� 
	int k=1;
	while(k>=1){
		color[k]=color[k]+1;
		while(color[k]<=m){
			if(OK(k)) break;
			else color[k]=color[k]+1;			
		}
		if(color[k]<=m&&k==n){
			for(int i=1;i<=n;i++){
				cout<<color[i]<<" ";//��� 
			}
			cout<<endl;
			flag=1;//��ʾ����Ϳɫ���� 
		}
		else if(color[k]<=m&&k<n){
			k++;//�������� 
		}
		else{
			color[k]=0;
			k=k-1;//���� 
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
			cin>>c[i][j];//��¼����֮���Ƿ����� 
		}
	}
	cout<<"��ɫ���ܣ�"<<endl; 
	FillColor(); 
	return 0;
} 
