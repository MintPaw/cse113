#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");

	char file_string[999];

	int x = 10;
	int y = 20;
	int i;
	printf("These are printed in an (x, y) format\n\n");
	while(!feof(file))
	{
		x = 10;
		fscanf(file, "%s", file_string);
		if (file_string[0] == '.' || file_string[0] == '*')
		{
			for (i = 0; i < strlen(file_string); i++)
			{
				if (file_string[i] == '.')
				{
					printf("(%d, %d) = 0 ", x, y);
				} else {
					printf("(%d, %d) = 1 ", x, y);
				}
				x++;
			}
		} else {
			continue;
		}
		printf("\n");
		y++;
	}


	return 0;
}