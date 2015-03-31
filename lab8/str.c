#include "str.h"
#include <stdio.h>

int str_len(char *s)
{
	/* this is so it compiles */
	return 0;
}

/* array version */
/* concantenate t to the end of s; s must be big enough */
void str_cat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while(s[i] != '\0') 	/* find end of s */
		i++;
	while((s[i++] = t[j++]) != '\0') /* copy t */
		;
}

/* array version */
void squeeze(char s[], int c)
{
	int i, j;
	
	for(i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';
}


void reverse(char s[])
{
	int c, i, j;

	for(i = 0, j = str_len(s) - 1; i < j; i++, j-- ) {
		/* change this so it calls cswap */
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	
}

/* copy n chars of src into dest */
void pstr_ncpy(char *dest, char *src, int n)
{

}

/* concantenate t to the end of s; s must be big enough! */
void pstr_cat(char *s, char *t)
{


}
