#include<stdio.h>
const int N = 105;
int T[N];		//���ݴ�����T����
int flag = 0;	//flag=0����û�ҵ���flag=1�����ҵ�
int x;
void Init() {
	for (int i = 1; i <= 100; i++) {
		T[i] = i;//��ʼ�����ݣ�����
	}
	for (int i = 1; i <= 100; i++) {
		printf("%4d", T[i]);
		if (i % 10 == 0) printf("\n");
	}
}
void SequentialSearch() {	//˳�����
	for (int i = 1; i <= 100; i++) {
		if (T[i] == x) {
			printf("j=%d\n", i);
			flag = 1;
		}
	}
	if (flag == 0) printf("j=0\n");
}
void BinarySearch() {	//���ֲ���
	int left = 1, right = 100;
	int mid;
	while (left <= 100 && right > 0 && left <= right) {
		mid = (left + right)/2;
		if (T[mid] > x) right = mid - 1;		//��x��mid��ߣ�����right=mid-1
		else if (T[mid] < x) left = mid + 1;	//��x��mid�ұߣ�����left=mid+1
		else {
			printf("j=%d\n", mid);
			flag = 1;
			break;
		}
	}
	if (flag == 0) printf("j=0\n");
}
int main() {
	Init();
	scanf("%d", &x);
	SequentialSearch();
	BinarySearch();
}
