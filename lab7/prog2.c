#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void towerOfHanoi(int n, char s, char h, char d) {

	if (n == 1) {
		printf("Move %d from %c to %c\n", n, s, d);
		return;
	}

	towerOfHanoi(n - 1, s, d, h);
	printf("Move %d from %c to %c\n", n, s, d);
	towerOfHanoi(n - 1, h, s, d);

}

int main() {

	int n;
	scanf("%d",&n);
	towerOfHanoi(n, 'S', 'H', 'D');

	return 0;
}