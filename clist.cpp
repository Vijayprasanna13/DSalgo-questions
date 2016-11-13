#include <iostream>

using namespace std;

struct node{
	int data;
	node* next;
}*head = NULL;

void add_clist(){
	struct node* new_node = new struct node;
	std::cout<<"\nEnter the value : ";
	std::cin>>new_node->data;
	if(head != NULL){
		struct node* temp_head = head;
		while(temp_head->next != head)
			temp_head = temp_head->next;
		temp_head->next = new_node;
		new_node->next = head;
	}
	else 
		new_node->next = new_node; 	
	head = new_node;
}

void display_clist(){
	struct node *temp_head = head;
	do{
		std::cout<<temp_head->data<<"->";
		temp_head = temp_head->next;
	}while(temp_head != head);
}
int main(){
	int menu_choice;
	do{
		std::cout<<"\n1.Add a new element \n2.Display \n3.HEAD \nEnter choice: ";
		std::cin>>menu_choice;
		switch(menu_choice){
			case 1: 
				add_clist();break;
			case 2:
				display_clist();break;
			case 3:
				std::cout<<head->data;break;
			default:
				std::cout<<"\nInvalid choice";break;
		}
	}while(1);
	return 0;
}
