#include "str.h"
#include <stdio.h>

int str_len(char *s)
{
	int count = 0;
	int i;
	for (i = 0; ; i++)
	{
		if (*(s + i) == '\0')
		{
			break;
		}

		count++;
	}
	return count;
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

int pstr_ncmp(char *s, char *t, int n)
{
	int i;
	for (i = 0; i < n ; i++)
	{
		if (*(s + i) != *(t + i))
		{
			return 0;
		}
	}
	return 1;
}

/* copy n chars of src into dest */
void pstr_ncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n ; i++)
	{
		*(dest + i) = *(src + i);
		if (*(src + i) == '\0')
		{
			break;
		}
	}
}

/* concantenate t to the end of s; s must be big enough! */
void pstr_cat(char *s, char *t)
{
	int i, j;

	i = j = 0;
	while(*(s + i) != '\0')
	{
		i++;
	}

	while((*(s + i++) = *(t + j++)) != '\0')
	{
	}
}

char *pindex(char *s, int c)
{
	int i;
	for (i = 0; ; i++)
	{
		if (*(s + i) == c)
		{
			return s + i;
		}

		if (*(s + i) == '\0')
		{
			return NULL;
		}
	}
}

void psqueeze(char *s, int c)
{
	int i, j;
	
	for(i = j = 0; *(s + i) != '\0'; i++)
	{
		if (*(s + i) != c)
		{
			*(s + j++) = *(s + i);
		}
	}

	*(s + j) = '\0';
}

void preverse(char *s)
{
	int c, i, j;

	for(i = 0, j = str_len(s) - 1; i < j; i++, j-- ) {
		/* change this so it calls cswap */
		c = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = c;
	}	
}