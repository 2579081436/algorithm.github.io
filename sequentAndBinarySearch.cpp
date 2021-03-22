#include<stdio.h>
const int N = 105;
int T[N];		//数据存在在T数组
int flag = 0;	//flag=0代表没找到，flag=1代表找到
int x;
void Init() {
	for (int i = 1; i <= 100; i++) {
		T[i] = i;//初始化数据，升序
	}
	for (int i = 1; i <= 100; i++) {
		printf("%4d", T[i]);
		if (i % 10 == 0) printf("\n");
	}
}
void SequentialSearch() {	//顺序查找
	for (int i = 1; i <= 100; i++) {
		if (T[i] == x) {
			printf("j=%d\n", i);
			flag = 1;
		}
	}
	if (flag == 0) printf("j=0\n");
}
void BinarySearch() {	//二分查找
	int left = 1, right = 100;
	int mid;
	while (left <= 100 && right > 0 && left <= right) {
		mid = (left + right)/2;
		if (T[mid] > x) right = mid - 1;		//若x在mid左边，更新right=mid-1
		else if (T[mid] < x) left = mid + 1;	//若x在mid右边，更新left=mid+1
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
