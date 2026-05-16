#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int n,d;
} frac;

int mdc(int a, int b) {
    if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (b == 0) return a;
	if (a == 0) return b;
    
	int m = 1;
	int resto = -1;
	if(b > a) {
		m = b;
		b = a;
		a = m;
		m = 1;
	}
	while(resto != 0) {
        resto = a%b;
        m = b;
        a = b;
        b = resto;
	}
	return m;
}

int mmc(int a, int b) {
	return (a*b)/mdc(a,b);
}

frac simpl(frac f) {
	int m = mdc(f.n,f.d);
	frac result;
	result.n = f.n/m;
	result.d = f.d/m;
	if(result.d < 0){
	    result.n = -result.n;
	    result.d = -result.d;
	}
	return result;
}

frac addi(frac f1, frac f2) {
	int m = mmc(f1.d, f2.d);
	f1.n = (m/f1.d) * f1.n;
	f2.n = (m/f2.d) * f2.n;
	frac result;
	result.n = f1.n + f2.n;
	result.d = m;
	return simpl(result);
}

frac subt(frac f1, frac f2) {
	int m = mmc(f1.d, f2.d);
	f1.n = (m/f1.d) * f1.n;
	f2.n = (m/f2.d) * f2.n;
	frac result;
	result.n = f1.n - f2.n;
	result.d = m;
	return simpl(result);
}

void print_frac(frac f) {
	printf("%d/%d",f.n,f.d);
}

frac mult(frac f1,frac f2) {
	frac result;
	result.n = f1.n * f2.n;
	result.d = f1.d * f2.d;
	return simpl(result);
}

frac divi(frac f1, frac f2) {
	frac result;
	result.n = f1.n * f2.d;
	result.d = f1.d * f2.n;
	return simpl(result);
}

frac scan_frac() {
	frac result;
	scanf("%d/%d", &result.n, &result.d);
	return result;
}

frac start_frac(int i, int j) {
	frac result;
	result.n = i;
	result.d = j;
	return result;
}

bool equals(frac *v1, frac *v2, int qt) {
	for(int i = 0; i < qt; i++) {
	    v1[i] = simpl(v1[i]);
	    v2[i] = simpl(v2[i]);
		if((v1[i].n != v2[i].n) || (v1[i].d != v2[i].d)) {
			return false;
		}
	}

	return true;
}

int main() {
	int n = 0;

	printf("How many states this chain have?\n");
	scanf("%d", &n);

	frac matrix[n][n];
	frac step[n], soma[n], lastStep[n];

	printf("Use the format numerator/denominator\n");
	for(int p = 0; p<n; p++) {
		printf("Complete the adjacency matrix line %d",p);
		for(int l =0; l<n; l++) {
			printf("\nItem %d,%d: ",p,l);
			matrix[p][l] = scan_frac();
		}
		soma[p] = start_frac(0,1);
		step[p] = start_frac(0,1);
		if(p==0) {
			step[p]=start_frac(1,1);
		}
		lastStep[p]=start_frac(1,1);
	}

	printf("Starting from the first state we have:\n");

	do {
	    for(int i = 0; i < n; i++) {
			lastStep[i] = step[i];
		}
	    
		for(int j = 0; j < n; j++) {
			soma[j] = start_frac(0,1);
			for(int k = 0; k < n; k++) {
				soma[j] = addi(soma[j],mult(step[k],matrix[k][j]));
			}
		}

		for(int w = 0; w < n; w++) {
			step[w]=simpl(soma[w]);
			print_frac(step[w]);
		}
		printf("\n");
	} while(!equals(lastStep,step,n));

	return 0;
}