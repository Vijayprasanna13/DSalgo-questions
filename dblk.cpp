#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
}*head = NULL;



void insertFirst(int value){
	struct Node* new_node = new Node;
	if(!head){
		//First node ...
		new_node->next = new_node->prev = head;
		head = new_node;
	}
	else{
		//General insertion of head node ...
		new_node->prev = NULL;
		head->prev = new_node;
		new_node->next = head;
		head = new_node;	
	}
	new_node->data = value;
}


void insertLast(int value){
	if(!head){
		//Fisrt node insertion (call insertFirst() since operation is indentical) ...
		insertFirst(value);
	}
	else{
		//General insertion at the last ..
		struct Node* temp_head = head;
		while(temp_head->next){
			temp_head = temp_head->next; 	//temp_head contains the last node
		}
		struct Node* new_node = new Node;
		
		new_node->next = NULL;				//set new_node attributes
		new_node->prev = temp_head;
		
		temp_head->next = new_node;			//set temp_head attributes
		new_node->data = value; 
	}
}

void deleteFirst(){
	if(head->next){
	//For general head deletion ...
	struct Node* temp = head;
	head = head->next;
	head->prev = NULL;
	delete(temp);		
	}
	else{
		//if only one node is present ...
		delete(head);
		head = NULL;
	}
}

void deleteLast(){
	struct Node* temp_head = head;
	while(temp_head->next){
		temp_head = temp_head->next;   //temp_head contains last node
	}
	if(temp_head == head)			  //only one node is present (call deleteFirst() since operation is similar)
		deleteFirst();
	else{	
	temp_head->prev->next = NULL;	 //Set attributes for temp_head-1 node and free temp_head
	delete(temp_head); 
	}
}


void insertAfterValue(int primer,int value){
	if(!head){
		cout<<"\nNo list found!!";
		return;
	}
	else if(head->data == primer && !head->next){
		insertLast(value);
	}
	else{
		int toggle = 0; 	//Toggle if element is found
		struct Node* temp_head = head;
		while(temp_head){
			if(temp_head->data == primer){
				toggle++;	//hit toggle
				break;
			}
			temp_head = temp_head->next;
		}
		if(!toggle){
			cout<<"\nGiven value not found!!";
			return;
		}
		else{
			struct Node* new_node = new Node;
			new_node->data = value;
			
			new_node->prev = temp_head;
			new_node->next = temp_head->next;
			
			temp_head->next = new_node;
			temp_head->next->prev = new_node;
		}
	}
}

void deleteBeforeValue(int primer){
	if(!head){
		cout<<"\nNo list found!!";
		return;
	}
	else if(head->data == primer){
		cout<<"\nNo value before node!!";
		return;
	}
	else{
		int toggle = 0;
		struct Node* temp_head = head;
		while(temp_head){
			if(temp_head->data == primer){
				toggle++;
				break;
			}
			temp_head = temp_head->next;			
		}
		if(temp_head->prev == head){
			deleteFirst();		//If node to be deleted is head node (temp_head->prev->prev does not exist) 
		}
		else{
			struct Node* trash_node = temp_head->prev;
			temp_head->prev = temp_head->prev->prev;	//carry general node deletion for temp_head-1
			temp_head->prev->next = temp_head;
			delete(trash_node);
		}
	}
}

void countNodes(){
	int counter = 0;
	struct Node* temp_head = head;
	while(temp_head){
		counter++;
		temp_head = temp_head->next;
	}
	cout<<"\nNo of node : "<<counter;
}

void displayList(){
	cout<<"\nList :-\n";
	if(!head)
	{
		cout<<"\nEmpty List!!";
		return;
	}
	struct Node* temp_head = head;
	while(temp_head){
		cout<<temp_head->data<<"<->";
		temp_head = temp_head->next;
	}
	cout<<"\b\b\b   \n";
}

void checkOrder(){
	int toggle = 1;
	struct Node* temp_head = head;
	while(temp_head->next){
		if(!(temp_head->next->data >= temp_head->data)){
			toggle = 0;
			break;
		}
		temp_head = temp_head->next;
	}
	if(toggle){
			cout<<"\nAscending order";
			return;
		}
	temp_head = head;
	toggle= 1;
	while(temp_head->next){
		if(!(temp_head->next->data <= temp_head->data)){
			toggle = 0;
			break;
		}
		temp_head = temp_head->next;
	}
	if(toggle){
		cout<<"\nDescending order";
		return;
	}		
	else{
		cout<<"\nNo order found";
	} 
}

int main(){
	int choice;
	cout<<"\nDouble Linked List";
	cout<<"\n~~~~~~~~~~~~~~~~~~";
	do{
		cout<<"\n1.Insert at first \n2.Insert at last \n3.Insert after value  \n4.Delete first \n5.Delete last \n6.Delete before value \n7.Count nodes \n8.Check order \n9.Display \n0.exit\n";
		cout<<"\nEnter choice : ";
		cin>>choice;
		switch(choice){
			case 1: {
				int val;
				cout<<"\nValue : ";
				cin>>val;
				insertFirst(val);
				break;
			}
			case 2: {
				int val;
				cout<<"\nValue : ";
				cin>>val;
				insertLast(val);
				break;
			}
			case 3: {
				int x,val;
				cout<<"\nAfter which value?? : ";
				cin>>x;
				cout<<"\nInsert which value?? : ";
				cin>>val;
				insertAfterValue(x,val);
				break;
			}
			case 4: deleteFirst();break;
			case 5: deleteLast();break;
			case 6: {
				int x;
				cout<<"\nDelete before which value?? : ";
				cin>>x;
				deleteBeforeValue(x);
				break;
			}
			case 7: countNodes();break;
			case 8: checkOrder();break;
			case 9: displayList();break;
		}
		displayList();
	}while(choice);
	return 0;
}
