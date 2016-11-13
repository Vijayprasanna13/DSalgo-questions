#include<bits/stdc++.h> 

using namespace std;

struct Node{
	int data;
	Node* left = NULL;
	Node* right = NULL;
}*root = NULL,*new_root = NULL;

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

void createCopy(struct Node* temp_root){
	if(!temp_root){
		return;
	}
	else{
		insertToTree(root,temp_root->data);
		createCopy(temp_root->left);
		createCopy(temp_root->right);
	}	
}

int main(){
	cout<<"BST\n";
	cout<<"~~~\n";
	int choice;
	do{
	cout<<"\n1.Insert to tree 2.Display original Tree 3.Copy  4.Display copied tree 0.Exit\n";
	cin>>choice;	
	switch(choice){
		case 1:{
			do{	
				int value;
				cout<<"element : ";
				cin>>value;
				insertToTree(root,value);
				cout<<"element inserted. insert another? (0 to exit) : ";
				cin>>choice;
			}while(choice);
			choice = 1;			
			break;
		}
		case 2: postOrder(root);break;
		case 3: {
			struct Node* temp_root = root;
			root = NULL;
			createCopy(temp_root);
			new_root = root;
			root = temp_root;
			cout<<"Copied Tree : \n Post Order : ";
			postOrder(new_root);
			cout<<"\n Pre Order : ";
			preOrder(new_root);
			cout<<"\n In Order : ";
			inOrder(new_root);
			cout<<"\nactual Tree : \n Post Order : ";
			postOrder(root);
			cout<<"\n Pre Order : ";
			preOrder(root);
			cout<<"\n In Order : ";
			inOrder(root);
			break;
		}
		case 4:postOrder(new_root);break;
	}
	}while(choice);	
	return 0;
}
