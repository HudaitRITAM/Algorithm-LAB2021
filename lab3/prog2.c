#include <stdio.h>
#include <time.h>

int gcd(int n, int m) {
	while (n > 0) {
		int r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int main() {

	time_t start, end;
	int n, m;
     scanf("%d", &n);
	scanf("%d", &m);


	start = clock();
     printf("%d\n", gcd(n, m));
	end = clock();
	double t = end - start;
	printf("Time taken: %f\n", (t / CLOCKS_PER_SEC));

	return 0;
}