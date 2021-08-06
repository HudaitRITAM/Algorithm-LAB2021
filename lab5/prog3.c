#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>



int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}

int lcm(int a, int b) {
	return (a * b / gcd(a, b));
}

int GCDN(int a[], int n) {

	int gcd_ = a[0];
	for(int i=1;i<n;i++) {
		gcd_ = gcd(gcd_, a[i]);
	}

	return gcd_;

}

int LCMN(int a[], int n) {

	int lcm_ = a[0];

	for(int i=1;i<n;i++) {
		lcm_ = lcm(lcm_, a[i]);

	}
	return lcm_;

}



int main() {


	int n;
	scanf("%d",&n);

	int arr[n];
	for(int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}

	time_t start, end;
	double time;
	start = clock();
	printf("GCD of numbers: %d\n", GCDN(arr, n));
	end = clock();
	time = (end - start) * 1.0 / CLOCKS_PER_SEC;
	printf("Time taken: %f seconds\n", time);

	start = clock();
	printf("LCM of numbers: %d\n", LCMN(arr, n));
	end = clock();
	time = (end - start) * 1.0 / CLOCKS_PER_SEC;
	printf("Time taken: %f seconds\n", time);



	return 0;
}