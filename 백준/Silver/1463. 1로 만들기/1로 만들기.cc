#include<stdio.h>
int arr[1000001];
int min_arr(int a, int b)
{
	return a < b ? a : b;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) {
			arr[i] = min_arr(arr[i], arr[i / 2] + 1);
		}
		if (i % 3 == 0) {
			arr[i] = min_arr(arr[i], arr[i / 3] + 1);
		}
	}
	printf("%d", arr[n]);
}