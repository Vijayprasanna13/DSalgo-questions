#include <bits/stdc++.h>
using namespace std;

class Stack{

private:
  int capacity;
  int top;
  int *arr;

public:
  Stack(int size){
    capacity = size;
    top = -1;
    arr = new int [size];
  }

  int IsEmpty(){
    return top == -1;
  }

  void Push(int value){
    if(top <= capacity)
      arr[++top] = value;
    else
      cout<<"\nSTACK OVERFLOW!!";
  }

  
  int Pop(){
    if(!IsEmpty())
      return arr[top--];
  }

  int Peek(){
    if(!IsEmpty())
      return arr[top];
  }
};

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

int infixToPostfix(char* exp)
{
  int i, k;
  Stack stack = Stack(strlen(exp));
  for (i = 0, k = -1; exp[i]; ++i)
    {
      if (isOperand(exp[i]))
	exp[++k] = exp[i];
      else if (exp[i] == '(')
	stack.Push(exp[i]);
      else if( exp[i] == ')')
        {
	  while (!stack.IsEmpty() && stack.Peek() != '(')
	    exp[++k] = stack.Pop();
	  if (!stack.IsEmpty() && stack.Peek() != '(')
	    return -1;    
	  else
	    stack.Pop();
        }
      else
        {
	  while (!stack.IsEmpty() && Prec(exp[i]) <= Prec(stack.Peek()))
	    exp[++k] = stack.Pop();
	  stack.Push(exp[i]);
        }
 
    }
  while (!stack.IsEmpty())
    exp[++k] = stack.Pop();
  exp[++k] = '\0';
  cout<<"\n"<<exp;
}

int main(){
  char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
