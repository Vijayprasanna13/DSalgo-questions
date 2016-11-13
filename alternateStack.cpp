#include <iostream>
using namespace std;

class Stack{
	int* array;
	int size;
	int top1;
	int top2;
	public:
		Stack(int size){
			size = size;
			top1 = -2;
			top2 = -1;
			array = new int [size];
		}
		int isEmptyEven(){
			return top1 == -2;
		}
		int isEmptyOdd(){
			return top2 == -1;
		}
		void pushToStackEven(int value){
			top1+=2;
			array[top1] = value;
		}
		void pushToStackOdd(int value){
			top2+=2;
			array[top2] = value;
		}
		void printEvenFromStack(){
			int temp_top = top1;
			while(temp_top >= 0){
				cout<<array[temp_top]<<"\n";
				temp_top -= 2;
			}
		}
		void printOddFromStack(){
			int temp_top = top2;
			while(temp_top >= 1){
				cout<<array[temp_top]<<"\n";
				temp_top -= 2;
			}
		}
};

int main(){
	class Stack stack = Stack(10);
	stack.pushToStackEven(2);
	stack.pushToStackOdd(3);
	stack.pushToStackEven(4);
	stack.pushToStackOdd(3);
	stack.pushToStackOdd(3);
	stack.pushToStackEven(6);
	stack.pushToStackEven(8);
	stack.pushToStackEven(10);
	stack.printEvenFromStack();
	stack.printOddFromStack();
	return 0;
}
