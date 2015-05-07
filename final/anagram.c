/**
* @file anagram.c
* @brief Determines if two words are anagrams
* @details Determines if two words are anagrams
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

char is_anagram(char *word1, char *word2);

int main(int argc, char *argv[])
{
	char *word1 = argv[1];
	char *word2 = argv[2];

	is_anagram(word1, word2);

	return 0;
}

/**
* Tests if two words are anagrams
* @param word1 The first word
* @param word2 The second word
* @return Whether they are anagrams
*/
char is_anagram(char *word1, char *word2)
{
	if (strlen(word1) != strlen(word2)) {
		printf("not anagram: strings differ in length\n");
		return 0;
	}

	unsigned char *letters1;
	unsigned char *letters2;

	letters1 = calloc(26, sizeof(unsigned char));
	letters2 = calloc(26, sizeof(unsigned char));

	int i;
	for (i = 0; i < 26; i++) {
		letters1[i] = 0;
		letters2[i] = 0;
	}

	for (i = 0; i < strlen(word1); i++) {
		unsigned char current_letter1 = tolower(word1[i]) - 97;
		unsigned char current_letter2 = tolower(word2[i]) - 97;
		
		letters1[current_letter1]++;
		letters2[current_letter2]++;
	}

	char result = 1;
	for (i = 0; i < 26; i++) {
		if (letters1[i] != letters2[i]) {
			result = 0;
			break;
		}
	}

	free(letters1);
	free(letters2);

	if (result == 0) {
		printf("%s and %s are not anagrams\n", word1, word2);
		return 0;
	}

	printf("%s and %s are anagrams\n", word1, word2);
	return 1;
}