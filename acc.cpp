#include <iostream>
#include <cstring>
using namespace std;

class Stack{
	int size;
	int top;
	char *array;
	public:
		Stack(int s){
			size = s;
			top = -1;
			array = new char [s];
		}
		
		void pushToStack(char value){
			array[++top] = value;
		}
		
		char popFromStack(){
			return array[top--];
		}
		
		int isEmpty(){
			return top == -1;
		}
		void flipInStack(){
			char temp1 = popFromStack();
			char temp2 = popFromStack();
			pushToStack(temp1);
			pushToStack(temp2);			
		}

};

char *findType(char value){
	switch(value){
		case '+':	return "ADD";
		case '-':	return "SUB";
		case '*':	return "MUL";
		case '/':	return "DIV";
		default :	return "NUM";
	}
}

int main(){
	char expression[] = "AB+CB-*";
	class Stack numberStack = Stack(10);
	class Stack tempStack = Stack(10);
	int rNumber = 0,tNumber = 0;
	for(int i=0;expression[i];i++){
		if(!strcmp(findType(expression[i]),"NUM"))
			numberStack.pushToStack(expression[i]);
		else if(strcmp(findType(expression[i]),"NUM") && !numberStack.isEmpty()){
				if(!rNumber){
					if(!strcmp(findType(expression[i]),"DIV") || !strcmp(findType(expression[i]),"SUB") )
						numberStack.flipInStack();
					cout<<"\nMOV R"<<rNumber+1<<", #"<<numberStack.popFromStack();
					cout<<"\nMOV Acc, R"<<rNumber+1;
					i--;
				}
				else{
					cout<<"\nMOV R"<<rNumber+1<<", #"<<numberStack.popFromStack();
					cout<<"\n"<<findType(expression[i])<<" R"<<rNumber+1;			
				}
				rNumber++;			
		}
		if(i == strlen(expression)-1){
			int tempTNumber = 0;
			while(tempTNumber < tNumber){
				if(!tempTNumber)
					cout<<"\nMOV Acc, T"<<tempTNumber+1;
				else{
					cout<<"\nMOV R"<<rNumber+1<<", T"<<tempTNumber+1;
					cout<<"\n"<<findType(expression[i])<<" R"<<rNumber+1;
					rNumber++;
				}
				tempTNumber++;
			}
			cout<<"\nSTA T"<<++tempTNumber<<", Acc";
		}
		else if(numberStack.isEmpty()){					
				//tempStack.pushToStack(++tNumber);
				cout<<"\nSTA T"<<++tNumber<<", Acc";
				rNumber = 0;
		}
	}
	return 0;
}

