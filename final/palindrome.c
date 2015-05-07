/**
* @file palindrome.c
* @brief Determines if a word is a palindrome
* @details Determines if a word is a palindrome
* @author Jeru Sanders
* @date 5/7/15
* @todo None
* @bug None
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char is_palindrome(char *word);

int main(int argc, char *argv[])
{
	char *word = *(argv + 1);

	is_palindrome(word);

	return 0;
}

/**
* Determines if a word is a palindrome
* @param word The word
* @return Whether the word is a palindrome
*/
char is_palindrome(char *word)
{
	int i;
	for (i = 0; i < strlen(word); i++) {
		if (tolower(*(word + i)) != tolower(*(word + strlen(word) - i - 1))) {
			printf("%s is not a palindrome\n", word);
			return 0;
		}
	}

	printf("%s is a palindrome\n", word);
	return 1;
}