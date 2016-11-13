#include <iostream>
#include <cstring> 

using namespace std;

struct Stack{
	int capacity;
	int top;
	char* string;	
};

struct Stack* createStack(int capacity){
	if(struct Stack* stack = new Stack){
		stack->capacity = capacity;
		stack->top = -1;
		stack->string = new char [capacity];
		return stack;		
	}
	else 
		return NULL;
}

int isEmpty(struct Stack* stack){
	return stack->top == -1;
}

void pushToStack(struct Stack* stack,char ch){
	stack->string[++stack->top] = ch;
}

char popFromStack(struct Stack* stack){
	if(!isEmpty(stack))
		return stack->string[stack->top--];
	else return -1;
}

void reverseString(char* string){
	struct Stack* stack = createStack(strlen(string));
	int i = 0;
	while(i < strlen(string)){
		pushToStack(stack,string[i]);
		i++;
	}
	i = 0;
	while(i < strlen(string)){
		cout<<popFromStack(stack);
		i++;	
	}		
}

int main(){
	char* string = "hello world";
	reverseString(string);
	return 0;
}
