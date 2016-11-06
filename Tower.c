/*
 *
 * An algorithm that solves the Tower of Hanoi with the use of recursion
 * Robert Vaughan
 * 15/02/2016
 *
 */

#include <stdio.h>
#define SIZE 1
int moveTower(int, int, int, int);

int main()
{
	int input = 0;
	while (input < SIZE) {
		printf("Please enter the number of discs you would like in the tower:\n");
		scanf("%d", &input);
		if (input < SIZE) {
			printf("You must enter a number of discs greater than one!\n");
		}
	}
	int moves = moveTower(input, 1, 3, 2);
	printf("Your tower is now complete!\n");
	printf("The number of moves is %d\n", moves);
}

int moveTower(int disc, int source, int dest, int spare)
{
	if (disc == 1) {
		printf("Moved a disc from Tower %d to tower %d\n", source, dest);
		return 1;
	} else {
		return moveTower(disc - 1, source, spare, dest)
		     + moveTower(1,        source, dest,  spare)
		     + moveTower(disc - 1, spare,  dest,  source);
	}
}
