#include <bits/stdc++.h>

using namespace std;

void linearSearch(int arr[],int n,int value){
	int toggle = 0;
	for(int i = 0;i < n;i++)
		if(arr[i] == value){
			toggle = i+1;
			break;
		}
	if(toggle)
		cout<<"\nElement found at : "<<toggle;
	else
		cout<<"\nElement not found!!!!!!!!!!!";
}

int main(){
	cout<<"Linear Search";
	cout<<"\n~~~~~~~~~~~~~~";
	int menu_choice;
	do{
		int arr[100],size;
		cout<<"\nEnter the size of the array : ";
		cin>>size;
		cout<<"\nEnter the array : ";
		for(int i = 0 ;i < size;i++)
		cin>>arr[i];
		int value;
		cout<<"\nEnter the value to be searched : ";
		cin>>value;
		linearSearch(arr,size,value);
		cout<<"\nDo you want to go again? (0 to exit)";
		cin>>menu_choice;
	}while(menu_choice);
	return 0;
}
