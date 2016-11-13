#include <iostream>

using namespace std;

struct Stack{
	int capacity;
	int top;
	int* arr;
};

struct Stack* createStack(int capacity){
	struct Stack* stack = new Stack;
	stack->capacity = capacity;
	stack->top = -1;
	stack->arr = new int [capacity];
	return stack;
}

void addToStack(struct Stack* stack){
	cout<<"\nEnter data : ";
	cin>>stack->arr[++stack->top];	
}

void displayStack(struct Stack* stack){
	int i = stack->top;
	while(i >= 0){
		cout<<stack->arr[i--]<<"\n^\n";
	};
}

void deleteFromStack(struct Stack* stack){
	int key,i = stack->top,j;
	cout<<"\nElement to be deleted : ";
	cin>>key;
	while(stack->arr[i] != key && i >= 0){
		j = i;
		while(j < stack->top){
			stack->arr[j] = stack->arr[++j];
		};
		stack->top--;
		i--;		
	};
}

void getTopFromStack(struct Stack* stack){
	if(stack->top == -1)
	 cout<<"\nStack Empty";
	else
	 cout<<stack->arr[stack->top];
}

int main(){
	struct Stack* stack = new Stack;
	int capacity,menu_choice;
	cout<<"\nEnter the size of the stack : ";
	cin>>capacity;
	stack = createStack(capacity);
	do{
	cout<<"\n1.Add a element\n2.Display Stack\n3.Delete a element\nEnter your choice : ";
	cin>>menu_choice;
	switch(menu_choice){
		case 1:addToStack(stack);break;
		case 2:displayStack(stack);break;
		case 3:deleteFromStack(stack);break;
		default: cout<<"\nInvalid Choice";
	}
	}while(1);
	
}
