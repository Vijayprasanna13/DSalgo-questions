#include <cstring>
#include <algorithm>
#include <iostream>
 
// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
struct Stack* createStack(int capacity){
 	struct Stack* stack = new Stack;
 	if (!stack) 
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
 
    stack->array = new int [capacity];
 
    if (!stack->array)
        return NULL;
    return stack;
}

int isEmpty(struct Stack* stack){
	return stack->top == -1;
}

void pushToStack(struct Stack* stack,char element){
	stack->array[++stack->top] = element;
}

char popFromStack(struct Stack* stack){
	if(!isEmpty(stack))
		return stack->array[stack->top--];
	else 
		return '$';	
}

char peekFromStack(struct Stack* stack){
	 return stack->array[stack->top];
}

int Prec(char ch){
	switch(ch){
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
	}
	return -1;
}

int isOperand(char ch){
	return (ch>= 'a' && ch<='z') || (ch<='A' && ch>='Z');
}

void infixToPostfix(char* exp){
	int i,k = -1;
	struct Stack* stack = createStack(strlen(exp));
	if(!stack)
		return;
		
	for(i = 0; exp[i] ;i++){
		
		if(isOperand(exp[i]))
			exp[++k] = exp[i];
		
		else if(exp[i] == '(')
			pushToStack(stack,exp[i]);
		
		else if(exp[i] == ')'){
			while(!isEmpty(stack) && peekFromStack(stack) != '(')
				exp[++k] = popFromStack(stack);
			if(!isEmpty(stack) && peekFromStack(stack) != '(')
				return;
			else
				popFromStack(stack);
		}
		
		else{
			while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peekFromStack(stack)))
                exp[++k] = popFromStack(stack);
            pushToStack(stack, exp[i]);
		}
	
	}
	while(!isEmpty(stack))
		exp[++k] = popFromStack(stack);
	exp[++k] = '\0';
	std::cout<<exp;
}

int main(){
	std::string s;
	std::getline(std::cin,s);
	reverse(s.begin(), s.end());
	std::cout<<"\n"<<s;
	char exp[] = "c*(a+b)";
	infixToPostfix(exp);
	return 0;
}
