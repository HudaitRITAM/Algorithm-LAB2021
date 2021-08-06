#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>

int main() {

	int n;
	scanf("%d",&n);
	float arr[10][10];
	float a[10][10];
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf("%f", &arr[i][j]);
			a[i][j] = arr[i][j] - (int)(arr[i][j]);
		}
	}
	float row[n], col[n];
	for(int i=0;i<n;i++) {
		float s = 0.0;
		for(int j=0;j<n;j++) {
			s += a[i][j];
		}
		row[i] = s;
	}

	for(int j=0;j<n;j++) {
		float s = 0.0;
		for(int i=0;i<n;i++) {
			s += (arr[i][j] - (int)(arr[i][j]));
		}
		col[j] = s;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < row[i]; j++) {
			if (col[j] == 0) {
				a[i][j] = 0;
				continue;
			}
			a[i][j] = 1;
			col[j]--;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < col[i]; j++) {
			if (row[j] == 0) {
				a[j][i] = 1;
				continue;
			}
			a[j][i] = 0;
			row[j]--;
		}
	}


	printf("Rounded up matrix :\n");

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			printf("%d ", (int)(arr[i][j]) + (int)(a[i][j]));
		}
		printf("\n");
	}

	return 0;
}