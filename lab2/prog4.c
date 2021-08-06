#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

	int n =30000;
	int a[n];

	for(int i=0;i<n;i++) {
		//arr[i] = 1 + rand() % 100;
		a[i] = i + 1;
	}


	int best = a[(n - 1) / 2];
	int worst = a[1];
	int avg = a[n / 16];
	clock_t strt, end;

 int low = 0, high = n - 1;
	strt = clock();
	while (low < high)
	{
		int mid = (low + high) / 2;

		if (a[mid] == best) {
			end = clock();
			double t = end - strt;
			printf("best case: %f\n", (t / CLOCKS_PER_SEC));
			break;
		}

		if (a[mid] > best)
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}


	low = 0, high = n - 1;

	strt = clock();
	while (low < high)
	{
		int mid = (low + high) / 2;

		if (a[mid] == avg) {
			end = clock();
			double t = end - strt;
			printf("avg case: %f\n", (t / CLOCKS_PER_SEC));
			break;
		}

		if (a[mid] > avg)
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}


	low = 0, high = n - 1;

	strt = clock();
	while (low < high)
	{
		int mid = (low + high) / 2;

		if (a[mid] == worst) {
			end = clock();
			double t = end - strt;
			printf("worst case: %f\n", (t / CLOCKS_PER_SEC));
			break;
		}

		if (a[mid] > worst)
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}



	return 0;
}