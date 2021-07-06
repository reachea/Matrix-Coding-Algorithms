#include <stdio.h>

int calc(int *cnta,int *cntb) {
	return *cnta + *cntb;
}

int main() {
	int a [2][2] = {1,2,5,-6};
	int b [2] = {5,3};
	int c [2];
	int i,j;
	int cnta = 0;
	int cntb = 0;

	for (i=0; i<2; i++) {
		for (j=0; j<2; j++) {
			if ( j==0 ) {
				cnta = a[i][j] * b[i];
			}
			else if ( j==1 )
			{
				cntb = a[i][j] * b[i];
			}
			c[i] = calc(&cnta, &cntb);
		}
		printf("%d \n", c[i]);
	}
	return 0;
}
