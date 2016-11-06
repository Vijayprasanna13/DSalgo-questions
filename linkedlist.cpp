#include <bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  Node* link;
};

Node* InsertNode(Node* head,int value){
  Node* newnode = new Node;
  newnode->data = value;
  newnode->link = head;
  head = newnode;
}

void Display(Node* head){
  cout<<"\n";
  while(head){
    cout<<head->data<<" ";
    head = head->link;
  }
}

Node* Reverse(Node* head){
  Node* previous = NULL,*next;
  while(head){
    next = head->link;
    head->link = previous;
    previous = head;
    head = next;
  }
  return previous;
}
/*
STACK OPERATIONS
*/
Node* PushToStack(Node* stack,int value){
  return InsertNode(stack,value);
}

Node* PopFromStack(Node* stack){
  cout<<"\n"<<stack->data;
  return stack->link;
}

int IsEmpty(Node* stack){
  return stack == NULL;
}

void DisplayStack(Node* stack){
  Node* temp = stack;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->link;
  }  
}

int main(){
  int menu_choice;
  Node* head = NULL;
  do{
    cout<<"\n1.Insert 2.Display 3.Reverse\n 4.Make Stack";
    cout<<"\nEnter the choice : ";
    cin>>menu_choice;
    switch(menu_choice){
    case 1:{
      int value;
      cout<<"\nEnter the value : ";
      cin>>value;
      head = InsertNode(head,value);
      break;
    }
    case 2:{
      Display(head);
      break;
    }
    case 3:{
      head = Reverse(head);
      Display(head);
      break;
    }
    case 4:{
      int choice;
      Node* stack = NULL;
      do{
	cout<<"\nSTACK OPERATIONS\n";
	cout<<"~~~~~~~~~~~~~~~~\n";
	cout<<"\n1.Push 2.Pop 3.Display";
	cout<<"\nEnter choice (0 to exit) : ";
    	cin>>choice;
	switch(choice){
	case 1:{
	  int value;
	  cout<<"\nEnter value : ";
	  cin>>value;
	  stack = InsertNode(stack,value);
	  break;
	}
	case 2:{
	  cout<<"\nPopped value :  ";
	  stack = PopFromStack(stack);
	  break;
	}
	case 3:{
	  DisplayStack(stack);
	}
	}
      }while(choice);
      break;
    }
    }
  }while(menu_choice);
  return 0;
}
