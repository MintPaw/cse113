/**
* @file ch5_ex8
* @brief Give the closet flight time
*
* @author Jeru Sanders
* @date 2/13/15
*
* @todo Make it work
* @bugs Everything, I have no idea whay I'm doing with strings. 
	I shouldn't have tried this, but I did and now I have
	no time to write it properly.
*/

#include<stdio.h>
#include<stdlib.h>

int string_to_int_time(char *time);
void print_flight_time(int *index, char *time_data[]);

int main()
{
	char *time_data[] = {
		"8:00-10:16", 
		"9:43-11:52",
		"11:19-1:31",
		"12:47-15:00",
		"2:00-16:08",
		"3:45-17:55",
		"7:00-11:20",
		"9:45-11:58"
	};
	char string_input[8];
	int time_input;

	printf("Give a time in 24hr format seperated by a colon: ");
	fgets(string_input, 8, stdin);

	time_input = string_to_int_time(string_input);

	printf("> %i", time_input);
	
	int closest_time;
	for (closest_time = 0; closest_time < 7; closest_time++)
	{
		if (time_input > string_to_int_time(time_data[closest_time]))
		{
			closest_time--;
			break;
		}
	}

	if (closest_time < 0)
	{
		printf("You will miss all flights");
	} else {
		print_flight_time(&closest_time, time_data);
	}
	
	return 0;
}

int string_to_int_time(char *time)
{
	char hours_string[8];
	char minutes_string[8];

	scanf("1:00", "%s:%s", &hours_string, &minutes_string);
	printf(">> %s %s %s", time, hours_string, minutes_string);
	return atoi(hours_string) * 60 + atoi(minutes_string);
}

void print_flight_time(int *index, char *time_data[])
{
	char time0[8];
	char time1[8];
	printf("%i", *index);
	scanf(time_data[*index], "%s-%s", &time0, &time1);

	printf(
		"The closest fight leaves at %s and lands at %s\n"
		, time0
		, time1);
}
