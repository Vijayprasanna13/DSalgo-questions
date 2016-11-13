#include<bits/stdc++.h> 

using namespace std;

struct Node{			//structrure for Node of a tree
	int data;
	Node* right;
	Node* left;
};

struct Node* newNode(int value){		//function to create a new Node. 
	struct Node* new_node = new Node;
	new_node->data = value;
	new_node->left = new_node->right = NULL;
	return new_node;
}

struct Node* insertNode(struct Node* node,int value){	//function to insert a new node to the BST
	if(!node)	
		return newNode(value);
	else if(node->data < value)
		node->right = insertNode(node->right,value);
	else
		node->left = insertNode(node->left,value);
	return node;
}

void preOrder(struct Node* root){			//function to print the pre-order of the BST
	if(root){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);	
	}
}

void postOrder(struct Node* root){			//function to print the post-order of the BST
	if(root){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}

void inOrder(struct Node* root){			//function to print the in-order of the BST
	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

struct Node* getInorderSuccessor(struct Node* root){	//function to retrieve in order successcor
	root = root->right;
	while(root->left){
		root = root->left;
	}
	return root;	
}

struct Node* deleteNode(struct Node* root,int value){	//function to delete node from BST
	if(root == NULL)
		return root;
	if(value > root->data)
		root->right = deleteNode(root->right,value);
	else if(value < root->data)
		root->left = deleteNode(root->left,value);
	else {
		if(!root->left){
			struct Node* temp = root->right;
			delete(root);
			return temp;
		}
		else if(!root->right){
			struct Node* temp = root->left;
			delete(root);
			return temp;
		}
		else{
			struct Node* inOrderSucc = getInorderSuccessor(root);
			root->data = inOrderSucc->data;
			root->right = deleteNode(root->right,inOrderSucc->data);
		}
		return root;
	}
}

int main(){
	struct Node* root = NULL;
	int menu_choice;
	do{	
		cout<<"\n1.Insert a Node \n2.Delete a node \n3.Display the Tree \n0.Exit\n";
		cin>>menu_choice;
		switch(menu_choice){
			case 1: {
				int value;
				cout<<"\nEnter the value : ";
				cin>>value;
				root = insertNode(root,value);
				break;
			}
			case 2:{
				int value;
				cout<<"\nEnter the value to be deleted : ";
				cin>>value;
				root = deleteNode(root,value);
				break;
			}
			case 3:{
				cout<<"\nPreOrder : ";
				preOrder(root);
				cout<<"\nPostOrder : ";
				postOrder(root);
				cout<<"\nInOrder : ";
				inOrder(root);
				break;
			}
		}
	}while(menu_choice);
	return 0;
}
