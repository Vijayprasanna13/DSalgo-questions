#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[],int m,int l,int r){
  int n1 = m - l + 1, n2 = r - m, leftarray[n1], rightarray[n2], k = l;
  for(int i = 0;i < n1; i++)
    leftarray[i] = arr[l + i];
  for(int j = 0;j < n2; j++)
    rightarray[j] = arr[m + 1 + j];
  int i = 0, j = 0;
  while(i < n1 && j < n2){
    if(leftarray[i] < rightarray[j])
      arr[k++] = leftarray[i++];
    else
      arr[k++] = rightarray[j++];
  }
  while(i < n1)
    arr[k++] = leftarray[i++];
  while(j < n2)
    arr[k++] = rightarray[j++];
}

void MergeSort(int arr[],int l,int r){
  if(l < r){
    int mid = (l+r)/2;
    MergeSort(arr,l,mid);
    MergeSort(arr,mid+1,r);
    Merge(arr,mid,l,r);
  }
}

int main(){
  int arr[100], n;
  cout<<"\nEnter the number of elements : ";
  cin>>n;
  for(int i = 0;i < n;i++)
    cin>>arr[i];
  MergeSort(arr,0,n-1);
  cout<<"\nSorted Array : ";
  for(int i = 0;i < n;i++)
    cout<<" "<<arr[i];
  cout<<"\n";
  return 0;
}
