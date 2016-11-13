#include <iostream>
using namespace std; 
struct Complex{
	int real;
	int img;
	void acceptComplexNumber(int real,int img){
		this->real = real;
		this->img = img;
	}
	
	void printComplexNumber(){
		cout<<"\n The complex number is : "<<this->real<<"+"<<this->img<<"i"; 
	}
	
	struct Complex addComplexNumber(struct Complex number1,struct Complex number2){
		struct Complex number;
		number.acceptComplexNumber(number1.real+number2.real,number1.img+number2.img);
		return number;
	}
};

int main(){
	int choice;
	do{
		int real,img;
		cout<<"Add Complex Numbers\n";
		cout<<"~~~~~~~~~~~~~~~~~~~\n";

		struct Complex number1,number2,number;
		
		//Get the first complex number
		cout<<"First number - \n";
		cout<<"~~~~~~~~~~~~ - \n";
		cout<<"\n\tEnter the real part : ";
		cin>>real;
		cout<<"\n\tEnter the img part : ";
		cin>>img;
		number1.acceptComplexNumber(real,img);
		
		//Get the second complex number
		cout<<"Second number - \n";
		cout<<"~~~~~~~~~~~~~ - \n";
		cout<<"\n\tEnter the real part : ";
		cin>>real;
		cout<<"\n\tEnter the img part : ";
		cin>>img;
		number2.acceptComplexNumber(real,img);
		
		number = number.addComplexNumber(number1,number2);
		number.printComplexNumber();
		
		cout<<"\nDo you want to go again? (hit 0 to break) : ";
		cin>>choice;
		
	}while(choice);
	
	return 0;
}
