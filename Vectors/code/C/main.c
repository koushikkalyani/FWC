#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"
int main()
{
	int m=3, n=1;
        double **l1, **l2;
        double **sol;
    l1 = loadtxt("l1.dat",m,n);
	l2 = loadtxt("l2.dat",m,n);
    sol = lin_solv(l1,l2);

	print(sol,2,n);
	save(sol,2,n);
}
		
