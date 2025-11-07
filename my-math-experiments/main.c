#include "math_experiments.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	// Example usage: 6 outcomes with given probabilities, 6000 repetitions, random cap of 60
	printf("Unfair to Fair Experiment Results:\n");
	unfair_to_fair(6, (double[]) { 0.15, 0.2, 0.3, 0.1, 0.2, 0.05 }, 6000, 60);

	system("pause");

	// Example usage: 1000 low bound, 2000 up bound, 1500 threshold, 10000 repetitions
	// Use  for tail recursion optimization
	printf("\nPhilanthropist Experiment Results:\n");
	philanthropist(1000, 2000, 1500, 10000);

	system("pause");
}