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

/*
QUEUE OPERATIONS
*/
Node* PushToQueue(Node* queue,int value){
  if(!queue){
    Node* newnode = new Node;
    newnode->data = value;
    newnode->link = queue;
    queue = newnode;
    return queue;
  }
  else{
    Node* newnode = new Node,*temp = queue;
    while(queue->link)
      queue = queue->link;
    newnode->data = value;
    queue->link = newnode;
    newnode->link = NULL;
    return temp;
  }
}

void DisplayQueue(Node* queue){
  if(!IsEmpty(queue))
    while(queue){
      cout<<queue->data<<" ";
      queue = queue->link;
    }
  else
    cout<<"\nNothing to diplay!";
}

Node* PopFromQueue(Node* queue){
  if(!IsEmpty(queue)){
  cout<<"Element popped is : "<<queue->data;
  return queue->link;
  }
}

/*
DOUBLE ENDED QUEUE
*/
Node* PushToQueueFront(Node* queue,int value){
  return PushToStack(queue,value);
}

Node* PopFromQueueBack(Node* queue){
  if(!IsEmpty(queue)){
    if(!queue->link){
      queue = PopFromQueue(queue);
      return queue;
    }
    else{
      Node* temp = queue;
      while(queue->link)
	queue = queue->link;
      cout<<"Popped element is : "<<queue->data;
      queue->link = NULL;
      return temp;
    }
  }
}

int main(){
  int menu_choice;
  Node* head = NULL;
  do{
    cout<<"\n1.Insert 2.Display 3.Reverse 4.Make Stack 5.Make Queue 6.Make Double Ended Queue";
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
    case 5:{
      int choice;
      Node* queue = NULL;
      do{
      cout<<"\nQUEUE OPERATIONS\n";
      cout<<"~~~~~~~~~~~~~~~~~\n";
      cout<<"1.Push 2.Display 3.Pop\n";
      cout<<"\nEnter the choice : ";
      cin>>choice;
      switch(choice){
      case 1: {
	int value;
	cout<<"\nEnter the value : ";
	cin>>value;
	queue = PushToQueue(queue,value);
	break;
      }
      case 2:{
	DisplayQueue(queue);
	break;
      }
      case 3:{
	queue = PopFromQueue(queue);
	break;
      }
      }	
      }while(choice);
      break;
    }
    case 6:{
      int choice;
      Node* queue = NULL;
       do{
      cout<<"\nDOUBLE ENDED QUEUE OPERATIONS\n";
      cout<<"~~~~~~~~~~~~~~~~~\n";
      cout<<"1.Push(Back) 2.Push(Front) 3.Pop(Front) 4.Pop(Back) 5.Display\n";
      cout<<"\nEnter the choice : ";
      cin>>choice;
      switch(choice){
      case 1: {
	int value;
	cout<<"\nEnter the value : ";
	cin>>value;
	queue = PushToQueue(queue,value);
	break;
      }
      case 2:{
	int value;
	cout<<"\nEnter the value : ";
	cin>>value;
	queue = PushToQueueFront(queue,value);
	break;
      }
      case 3:{
	queue = PopFromQueue(queue);
	break;
      }
      case 4:{
	queue = PopFromQueueBack(queue);
	break;
      }
      case 5:{
	Display(queue);
	break;
      }
      }	
      }while(choice);
      break;
    }
    }
  }while(menu_choice);
  return 0;
}
