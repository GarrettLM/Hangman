#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESSES 6

void printHangman(int);
int count(char *, char);

int main(int argc, char *argv[]) {
	char word[7] = "syzygy";
	char filled[7] = "______";

	int guesses = 0;
	while (guesses < MAX_GUESSES) {
		printHangman(guesses);
		printf("%s\nEnter a letter: ",filled);

		char guess;
		do {
			guess = getchar();
		} while (guess == '\n');

		if (count(word, guess) == 0) {
			guesses++;
			continue;
		}

		for (int i = 0; word[i]; i++)
			if (word[i] == guess)
				filled[i] = guess;
		if (strcmp(word, filled) == 0) {
			printf("Congratulations!\n");
			printf("The word was %s\n", word);
			printf("You guessed it with only %d incorrect guesses!\n", guesses);
			exit(0);
		}
	}

	printHangman(guesses);
	printf("You ran out of guesses.\nYou lose!\n");
}

void printHangman(int wrongGuesses) {
	switch (wrongGuesses) {
		case 0:
			printf("    _____\n");
			printf("   |     |\n");
			printf("         |\n");
			printf("         |\n");
			printf("         |\n");
			printf("         |\n");
			printf("         |\n");
			printf("      ___|___\n");
			break;
		case 1:
			printf("    _____\n");
			printf("   |     |\n");
			printf("   O     |\n");
			printf("         |\n");
			printf("         |\n");
			printf("         |\n");
			printf("         |\n");
			printf("      ___|___\n");
			break;
		case 2:
			printf("    _____\n");
			printf("   |     |\n");
			printf("   O     |\n");
			printf("   |     |\n");
			printf("   |     |\n");
			printf("         |\n");
			printf("         |\n");
			printf("      ___|___\n");
			break;
		case 3:
			printf("    _____\n");
			printf("   |     |\n");
			printf("   O     |\n");
			printf("  _|     |\n");
			printf("   |     |\n");
			printf("         |\n");
			printf("         |\n");
			printf("      ___|___\n");
			break;
		case 4:
			printf("    _____\n");
			printf("   |     |\n");
			printf("   O     |\n");
			printf("  _|_    |\n");
			printf("   |     |\n");
			printf("         |\n");
			printf("         |\n");
			printf("      ___|___\n");
			break;
		case 5:
			printf("    _____\n");
			printf("   |     |\n");
			printf("   O     |\n");
			printf("  _|_    |\n");
			printf("   |     |\n");
			printf("  /      |\n");
			printf("         |\n");
			printf("      ___|___\n");
			break;
		case 6:
			printf("    _____\n");
			printf("   |     |\n");
			printf("   O     |\n");
			printf("  _|_    |\n");
			printf("   |     |\n");
			printf("  / \\    |\n");
			printf("         |\n");
			printf("      ___|___\n");
			break;
	}
}

int count(char *str, char letter) {
	int count = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] == letter) count++;
	return count;
}
