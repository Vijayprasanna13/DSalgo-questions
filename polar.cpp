#include <iostream>
#include <math.h>
using namespace std;

//Class for Polar number - contains variables and functions 
class Polar{				
	float magnitude;
	float angle;
	public:
		//Constructor 
		Polar(int a,int b){
			magnitude = a;
			angle = b;
		}
		//Add two polar numbers
		class Polar add(class Polar number1,class Polar number2){
			class Polar number = Polar(0,0);
			float x = number1.magnitude*cos(3.14*number1.angle/180) + number2.magnitude*cos(3.14*number2.angle/180);
			float y = number1.magnitude*sin(3.14*number1.angle/180) + number2.magnitude*sin(3.14*number2.angle/180);
			number.magnitude = sqrt(x*x+y*y);
			number.angle = 180*atan(y/x)/3.14;
			return number;	
		}
		//Subtract two polar numbers
		class Polar subtract(class Polar number1,class Polar number2){
			class Polar number = Polar(0,0);
			float x = number1.magnitude*cos(3.14*number1.angle/180) - number2.magnitude*cos(3.14*number2.angle/180);
			float y = number1.magnitude*sin(3.14*number1.angle/180) - number2.magnitude*sin(3.14*number2.angle/180);
			number.magnitude = sqrt(x*x+y*y);
			number.angle = 180*atan(y/x)/3.14;  
			return number;	
		}
		//Multiply two polar numbers
		class Polar multiply(class Polar number1,class Polar number2){
			class Polar number = Polar(0,0);
			number.magnitude = number1.magnitude*number2.magnitude;
			number.angle = number1.angle + number2.angle;
			return number;
		}
		void printPolar(){
			cout<<"The answer is :- Magnitude: "<<magnitude<<" Angle: "<<angle<<"\n";
		}
		
};

int main(){
	cout<<"POLAR coords\n";
	cout<<"~~~~~~~~~~~~~";
	int menu_choice;
	do{
	float magnitude,angle;
	
	cout<<"\nEnter the first POLAR coord set : \n";	//accept the first POLAR number
	cout<<"\nEnter the magnitude : ";
	cin>>magnitude;
	cout<<"\nEnter the angle(in Deg): ";
	cin>>angle;
	class Polar number1 = Polar(magnitude,angle);
	
	cout<<"\nEnter the Second POLAR coord set : \n";	//accept the second POLAR number
	cout<<"\nEnter the magnitude: ";
	cin>>magnitude;
	cout<<"\nEnter the angle (in deg): ";
	cin>>angle;
	class Polar number2 = Polar(magnitude,angle);
	class Polar number = Polar(0,0);
	//number = number.subtract(number1,number2);
	//number.printPolar();
	int menu_choice;
	do
	{
		class Polar number = Polar(0,0);
		cout<<"\n1.Add \n2.Subtract \n3.Multiply";
		cout<<"\nEnter your choice : ";
		cin>>menu_choice;
		switch(menu_choice){
			case 1: number = number.add(number1,number2);number.printPolar();break;
			case 2: number = number.subtract(number1,number2);number.printPolar();break;
			case 3: number = number.multiply(number1,number2);number.printPolar();break;
			}
		cout<<"\nTry another operation?(0 to exit) :";
		cin>>menu_choice;
	}while(menu_choice);
	
	cout<<"\nDo you want to do again?(0 to exit)";
	cin>>menu_choice;
	}
	while(menu_choice);
	return 0;
}
