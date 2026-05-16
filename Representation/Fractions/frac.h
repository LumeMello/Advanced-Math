#ifndef FRAC_H

#define FRAC_H

typedef struct {
	int n,d;
} frac;
int mdc(int a, int b);
int mmc(int a, int b);
frac simpl(frac f);
frac addi(frac f1, frac f2);
frac subt(frac f1, frac f2);
void print_frac(frac f);
frac mult(frac f1,frac f2);
frac divi(frac f1, frac f2);
frac scan_frac();
frac start_frac(int i, int j);

#endif