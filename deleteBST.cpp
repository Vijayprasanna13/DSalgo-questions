#include<bits/stdc++.h> 

using namespace std;

struct Node{
	int data;
	Node* left = NULL;
	Node* right = NULL;
}*root = NULL;

void insertToTree(struct Node* temp_root,int value){
	if(!root){
		struct Node* new_node = new Node;
		new_node->data = value; 
		new_node->right = new_node->left = NULL;
		root = new_node;
		return;
	}
	else if(temp_root->data < value){
		if(!temp_root->right){
				struct Node* new_node = new Node;
				new_node->data = value; 
				temp_root->right = new_node;

				return;
		}
		else
			insertToTree(temp_root->right,value);
	}
	else{
		if(!temp_root->left){
			struct Node* new_node = new Node;
			new_node->data = value; 
			temp_root->left = new_node;
			return;
		}
		else
			insertToTree(temp_root->left,value);
	}
}	

void inOrder(struct Node* temp_root){
	if(!temp_root){
		return;
	}
	else{
		inOrder(temp_root->left);
		cout<<" "<<temp_root->data;
		inOrder(temp_root->right);
	}
}

void preOrder(struct Node* temp_root){
	if(!temp_root){
		return;
	}
	else{
		cout<<" "<<temp_root->data;
		preOrder(temp_root->left);
		preOrder(temp_root->right);
	}
}

void postOrder(struct Node* temp_root){
	if(!temp_root){
		return;
	}
	else{
		postOrder(temp_root->left);
		postOrder(temp_root->right);
		cout<<" "<<temp_root->data;
	}
}

struct Node *findInorder(Node* temp_root){
	temp_root = temp_root->right;
	if(temp_root)
		while(temp_root->left){
			temp_root = temp_root->left;
		}
	return temp_root;
}

struct Node *findNode(Node* temp_root,int value){
	while(temp_root){
		//cout<<temp_root->data<<"\n";
		if(temp_root->data == value){
			return temp_root;
		}
		if(temp_root->data < value){
			temp_root = temp_root->right;
		}
		else temp_root = temp_root->left;
	}
	return NULL;
}

void deleteSucc(struct Node* temp_root,struct Node* val){
	if(!temp_root){
		return;
	}
	else{
		deleteSucc(temp_root->left,val);
		deleteSucc(temp_root->right,val);
		if(temp_root->right && temp_root->right == val)
			temp_root->right = NULL;
		else 
			temp_root->left = NULL;
	}
}

void deleteNode(struct Node* temp_root,int value){
	struct Node* target_node = findNode(temp_root,value);
	if(target_node){
		
		//struct Node* trash_node = target_node;
		if(target_node == root){
			cout<<"Cannot be Deleted";
		}
		else if(target_node->left && target_node->right){
			struct Node* inOrder_succ = findInorder(target_node);
			target_node->data = inOrder_succ->data;
			target_node->right->left = inOrder_succ->right;
			deleteSucc(root,inOrder_succ);			
		}
		else if(target_node->left){
			target_node->data = target_node->left->data;
			target_node->left = NULL;
		}
		else if(target_node->right){
			target_node->data = target_node->right->data;
			target_node->right = NULL;
		}
		else if(!target_node->left && !target_node->right)
		{
			struct Node* temp = target_node;
			delete(temp);
		}
	}	
}

int main(){
	cout<<"DELETION AND UPDATION\n";
	cout<<"~~~~~~~~~~~~~~~~~~~~~";
	int menu_choice;
	do{
		cout<<"\n1.Insert to tree \n2.Delete from Tree \n3.De \n0.Exit\n";
		cin>>menu_choice;
		switch(menu_choice){
			case 1: {
				int val;
				cout<<"\nEnter the Value  : ";
				cin>>val;
				insertToTree(root,val);
				break;
			}
			case 2:{
				int val;
				cout<<"Deletion value : ";
				cin>>val;
				deleteNode(root,val);
				break;
			}
			case 3:{
				cout<<"\nPOST ORDER : ";
				postOrder(root);
				cout<<"\n IN ORDER : ";
				inOrder(root);
				cout<<"\n PRE ORDER : ";
				preOrder(root);
				break;
			}
		}
	}while(menu_choice);
}



