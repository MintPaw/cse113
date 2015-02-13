/**
* @file lab2.c
* @brief Does lots of geo-maths 
*
* @author Jeru Sanders
* @date 2/11/15
*
* @note I think nested switch statements are objectively bad design in this situation
*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

void get_real_char(char *c);
void get_input_double(char prompt[], double *radius);
void errorCheck(double *value);

double area_rectangle(double width, double height);
double perimeter_rectangle(double width, double height);
double diagonal_rectangle(double width, double height);
double area_circle(double radius);
double circumference(double radius);
double area_triangle(double base, double height);
double hypotenuse(double a, double b);
double perimeter_triangle(double a, double b);
double exterior_angle(int sides);
double interior_angle(int sides);
double area_regular_polygon(int sides, double length);

int main()
{
	char choice;
	double value1;
	double value2;

	printf("Welcome to Jeru Sanders' geometry calculator\n\nSelect a category:\n\n");
	printf("C. Circles\nP. Regular Polygons\nR. Rectangles\nT. Right Triangles\n\n");

	get_real_char(&choice);

	printf("\n\n\n");
	switch (choice)
	{
		case 'c':
			printf("A. Area\nC. Circumference\n");
			get_real_char(&choice);
			get_input_double("Give a radius: ", &value1);
			switch (choice)
			{
				case 'a':
					printf("The area of cirle radius %lf is %lf\n", value1, area_circle(value1));
					break;
				case 'c':
					printf("The circumference cirle radius %lf is %lf\n", value1, circumference(value1));
					break;
				default:
					printf("Invalid option");
			}
			break;
		case 'p':
			printf("E. Exterior angles\nI. Interior angles\nA. Area\n");
			get_real_char(&choice);
			get_input_double("Give polygon sides: ", &value1);
			switch (choice)
			{
				case 'e':
					printf("The exterior angles of a polygon with %lf sides is %lf\n", value1, exterior_angle(value1));
					break;
				case 'i':
					printf("The interior angles of a polygon with %lf sides is %lf\n", value1, interior_angle(value1));
					break;
				case 'a':
					get_input_double("Give side length: ", &value2);
					printf("The area of a polygon with %lf sides %lf long is %lf\n", value1, value2, area_regular_polygon(value1, value2));
					break;
				default:
					printf("Invalid option");
			}
			break;
		case 'r':
			printf("A: Area\nP: Perimeter\nD: Diagonal\n");
			get_real_char(&choice);
			get_input_double("Give width: ", &value1);
			get_input_double("Give height: ", &value2);
			switch (choice)
			{
				case 'a':
					printf("The area of rectangle length %lf and width %lf is %lf\n", value1, value2, area_rectangle(value1, value2));
					break;
				case 'p':
					printf("The perimeter of rectangle length %lf and width %lf is %lf\n", value1, value2, perimeter_rectangle(value1, value2));
					break;
				case 'd':
					printf("The diagonal of rectangle length %lf and width %lf is %lf\n", value1, value2, diagonal_rectangle(value1, value2));
					break;
				default:
					printf("Invalid option");
			}
			break;
		case 't':
			printf("A: Area\nP: Perimeter\nH: Hypotenuse\n");
			get_real_char(&choice);
			switch (choice)
			{
				case 'a':
					get_input_double("Give base: ", &value1);
					get_input_double("Give height: ", &value2);
					printf("The area of triangle sides %lf and %lf is %lf\n", value1, value2, area_triangle(value1, value2));
					break;
				case 'p':
					get_input_double("Give side A: ", &value1);
					get_input_double("Give side B: ", &value2);
					printf("The perimeter of triangle sides %lf and %lf is %lf\n", value1, value2, perimeter_triangle(value1, value2));
					break;
				case 'h':
					get_input_double("Give side A: ", &value1);
					get_input_double("Give side B: ", &value2);
					printf("The hypotenuse of triangle sides %lf and %lf is %lf\n", value1, value2, hypotenuse(value1, value2));
					break;
				default:
					printf("Invalid option");
			}
			break;
		default:
			printf("Invalid option");
	}
	
	return 0;

}

/**
* Gets a real character, filters things we don't want, also case insensitive
* @param c A pointer to a character to store the input
*/
void get_real_char(char *c)
{
	printf("Make a selection: ");

	char temp;
	while((temp = tolower(getchar())) != '\n')
	{
		*c = temp;
	}
}

/**
* Asks the user for a double
* @param prompt A string to prompt the user
* @param value A pointer to a double to store the input
*/
void get_input_double(char prompt[], double *value)
{
	printf("%s", prompt);
	scanf("%lf", value);
	errorCheck(value);
}

/**
* Error checks user input
* @param value The value to error check
*/
void errorCheck(double *value)
{
	if (*value < 0)
	{
		printf("Value must be greater or equal to 0\n");
		exit(1);
	}
}

/**
* Computes the area of a rectangle
* @param width The width of the rectangle
* @param height The height of the rectangle
* @return The area of the rectangle
*/
double area_rectangle(double width, double height)
{
        return width * height;
}

/**
* Computes the perimeter of a rectangle
* @param width The width of the rectangle
* @param height The height of the rectangle
* @return The perimeter of the rectangle
*/
double perimeter_rectangle(double width, double height)
{
        return width*2 + height*2;
}

/**
* Computes the diagonal of a rectangle
* @param width The width of the rectangle
* @param height The height of the rectangle
* @return The diagonal of the rectangle
*/
double diagonal_rectangle(double width, double height)
{
        return sqrt(width * width + height * height);
}

/**
* Computes the area of a circle
* @param radius The radius of the circle
* @return The area of the circle
*/
double area_circle(double radius)
{
        return M_PI * radius * radius;
}

/**
* Computes the circumference of a circle
* @param radius The radius of the circle
* @return The circumference of the circle
*/
double circumference(double radius)
{
        return 2 * M_PI * radius;
}

/**
* Computes the area of a triangle
* @param base The base of the triangle
* @param height The height of the triangle
* @return The area of the triangle
*/
double area_triangle(double base, double height)
{
        return base * height / 2;
}

/**
* Computes the diagonal of a triangle
* @param a The a side of the triangle
* @param b The b side of the triangle
* @return The hypotenuse of the triangle
*/
double hypotenuse(double a, double b)
{
        return sqrt(a * a + b * b);
}

/**
* Computes the perimeter of a triangle
* @param a The a of the triangle
* @param b The b of the triangle
* @return The perimeter of the triangle
*/
double perimeter_triangle(double a, double b)
{
        return a + b + hypotenuse(a, b);
}

/**
* Computes the exterior angles in a polygon
* @param sides The number of sides in the polygon
* @return The degrees per exterior angle in the polygon
*/
double exterior_angle(int sides)
{
        return sides / 360;
}

/**
* Computes the interior angles in a polygon
* @param angles The number of sides in the polygon
* @return The degrees per interior angle in the polygon
*/
double interior_angle(int sides)
{
        return (180 * (sides - 2)) / sides;
}

/**
* Computers the area of a regular polygon
* @param sides The number of sides in the polygon
* @param length The length of each side
* @return The area of the polygon
*/
double area_regular_polygon(int sides, double length)
{
        return (length * length * sides) / (4 * tan(M_PI/sides));
}
