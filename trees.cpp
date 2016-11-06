#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* right;
  Node* left;
};

Node* CreateNode(int value){
  Node* temp = new Node;
  temp->data = value;
  temp->right = temp->left = NULL;
  return temp;
}

Node* InsertToTree(Node* root,int value){
  if(!root)
    return CreateNode(value);
  else{
    if(value > root->data)
      root->right = InsertToTree(root->right,value);
    else if(value < root->data)
      root->left = InsertToTree(root->left,value);
    else{
      cout<<"\bThis value is already present in the Tree!!";
    }
    return root;
  }
}

void Preorder(Node* root){
  if(root){
    cout<<" "<<root->data;
    Preorder(root->left);
    Preorder(root->right);
  }
}

void Postorder(Node* root){
  if(root){
    Postorder(root->left);
    Postorder(root->right);
    cout<<" "<<root->data;
  }
}

void Inorder(Node* root){
  if(root){
    Inorder(root->left);
    cout<<" "<<root->data;
    Inorder(root->right);
  }
}

Node* CreateCopy(Node* root){
  Node* temp = NULL;
  if(root){
    temp = new Node;
    temp->data = root->data;
    temp->left = CreateCopy(root->left);
    temp->right = CreateCopy(root->right);
  }
  return temp;
}

Node* FindInorderSucc(Node* root){
  if(root){
    while(root->left)
      root = root->left;
  }
  return root;
}

Node* DeleteValue(Node* root,int value){
  if(!root)
    return NULL;
  else if(value > root->data)
    root->right = DeleteValue(root->right,value);
  else if(value < root->data)
    root->left = DeleteValue(root->left,value);
  else{
    if(!root->left){
      Node* temp = root->right;
      delete(root);
      return temp;
    }
    else if(!root->right){
      Node* temp = root->left;
      delete(root);
      return temp;
    }
    Node* inordersucc = FindInorderSucc(root->right);
    root->data = inordersucc->data;
    root->right = DeleteValue(root->right,inordersucc->data);
  }
  return root;
}

Node* CreateMirror(Node* root){
  Node* temp = NULL;
  if(root){
    temp = new Node;
    temp->data = root->data;
    temp->left = CreateMirror(root->right);
    temp->right = CreateMirror(root->left);
  }
  return temp;
}

int main(){
  int menu_choice;
  Node* root = NULL,*temproot = NULL;
  do{
    cout<<"\n1.Insert 2.Orders 3.Copy 4.Mirror";
    cout<<"\nEnter the choice : ";
    cin>>menu_choice;
    switch(menu_choice){
    case 1:{
      int value;
      do{
	cout<<"\nEnter the value to be inserted : (type 0 to stop)";
	cin>>value;
	if(value)
	  root = InsertToTree(root,value);
      }while(value);
      break;
    }
    case 2: {
      cout<<"\nInOrder : ";Inorder(root);
      cout<<"\nPreOrder : ";Preorder(root);
      cout<<"\nPostOrder : ";Postorder(root);
      break;
    }
    case 3: {
      cout<<"\nCopied!";
      cout<<"Original Tree -\n ";
      cout<<"\nInOrder : ";Inorder(root);
      cout<<"\nPreOrder : ";Preorder(root);
      cout<<"\nPostOrder : ";Postorder(root);
      temproot = CreateCopy(root);
      cout<<"\nDuplicate Tree -\n ";
      cout<<"\nInOrder : ";Inorder(temproot);
      cout<<"\nPreOrder : ";Preorder(temproot);
      cout<<"\nPostOrder : ";Postorder(temproot);
      break;
    }
    case 4:{
      Node* temp = CreateMirror(root);
      cout<<"\nCopied!";
      cout<<"Original Tree -\n ";
      cout<<"\nInOrder : ";Inorder(root);
      cout<<"\nPreOrder : ";Preorder(root);
      cout<<"\nPostOrder : ";Postorder(root);
      cout<<"\nMirror Tree -\n ";
      cout<<"\nInOrder : ";Inorder(temp);
      cout<<"\nPreOrder : ";Preorder(temp);
      cout<<"\nPostOrder : ";Postorder(temp);
    }
    case 5:{
      int value;
      cout<<"\nEnter the value to be delete : ";
      cin>>value;
      root = DeleteValue(root,value);
    }
    case 0:{
      break;
    }
    }
  }while(menu_choice);
  return 0;
}
