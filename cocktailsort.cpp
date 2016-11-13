#include <iostream>

using namespace std;


int main(){
int arr[100], size;
 
cout<<"\nenter the size : ";
cin>>size;
 
cout<<"\nEnter the elements : ";
for(int i = 0;i<size;i++)
 	cin>>arr[i];

//for(int i = 0;i < size;i++)
// cout<<arr[i]<<" ";
  
 
int swapped = 0;

do{
	
 swapped = 0;
 for(int i=0; i<=size-2;i++){
 	if(arr[i] > arr[i+1]){
		swap(arr[i],arr[i+1]);
 		swapped = 1;
		 for(int j = 0;j < size;j++)
		 cout<<arr[j]<<" ";
		 cout<<"\n";
 
	 }
 	}	
 if(swapped == 0)
  break;
 
 for(int i = size-2;i >= 0;i--){
 	if(arr[i]>arr[i+1]){
 		swap(arr[i],arr[i+1]);
 		swapped = 1;
		 for(int j = 0;j < size;j++)
		 cout<<arr[j]<<" ";
		 cout<<"\n";
		 
	 }
 }
 }while(swapped);
 for(int i = 0;i < size;i++)
 cout<<arr[i]<<" ";
 return 0;
}
