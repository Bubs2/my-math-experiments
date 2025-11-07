/**
* A philanthropist is giving away money through a game.
* He writes a number x on a card A.
* Then he flips a coin to decide whether to write 2x or x/2 on another card B.
* While you don't know the number x and the result of the coin flip,
* you can choose to take either card A or card B.
* 
* First, it can be proved that you should not choose card A.
* Because no matter what x is and the strategy you use, the expected value of card A is always less than card B,
* where E[B] = 0.5 * 2x + 0.5 * x/2 = 1.25x > x = E[A].
* 
* Then, the question is, what is the best strategy to maximize the expected value of the card you take?
* One possible strategy is to set a threshold T.
* If the number on card B is less than T, you take card A.
* 
* Math proof:
* Let Rt(x) be the reward the philanthropist writes x, and threshold is T.
* When x < 0.5 * T, you always take card A, so E[Rt(x)] = x.
* When 0.5 * T <= x < 2 * T, you take card A when the card B is x/2, so E[Rt(x)] = 0.5 * x + 0.5 * 2x = 1.5x.
* When x >= 2 * T, you always take card B, so E[Rt(x)] = E[B] = 1.25x.
* 
* Now with your belief on the distribution of x, you can choose the best threshold T to maximize the expected value of the card you take.
**/

#include "math_experiments.h"
#include <stdio.h>
#include <stdlib.h>

double philanthropist(int low_bound, int up_bound, double threshold, int repeat) {
	double sum = 0;

	for (int i = 0; i < repeat; i++) {
		double card_a = low_bound + rand() % (up_bound - low_bound + 1);

		int coin = rand() % 2;

		double card_b = coin ? card_a * 2 : card_a / 2;

		if (card_b < threshold) {
			sum += card_a;
		}
		else {
			sum += card_b;
		}
	}

	printf("Average reward with threshold %lf: %lf\n", threshold, sum / repeat);
	return 1;
}