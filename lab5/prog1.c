#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>


int maxSum(int a[], int n)
{
	int prev = INT_MIN, curr = 0;

	for (int i = 0; i < n; i++)
	{
		curr = curr + a[i];

		if (prev < curr)
			prev = curr;

		if (curr < 0)
			curr = 0;
	}
	return prev;
}



int main() {


	int n;
	scanf("%d", &n);

	int arr[n];
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}

	time_t start, end;
	double time;
	start = clock();
	printf("Max Subarray sum : %d\n", maxSum(arr, n));
	end = clock();

	time = (end - start) * 1.0 / CLOCKS_PER_SEC;

	printf("Time taken: %f seconds", time);



	return 0;
}