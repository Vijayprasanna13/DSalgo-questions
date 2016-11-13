#include <iostream>

using namespace std;

class twoStacks{
	private: 
		int top1;
		int top2;
		int *arr;
		int size;
	public:
		twoStacks(int size){
			size = size;
			top1 = -1;
			top2 = size;
			arr = new int [size];
		}
		
		void pushTo1(int value){
			if(top1 > top2 - 1){
				cout<<"\nStack overflow";
			}
			else{
				arr[++top1] = value;
			}
		}
		
		void pushTo2(int value){
			if(top2-1 < top1){
				cout<<"\nStack overflow";
			}
			else{
				arr[--top2] = value;
			}
		}
		
		int popFrom1(){
			return (top1 == -1)? top1: arr[top1--]; 
		}
		
		int popFrom2(){
			return (top1 > size)? -1: arr[top2++];
		}
};

int main(){
	int size_1,size_2;
	cout<<"\nEnter the size of the stack 1 : ";
	cin>>size_1;
	cout<<"\nEnter the size of the stack 2 : ";
	cin>>size_2;
	class twoStacks stack = twoStacks(size_1 + size_2);
	int menu_choice;
	do{
		cout<<"\n1.Add to first stack\n2.Add to second stack\n3.pop from first stack\n.pop from second stack \nEnter the choice : ";
		cin>>menu_choice;
		switch(menu_choice){
			case 1: {
				int value;
				cout<<"\nEnter the value : ";
				cin>>value;
				stack.pushTo1(value);
				break;
			}
			case 2: {
				int value;
				cout<<"\nEnter the value : ";
				cin>>value;
				stack.pushTo2(value);
				break;
			}
			case 3: {
				cout<<"\n"<<stack.popFrom1();
				break;
			}
			case 4: {
				cout<<"\n"<<stack.popFrom2();
				break;
			}
			default: cout<<"\nInvalid choice";
		}
	}while(1);	
	return 0;
}
