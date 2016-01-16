#include <stdio.h>
#include <string.h>

typedef struct _rate {
    int id;
    double rat;
} rate;

int q = 0;
rate p[1000] = {};
char fano[1000][100] = {};

void code(int s, int e, double su) {
	if (s + 1 == e) return;

    int i, j;
	double n = 0;
	for (i = s; i < e; i++) {
		if (n + p[i].rat > (su / 2.00)) break;
		n += p[i].rat;
		strcat(fano[p[i].id], "0");
	}

	if (i < e && ((su - n) - n) > (n + p[i].rat - (su - n))) {
		n += p[i].rat;
		strcat(fano[p[i].id], "0");
		i++;
	}

	for (j = i; j < e; j++)
		strcat(fano[p[j].id], "1");

	code(s, i, n);
	code(i, e, su - n);
}

int main() {
	printf("ÇëÊäÈëQ\n");
	scanf("%d", &q);
    printf("ÇëÊäÈëpi\n");
	int i, j;
	double sum = 0;
	for (i = 0; i < q; i++) {
		p[i].id = i;
		scanf("%lf", &p[i].rat);
		sum += p[i].rat;
	}

	for(i = 0; i < q; i++) {
        for(j = 0; j < q - 1; j++) {
            if(p[j].rat < p[j + 1].rat) {
                rate tmp;
                tmp.id      = p[j].id;
                tmp.rat     = p[j].rat;
                p[j].id     = p[j+1].id;
                p[j].rat    = p[j+1].rat;
                p[j+1].id   = tmp.id;
                p[j+1].rat  = tmp.rat;
            }
        }
	}

	code(0, q, sum);

	for (i = 0;i < q; i++)
		printf("s%d %s\n", i, fano[i]);

	printf("\n");

	return 0;
}
