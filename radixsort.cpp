#include <bits/stdc++.h>
using namespace std;

int FindMax(int arr[],int n){
  int max = arr[0];
  for(int i = 1;i < n;i++)
    if(max < arr[i])
      max = arr[i];
  return max;
}

void CountSort(int arr[],int n,int exp){
  int output[n],count[10] = {0};
  for(int i = 0;i < n;i++)
    count[(arr[i]/exp)%10]++;
  for(int i = 1;i < 10;i++)
    count[i] += count[i-1];
  for(int i = n-1;i >= 0;i--){
    output[count[(arr[i]/exp)%10]-1] = arr[i];
    count[(arr[i]/exp)%10]--;
  }
  for(int i = 0;i < n;i++)
    arr[i] = output[i];
}

void RadixSort(int arr[],int n){
  int max = FindMax(arr,n);
  for(int exp = 1;max/exp > 0;exp *= 10){
    CountSort(arr,n,exp);
  }
}

int main(){
  int arr[100],n;
  cout<<"\nEnter the number of elements : ";
  cin>>n;
  for(int i = 0;i < n;i++)
    cin>>arr[i];
  RadixSort(arr,n);
  cout<<"\nSorted array : ";
  for(int i = 0;i < n;i++)
    cout<<arr[i]<<" ";
  cout<<"\n";
  return 0;
}
