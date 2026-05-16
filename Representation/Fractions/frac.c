#include <stdio.h>
#include "frac.h"

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