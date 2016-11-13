#include <iostream>

using namespace std;

class Stack{
	private: 
		int capacity;
		int* arr;
		int top;
	public:
		Stack(int capacity){
			capacity = capacity;
			arr = new int [capacity];
			top = -1;
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
			else return -1;
		}
};

void findGreatest(int* arr,int n){
	
	class Stack stack = Stack(n-1);
	int element;
	
	stack.pushToStack(arr[0]);
	
	for(int i = 1;i < n; i++){
		
		if(!stack.isEmpty()){
			element = stack.popFromStack(); //{11,13,12,14,21}
			while(element < arr[i]){
				cout<<"\n"<<element<<"--->"<<arr[i];
				if(stack.isEmpty())
					break;
				element = stack.popFromStack();
			}
			
			if(element > arr[i])
				stack.pushToStack(element);
		
		}
		stack.pushToStack(arr[i]);
	
	}
	while(!stack.isEmpty()){
		cout<<"\n"<<stack.popFromStack()<<"---->-1";
	}
}

int main(){
	int arr[] = {11,13,21,3};
	findGreatest(arr,4);
	return 0;
}
