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


	int best = a[0];
	int worst = a[n - 1];
	int avg = a[n / 2];
	clock_t strt, end;

	strt = clock();
	for(int i=0;i<n;i++) {
		if (best == a[i]) {
			end = clock();
			double t = end - strt;
			printf("best case time: %f\n", (t / CLOCKS_PER_SEC));
			break;
		}
	}

	strt = clock();
	for(int i=0;i<n;i++) {
		if (avg == a[i]) {
			end = clock();
			double t = end - strt;
			printf("avg case time: %f\n", (t / CLOCKS_PER_SEC));
			break;
		}
	}

	strt = clock();
	for(int i=0;i<n;i++) {
		if (worst == a[i]) {
			end = clock();
			double t = end - strt;
			printf("worst case time: %f\n", (t / CLOCKS_PER_SEC));
			break;
		}
	}


	return 0;
}