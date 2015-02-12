/**
* @file lab1.c
* @brief Does various geo-maths
*
* @author Jeru Sanders
* @date 2/4/15
*/

#include<stdio.h>
#include<math.h>

double area_rectangle(double width, double height);
double perimeter_rectangle(double width, double height);
double diagonal_rectangle(double width, double height);
double area_circle(double radius);
double circumference(double radius);
double area_triangle(double base, double height);
double hypotenuse(double a, double b);
double perimeter_triangle(double a, double b);
double exterior_angle(int angles);
double interior_angle(int angles);
double area_regular_polygon(int sides, double length);

int main()
{
        printf("Area of rectangle 3, 4: %lf\n", area_rectangle(3, 4));
        printf("Perimeter of rectangle 3, 4: %lf\n", perimeter_rectangle(3, 4));
        printf("Diagonal of rectangle 3, 4: %lf\n", diagonal_rectangle(3, 4));
        printf("Area of circle 4: %lf\n", area_circle(4));
        printf("Circumference of circle 4: %lf\n", circumference(4));
        printf("Area of triangle 3, 4: %lf\n", area_triangle(3, 4));
        printf("Hypotenuse of triangle 3, 4: %lf\n", hypotenuse(3, 4));
        printf("Perimeter of triangle 3, 4: %lf\n", perimeter_triangle(3, 4));
        printf("Exterior of angles of 8-sided polygon: %lf\n", exterior_angle(8));
        printf("Interior of angles of 8-sided polygon: %lf\n", interior_angle(8));
        printf("Area of 8-sided polygon with side length 10: %lf\n", area_regular_polygon(8, 10));
        return 0;
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
* @param angles The number of angles in the polygon
* @return The degrees per exterior angle in the polygon
*/
double exterior_angle(int angles)
{
        return angles / 360;
}

/**
* Computes the interior angles in a polygon
* @param angles The number of angles in the polygon
* @return The degrees per interior angle in the polygon
*/
double interior_angle(int angles)
{
        return (180 * (angles - 2)) / angles;
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
