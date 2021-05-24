#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAX=1000;
const int n=8;//{5,5,10,10,10,15,20,25}
const int m=2*n-1;//�ڵ����� 
typedef struct{
	int weight;//Ȩֵ 
	int parent,lchild,rchild;//���ڵ㡢���ӡ��Һ��� 
}Node;
typedef struct{
	int id;
	int weight;
}temp;
typedef Node HuffmanTree[MAX];

typedef struct{
    char bits[n+1];//��ű���λ��
}CodeNode;
typedef CodeNode HuffmanCode[MAX];

//��ʼ�� 
void InitTree(HuffmanTree T){
	for(int i=0;i<m;i++){
		T[i].weight=0;
		T[i].parent=-1;
		T[i].lchild=-1;
		T[i].rchild=-1;
	}
}
bool cmp(temp a,temp b){
	return a.weight<b.weight;
}
//ѡ����С�ʹ�С����¼��ź�Ȩֵ 
void select(HuffmanTree T,int k,int *p1,int *p2){
	temp x[MAX];
	int i,j;
	for(i=0,j=0;i<=k;i++){
		if(T[i].parent==-1){
			x[j].id=i;
			x[j].weight=T[i].weight;
			j++;
		}
	}
	sort(x,x+j,cmp);
	*p1=x[0].id;
	*p2=x[1].id;
}
void CreateHuffmanTree(HuffmanTree T){
	int p1,p2;
	InitTree(T);
	T[0].weight=5;
	T[1].weight=5;
	T[2].weight=10;
	T[3].weight=10;
	T[4].weight=10;
	T[5].weight=15;
	T[6].weight=20;
	T[7].weight=25;
	
	for(int i=n;i<m;i++){
		select(T,i-1,&p1,&p2);
		T[p1].parent=T[p2].parent=i;
		T[i].lchild=p1;
		T[i].rchild=p2;
		T[i].weight=T[p1].weight+T[p2].weight;
	}
}

//���ݹ�������T������������H
void CharSetHuffmanEncoding(HuffmanTree T,HuffmanCode H){
    int c,p;//c��p�ֱ���T�к��Ӻ�˫�׵�λ��
    char cd[n+1];//��ʱ��ű���
    int start;//ָʾ������cd�е���ʼλ��
    cd[n]='\0';//���������
    
    
    for(int i=0;i<n;i++){
        start=n;
        c=i;
        while((p=T[c].parent)>=0){
            if(T[p].lchild==c)
                cd[--start]='0';
            else
                cd[--start]='1';
            c=p;
        }
        strcpy(H[i].bits,&cd[start]);//���Ʊ���λ��
    }
}
int main(){
	HuffmanTree T;
	CreateHuffmanTree(T);
	HuffmanCode H;
	CharSetHuffmanEncoding(T,H);
	int wpl=0;
	for(int i=0;i<n;i++){
		//cout<<"id:"<<i<<"	weight:"<<T[i].weight<<endl;
		cout<<T[i].weight<<":"<<H[i].bits<<endl;
		wpl+=strlen(H[i].bits)*T[i].weight;
	} 
	cout<<"ƽ��:"<<wpl*1.0/100; 
	return 0;
} 
