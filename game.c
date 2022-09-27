#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	int opp_score = 100;
	int my_score = 100;
	int opp_total = 0, my_total = 0;
	int my_card[5];
	char ans;
	int opp_card[5];
	int i = 0;
	
	srand(time(NULL));
	while (opp_score > 0 && my_score > 0)
	{
			opp_total = my_total = 0;
			/* generates random numbers for the user's card*/
			while (i < 5)
			{
				my_card[i] =  (rand() % 10)+ 1;
				my_total += my_card[i];
				i++;
			}
			printf("These are your cards\n");
			sleep(1);
			for (i = 0; i < 5; i++)
				printf("%i ", my_card[i]);
			putchar('\n');
			i = 0;
			/* generates random number for the opponent's card*/
			while (i < 5)
			{
				opp_card[i] = (rand() % 10) + 1;
				opp_total += opp_card[i];
				i++;
			}
				
			printf("Will you bet? y/n?\n");
			puts("Note: Any button but 'n' means yes\n");
			scanf(" %c", &ans);
			if (ans == 'n' || ans == 'n' - 32)
			{
				my_score -= 25;
				opp_score += 25;
				printf("You lost 25pts you have %dpts remaining\n", my_score);
				continue;
			}
			printf("opponent's' cards\n");
			sleep(1);
			for (i = 0; i < 5; i++)
				printf("%i ", opp_card[i]);
			putchar('\n');
				
			if (my_total > opp_total)
			{
				my_score += 50;
				opp_score -= 50;
				sleep(1);
				printf("You won 50pts, your new score is now %d\n your opponent lost 50pts and is now %d\n", my_score, opp_score);
			}
			else if (opp_total > my_total)
			{
				my_score -= 50;
				opp_score += 50;
				sleep(1);
				printf("You lost 50pts, your new score is now %d\n your opponent won 50pts and is now %d\n", my_score, opp_score);
			}
			else
			{
				sleep(1);
				printf("It was a draw\n");
			}
			sleep(1);
	}
	if (my_score > 0)
		puts("Hurray you won :)");
	else
	{
				puts("You lose   : (");
	}
				
}
