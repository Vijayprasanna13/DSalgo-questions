#include <iostream>

using namespace std;

void selectionsort(int arr[],int size){
  int temp,k;
  for(int i =0;i < size;i++){
    temp = arr[i],k = i;
    for(int j=i+1;j < size;j++){
      if(arr[k] > arr[j]){
	k = j;	
      }
    }
    swap(arr[i],arr[k]);
  }
}

int main(){
  int arr[100],size;
	
  cout<<"\nEnter size : ";
  cin>>size;
	
  for(int i = 0;i < size;i++)
    cin>>arr[i];
	
  selectionsort(arr,size);
	
  for(int i = 0;i < size;i++)
    cout<<arr[i]<<" ";
	
  return 0;
}
