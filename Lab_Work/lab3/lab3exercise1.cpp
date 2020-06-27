//Lab 3 exercise 1
//Fall 2018
//js236

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void radiusInput(double &radius, double &height)
{
  cout<<"Please enter the radius and the height of the cylinder: ";
  cin >> radius >> height;
  if(radius<0)
      radius = 0;
  if (height<0)
      height = 0;
}

double circleDiameter(double radius)
{
	if(radius == 0)
	  return -1;

	return 2 * radius;
}

double circleCircumference(double radius)
{
    if(radius == 0 )
        return -1;
    
    double Circumference = 2 * M_PI * radius;
    return Circumference;
}

double cylinderVolume(double radius, double height)
{
    if(radius == 0 || height == 0)
	  return -1;
    
    double volume =M_PI*pow(radius,2) * height;

    return volume;
}

int main()
{
    double radius, height;
    
    radiusInput(radius, height);

    cout<<fixed<<setprecision(2)<<endl;
    
    cout<<"The diameter of the base of cylinder = "
    <<circleDiameter(radius)<<endl;
    
    cout<<"The circumference of the base of cylinder = "
    <<circleCircumference(radius)<<endl;
    
    cout<<"The cylinder Volume = "
    <<cylinderVolume(radius,height)<<endl;

	return 0;
}