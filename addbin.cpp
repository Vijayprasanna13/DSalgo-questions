#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
}*head=NULL;

void add(int val){
	Node* new_node = new Node;
	new_node->data = val;
	new_node->next = head;
	head = new_node;
}

int bin(Node* tmp_head){
	if(!tmp_head)
		return tmp_head->data;
	else{
		int temp = bin(tmp_head->next);
		int r;
		r = tmp_head->data && temp;
		tmp_head->data = tmp_head->data^temp;
		return r;
	}
}

void display(){
	Node* temp = head;
	while(temp){
		cout<<temp->data;
		temp = temp->next;
	}
}

int main(){
	add(1);
	add(1);
	add(1);
	display();
	bin(head);
	display();
	return 0;
}
