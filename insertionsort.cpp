#include <iostream>

using namespace std;

void insertionsort(int arr[], int size){
	int temp, temp_index,j, k;
	for(int i = 1;i < size;i++){
		temp = arr[i];
		for(j = i-1;j >= 0 && arr[j] > temp;j--)
			arr[j+1] = arr[j];
		arr[j+1] = temp;	
		}
}

int main(){
	int arr[100],size;
	
	cout<<"Size : ";
	cin>>size;
	for(int i = 0; i < size;i++)
		cin>>arr[i];
	
	insertionsort(arr,size);
	
	for(int i=0;i < size;i++)
	cout<<arr[i]<<" ";
	
	return 0;
}
