// Assume we have an unfair dice with n faces and p[i] is the probability of face i.
// Toss the dice for n times, if all the results are different, return the last result; otherwise, repeat.
// 
// Math proof:
// P(res[i]) = p[i]
// P(res[i] | diff) = P(diff | res[i]) * P(res[i]) / P(diff)
// P(diff | res[i]) = A(n - 1, n - 1) * ¦°(j <= n, j != i) p[j]
// P(diff} = A(n, n) * ¦°(j <= n) p[j]
// P(res[i] | diff) = { A(n - 1, n - 1) * ¦°(j <= n, j != i) p[j] * p[i] } / { A(n, n) * ¦°(j <= n) p[j] }
// P(res[i] | diff) = 1 / n

#include "math_experiments.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int unfair_to_fair(int size, double* p, int repeat, int rand_cap) {
    srand((unsigned)time(NULL));

    int* res = (int*)calloc(size, sizeof(int));
    int* bucket = (int*)calloc(size, sizeof(int));
    if (!res || !bucket) { return 0; }

    for (int i = 0; i < repeat;) {
        int has_same = 0;
        memset(bucket, 0, size * sizeof(int));

        for (int j = 0; j < size - 1; j++) {
            int toss = rand() % rand_cap;
            for (int k = 0; k < size; k++) {
                if ((toss -= p[k] * rand_cap) <= 0) { has_same = bucket[k]++; break; }
            }
            if (has_same) { break; }
        }
        if (has_same) { continue; }

        int toss = rand() % rand_cap;
        int tmp = 0;
        for (int k = 0; k < size; k++) {
            if ((toss -= p[k] * rand_cap) <= 0) { tmp = k; has_same = bucket[k]++; break; }
        }
        if (has_same) { continue; }
        res[tmp]++;
        i++;
    }

    for (int i = 0; i < size; i++) {
        printf("res[%d]: %d\n", i + 1, res[i]);
    }
    free(res);
    free(bucket);
    return 1;
}