#include <stdio.h>

typedef struct {
	int coeff;
	int exp;
}Polynomial; 

void input(int n, Polynomial p[], int s) {
	printf("Enter Polynomial %d:\n", s);
	for(int i = 0; i < n; i++) {
		printf("Coefficient: ");
		scanf("%d", &p[i].coeff);
		printf("Exponent: ");
		scanf("%d", &p[i].exp);
		printf("\n");
	}
}


void add(int n, Polynomial a[], Polynomial b[], Polynomial result[]) {
	int index = 0, flag, i = 0;
	while (i < n) {	
		for(i = 0; i < n; i++) {
			flag = 0;
			for(int j = 0; j < n; j++) {
				if (a[i].exp == b[j].exp) {
					result[index].exp = a[i].exp;
					result[index].coeff = a[i].coeff + b[j].coeff;
					index++;
					flag = 1;
				}
			}
			if (flag == 0) {
				result[index].exp = a[i].exp;
				result[index].coeff = a[i].coeff;
				index++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		flag = 0;	
		for (int j = 0; j < index; j++) {
			if (b[i].exp == result[j].exp) {
				flag = 1;
			}
		}
		if (flag == 0) {
			result[index].exp = b[i].exp;
			result[index].coeff = b[i].coeff;
			index++;
		}
	}
}

void display(int n, Polynomial p[], int s) {
	printf("Polynomial %d: ", n);
	int i;
	for(i = 0; i < n - 1; i++) {
		printf(" %d^%d +", p[i].coeff, p[i].exp);
	}
	printf(" %d^%d", p[i].coeff, p[i].exp);
	printf("\n");
}

int main() {
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	Polynomial a[n], b[n], result[2*n];
	input(n, a, 1);
	display(n, a, 1);
	input(n, b, 2);
	display(n, b, 2);
	
	add(n, a, b, result);
	display(n, result, 3);
	return 0;
}
