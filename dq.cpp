#include <bits/stdc++.h>
using namespace std;

struct DQ{
	int data;
	DQ* next;
}*head = NULL;

int isEmpty(){
	return head == NULL;
}

void insertLast(){
	struct DQ* new_node = new DQ;
	cout<<"\nEnter Data : ";
	cin>>new_node->data;
	new_node->next = head;
	head = new_node;	
}

		
void insertFirst(){
	if(!head)
		insertLast();
	else{
		struct DQ* temp_head = head;
		while(temp_head->next != NULL){
			temp_head = temp_head->next;
		}
		struct DQ* new_node = new DQ;
		new_node->next = NULL;
		temp_head->next = new_node;
		cout<<"\nEnter Data : ";
		cin>>new_node->data;
	}
}
		
void deleteLast(){
	if(isEmpty()){
		cout<<"\nDQ is Empty!!";
		return;
	}
	struct DQ* temp = head;
	head = head->next;
	delete(temp);
}
		
void deleteFirst(){
	if(isEmpty()){
		cout<<"\nDQ is Empty!!";
		return;
	}
	struct DQ* temp_head = head;
	if(head->next == NULL)
		deleteLast();
	else{	
		while(temp_head->next->next != NULL){
		temp_head = temp_head->next;				
		}
		struct DQ* t = temp_head->next;
		temp_head->next = NULL;
		delete(t);
	}
}
		
void displayDQ(){
	if(isEmpty()){
		cout<<"\nDQ is Empty!!";
		return;
	}
	cout<<"\n";
	struct DQ* temp_head = head;
	while(temp_head){
		cout<<temp_head->data<<"--";
		temp_head = temp_head->next;
		}
	cout<<"\b\b  ";
}

int main(){
	struct DQ dq;
	int menu;
	do{
		int menu_choice;
		cout<<"\n1.Insert an element at the first \n2.Insert an element at the last \n3.Delete last element \n4.Delete first element \n5.Display \n0.Exit";
		cout<<"\nEnter Choice : ";
		cin>>menu_choice;
		switch(menu_choice){
			case 1: insertLast();displayDQ();break;
			case 2: insertFirst();displayDQ();break;
			case 3: deleteFirst();displayDQ();break;
			case 4: deleteLast();displayDQ();break;
			case 5: displayDQ();break;
			case 0: break;
		}
		menu = menu_choice;
	}while(menu);
	return 0;
}
