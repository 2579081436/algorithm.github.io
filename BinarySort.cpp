#include<stdio.h>
const int N = 8;	//n=2^k
int A[N] = {1,5,2,6,3,7,4,8};
int B[N];

//归并
void Merge(int left, int mid, int right) {
	int i = left, j = mid + 1;
	int k = left;

	//在A(left,mid)和A(mid+1,right)两部分中取较小数加到B数组中，下标+1
	while (i <= mid && j <= right) {
		if (A[i] <= A[j]) B[k++] = A[i++];
		else B[k++] = A[j++];
	}
	//若A(left,mid)中还有元素剩余，则依次加到B数组中，下标+1
	while (i <= mid) {
		B[k++] = A[i++];
	}
	//若A(mid+1，right)中还有元素剩余，则依次加到B数组中，下标+1
	while (j <= right) {
		B[k++] = A[j++];
	}
	//B数组整体赋值给A数组
	for (int x = left; x <= right; x++)
		A[x] = B[x];
}

//二分
void Binary(int left,int right) {
	int mid = (left + right) / 2;	//mid取left、right中
	if (left < right) {
		Binary(left, mid);		//左半部分一直递归
		Binary(mid + 1, right);	//右半部分一直递归
		Merge(left,mid,right);	//归并左右部分
	}
}
int main() {
	Binary(0, N - 1);
	for (int i = 0; i < N; i++)
		printf("%4d", A[i]);
	return 0;
}