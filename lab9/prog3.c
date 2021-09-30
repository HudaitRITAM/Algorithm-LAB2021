#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int find_max(int arr[], int s, int e) {
	if (s > e) {
		return -(1 << 30);
	}
	if (s == e) {
		return arr[s];
	}
	int rem = find_max(arr, s + 1, e);
	return ((arr[s] > rem) ? arr[s] : rem);

}
int find_min(int arr[], int s, int e) {

	if (s > e) {
		return -(1 << 30);
	}

	if (s == e) {
		return arr[s];
	}

	int rem = find_max(arr, s + 1, e);

	return ((arr[s] < rem) ? arr[s] : rem);
}
int main() {
	printf("n\t\t|\tTime\t\tMax\t\tMin\n");
	int sizes;
	scanf("%d",&sizes);
	for(int i=0;i<sizes;i++) {
		int n;
		scanf("%d",&n);
		printf("%d\t|\t", n);
		int arr[n];
		time_t start, end;
		double time;
		for(int j=0;j<n;j++) {
			arr[j] = rand() % 5000 + 1;
		}
		start = clock();
		int ans1 = find_max(arr, 0, n - 1);
		int ans2 = find_min(arr, 0, n - 1);
		end = clock();
		time = (end - start) * 1.0 / CLOCKS_PER_SEC;
		printf("%f\t%d\t%d\n", time, ans1, ans2);

	}
	return 0;
}
