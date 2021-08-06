#include <stdio.h>
#include <time.h>
#include <math.h>

int checkPrimeSimple(int n) {
   for(int i = 2; i < n; i++)
         {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int checkPrimeSqRoot(int n) {

	int sq = sqrt(n);

     for(int i = 2; i < sq + 1; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {

	time_t start, end;
	int n;
        scanf("%d", &n);
	start = clock();
        printf("%d\n", checkPrimeSimple(n));
	end = clock();
	double t = end - start;
	printf("Time taken for simple algo: %f\n", (t / CLOCKS_PER_SEC));

	start = clock();
        printf("%d\n", checkPrimeSqRoot(n));
	end = clock();
	t = end - start;
	printf("Time taken for sq root algo: %f\n", (t / CLOCKS_PER_SEC));

	return 0;
}