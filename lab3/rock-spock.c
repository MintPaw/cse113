/**
 * @file rock-spock.c
 * @author
 * @date
 * @brief Play Rock-paper-scissors-lizard-Spock against the machine 
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define COMPUTER 8088
#define PLAYER 1000

#define CHOICES 5

#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define LIZARD 3
#define SPOCK 4

void move(int who, int move);
int winner(int computer, int player);
void print_winner(int winner, int comp_move, int player_move);
int nrand(int range);
void seed();


int main(void)
{
	int computer;
	int player;

	/* set up the seed value for the random number generator */
	/* call only once */
	seed();

        /* todo - add a while loop to keep playing */
	printf("Enter a move:\n");
	printf("0 for ROCK\n");
	printf("1 for PAPER\n");
	printf("2 for SCISSORS\n");
	printf("3 for LIZARD\n");
	printf("4 for SPOCK\n");
	printf("5 to have SPOCK eat a ROCK while chasing a LIZARD and quit\n"); 
	printf("Move: ");
	scanf("%d", &player);
  
        /* todo - error check input */
	/* todo -- exit from program when player selects 5 */
	/* otherwise play a game of rock-paper-scissors-lizard-spock */

        /* debug -- you don't need move() to play game  */
	move(PLAYER, player);

        /* generate random number for computers play */
	computer = nrand(CHOICES);

	/*debug -- you don't need this to play the game */
	move(COMPUTER, computer); 


        /* todo --implement function winner() */
        /* todo --implement function print_winner() */
	printf("todo -- who wins? implement the winner with switch statements\n");

	return 0;
}


/** prints the player's or computer's  move to stdin 
 * used in debugging
 * @param who is it the computer or the player's move?
 * @param move what move did they make
 * @return void
 */
void move(int who, int move)
{
	if (who == COMPUTER) 
		printf("Computer's play is ");
	else 
		printf("Player's play is ");


	switch(move) {
	case ROCK:
		printf("ROCK\n");
		break;
	case PAPER:
		printf("PAPER\n");
		break;
	case SCISSORS:
		printf("SCISSORS\n");
		break;
	case SPOCK:
		printf("SPOCK\n");
		break;
	case LIZARD:
		printf("LIZARD\n");
		break;
    	}
}


/** 
 * determines the winner either COMPUTER or PLAYER
 * @param computer the computer's move
 * @param player the player's move
 * @return the winner of the game
 */
int winner(int computer, int player)
{
	/* todo - determine the winner; use switch statements */

	return COMPUTER;
}

/** 
 * prints the winner of the game to stdin 
 * @param winner who won the computer or player
 * @param comp_move what move did the computer make
 * @param play_move what move did the player make
 * @return void
 */
void print_winner(int winner, int comp_move, int player_move)
{
    /* todo - use a switch statement 
 	
    print Computer Wins! or Player Wins!

    And how they won. Use the phrases below

    Scissors cuts paper
    Paper covers rock
    Rock crushes lizard
    Lizard poisons Spock
    Spock smashes scissors
    Scissors decapitates lizard
    Lizard eats paper
    Paper disproves Spock
    Spock vaporizes rock
    Rock crushes scissors
*/
}

/**
 * returns a uniform random integer n, between 0 <= n < range
 * @param range defines the range of the random number [0,range)  
 * @return the generated random number
 */
int nrand(int range) 
{
	return rand() % range;
}

/**
 * call this to seed the random number generator rand()
 * uses a simple seed -- the number of seconds since the epoch 
 * call once before using nrand and similar functions that call rand()
 */
void seed(void) 
{
  	srand((unsigned int)time(NULL));
}
