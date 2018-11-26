#include <iostream>       	//needed for C++
#include <time.h>
#include <math.h>
#include <string.h>
#define PI 3.14159			//declared PI to the following decimal places 

double diameter_to_radius(double diameter)
{
	double radius;								//takes the diameter and finds the radius then returns the radius
	radius=diameter/2;
	
	return radius;
}



double random_value_generator_radius()
{
	// the rand function can only be used with integers. so since we are using double float we have to break it down.
	double radius; 
	char measurement[3];
	double min=5.0;
	double max=15.0;
	double range=(max - min);
	double div = RAND_MAX/range; //RAND_MAX represents the largest value the rand function can return
	radius=min+(rand()/div);
	
	
	int result2=0;
	int result=0;
	
	do
	{
	std::cout << "Is your unit cm or m?\n";
	std::cin >> measurement;
	
	
	if(strcmp(measurement, "cm") == 0)
	{
		result=1;
		break;													//uses break to force exit out of while loop
	}
	
	if(strcmp(measurement, "m") == 0)
	{
		result2=1;
		break;
	}
	
	}
	while((result !=1) || (result2 !=1));
	
	std::cout << "The radius given by random generator is:\n"<< radius << measurement << std::endl;
	
	
	return radius;

}

double random_value_generator_diameter(double radius)
{
															// same as rand radius function ecept with different min and max 
	double diameter;	
	char measurement[3];
	double min=15.0;
	double max=30.0;
	double range=(max - min);
	double div = RAND_MAX/range;
	diameter=min+(rand()/div);
	
	
	int result2=0;
	int result=0;
	
	do
	{
	std::cout << "Is your unit cm or m?\n";
	std::cin >> measurement;
	
	
	if(strcmp(measurement, "cm") == 0)
	{
		result=1;
		break;
	}
	
	if(strcmp(measurement, "m") == 0)
	{
		result2=1;
		break;
	}
	
	}
	while((result !=1) || (result2 !=1));
	
	
	std::cout <<"The diameter given by random generator is:\n" << diameter << measurement << std::endl;
	
	return diameter;
	
}






double area_calculate(double radius)
{
	double area;									//caLculates the area of the circle by receiving the radius as parameter
	area=PI*radius*radius;
	std::cout << "The area of the circle with radius " << radius << "is " << area << std::endl;
	return area;
}

double circumference_calculator(double radius, double diameter)
{
	double circumference; 
	
	circumference=PI*diameter;								//calculates the circumference by receiving the radius and diameter as parameter
	
	std::cout << "The circumference of the circle with diameter" << diameter << "is" << circumference << std::endl;
	
}




double calculate(double radius, double diameter)
{
	char input[1];														//this function is used to calculate eitherr the area or circumference of the circle based on the users input
	double area;
	int answer;
	double circumference;
	int result2=0;
	int result=0;
	
	std::cout << "Do you want to calculate area or circumference?\n";
	
	do
	{
	std::cout << "Enter 'A' for area and 'C' for circumference\n";
	std::cin >> input;
	
	
	if(strcmp("A", input) == 0)
	{
	area=area_calculate(radius);							//calls the area calculate function passing radius as argument
	result=1;
	break;
	}
	
	if(strcmp("C", input) == 0)
	{
	circumference=circumference_calculator(radius, diameter);			//calls the circumference calculate function passing radius and diameter as arguments
	result2=1;
	break;
	}
	
	}
	while((result !=1) || (result2 !=1));	
	
}





int main()
{
	int option;					//holds the users input value
	double radius;
	double diameter;
	
	srand(time(NULL));
	
	do												//displays the menu for user interaction
	{
	std::cout << "Do you want to use radius or diameter for the calculation?\n";
	std::cout << "Type 1 for radius\n";
	std::cout << "Type 2 for diameter\n";
    std::cout << "Enter -1 to exit\n";
	std::cout << "Enter an option:";
	std::cin >> option;
	
	
    if(option == 1)
	{
	radius=random_value_generator_radius();
	diameter=radius*2;
	std::cout << "The corresponding diameter is:" << diameter << std::endl;
	calculate(radius, diameter);
	}
	
	if(option == 2)
	{
	diameter=random_value_generator_diameter(radius);
	radius=diameter_to_radius(diameter);
	std::cout << "The corresponding radius is:" << radius << std::endl;
	calculate(radius, diameter);
	}
	
	if(option == -1)
	{
	std::cout << "Goodbye";
	}
	
	
	}
	while(option != -1);
	
}