#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int GetPivotIndex(int A[], int left, int right);
void InsertionSort(int A[], int left, int right);
int Partition(int A[], int left, int right, int pivot_index);
void swap(int A[], int a, int b);
int Select(int k, int A[], int left, int right);
//������λ��,Ѱ����λ���е���λ��
int GetPivotIndex(int A[], int left, int right) {
    int i;
    //����5��Ԫ�صķ�Ϊһ��
    if (right - left < 5) {
        InsertionSort(A, left, right);
        return (left + right) / 2;
    }

    int sub_right = left - 1;

    //ÿ5��Ԫ�ط�Ϊһ��
    for (i = left; i + 4 <= right; i += 5) {
        InsertionSort(A, i, i + 4);
        int index = i + 2;
        swap(A, index, ++sub_right);
    }

    int mid = sub_right / 2;
    int pivot_index = Select(mid, A, 0, sub_right);
    return pivot_index;
}
//��������
void InsertionSort(int A[], int left, int right) {
    for (int i = left + 1; i < right; i++) {
        int j = i - 1;

        int cur = A[i];
        while (1) {
            if (A[j] > cur && j >= 0) {
                A[j + 1] = A[j];
                j--;
            }
            if (j < 0 || A[j] < cur)
                break;
        }
        A[j + 1] = cur;
    }
}
//������λ������
int Partition(int A[], int left, int right, int pivot_index) {
    swap(A, pivot_index, right);
    int pivot = A[right];
    int tail = left - 1;
    int i;
    for (i = left; i < right; i++) {
        if (A[i] <= pivot) {
            swap(A, ++tail, i);
        }
    }
    swap(A, tail + 1, right);

    return tail + 1;
}

void swap(int A[], int a, int b) {
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

int Select(int k, int A[], int left, int right) {
    int pivot_index = GetPivotIndex(A, left, right);
    int divide_index = Partition(A, left, right, pivot_index);
    int num = divide_index - left;
        if (num == k)   return num;
        else if (num < k)   return Select(k - num, A, divide_index, right);
        else    return Select(k, A, left, divide_index);
}

int main() {
    int n, k;
    int A[1024];
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int length = n;
    int right = length - 1;
    int left = 0;
    int index = Select(k - 1, A, left, right);

    printf("�� %d С��Ԫ���ǣ� %d\n", k, A[k - 1]);
}

