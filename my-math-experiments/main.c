#include "math_experiments.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	// Example usage: 6 outcomes with given probabilities, 60000 repetitions, random cap of 60
	printf("Unfair to Fair Experiment Results:\n");
	unfair_to_fair(6, (double[]) { 0.15, 0.2, 0.3, 0.1, 0.2, 0.05 }, 60000, 60);

	system("pause");
}