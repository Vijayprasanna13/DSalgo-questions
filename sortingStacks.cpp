#include <iostream>

using namespace std;

class Stack{
	private: 
		int capacity;
		int top;
		int* arr;
	public: 
		Stack(int capacity){
			capacity = capacity;
			top = -1;
			arr = new int [capacity];
		}
		
		int isEmpty(){
			return top == -1;
		}
		
		void pushToStack(int value){
			arr[++top] = value;
		}
		
		int popFromStack(){
			if(!isEmpty())
				return arr[top--];
			return -1;
		}
};

void insertSort(class Stack stack,int key){
	if(stack.isEmpty() || key > stack.popFromStack()){
		stack.pushToStack(key);
		return;
	}
	int temp = stack.popFromStack();
	insertSort(stack,key);
	
	stack.pushToStack(temp);
}

void sort(class Stack stack){
	if(!stack.isEmpty()){
		int key = stack.popFromStack();
		sort(stack);
		insertSort(stack,key);	
	}
}

int main(){
	class Stack stack = Stack(5);
	stack.pushToStack(11);
	stack.pushToStack(13);
	stack.pushToStack(12);
	stack.pushToStack(15);
	stack.pushToStack(14);
	while(!stack.isEmpty())
	cout<<stack.popFromStack()<<" ";
	return 0;
}
