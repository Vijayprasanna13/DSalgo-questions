#include <iostream>

using namespace std;
//1,2,4,3,6,5
void quicksort(int arr[],int left,int right){
	int i = left,j = right, pivot;
	pivot = arr[(i+j)/2];
	while(i <= j){
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot)
			j--;
		if(i <= j){
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	};
	if(left < j)
		quicksort(arr,left,j);
	if(i < right)
		quicksort(arr,i,right);
	
}

int main(){
	int size,arr[100];
	cout<<"\nEnter the size : ";
	cin>>size;
	for(int i = 0;i < size;i++)
	cin>>arr[i];
	quicksort(arr,0,size-1);
	for(int i = 0;i < size;i++)
	cout<<arr[i];
	return 0;
}
