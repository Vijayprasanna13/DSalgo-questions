#include <bits/stdc++.h>
using namespace std;

int get_maximum_element(int arr[], int n)
{
    int temp_max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > temp_max)
            temp_max = arr[i];
    return temp_max;
}
 
void counter(int arr[], int n, int bit)
{
    int result[n]; 
    int i, index[10] = {0};
    for (i = 0; i < n; i++)
        index[ (arr[i]/bit)%10 ]++;
    for (i = 1; i < 10; i++)
        index[i] += index[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        result[index[ (arr[i]/bit)%10 ] - 1] = arr[i];
        index[ (arr[i]/bit)%10 ]--;
    } 
    for (i = 0; i < n; i++)
        arr[i] = result[i];
}


void radixSort(int arr[], int n)
{
    int max = get_maximum_element(arr, n); 
    for (int bit = 1; max/bit > 0; bit*=10)
        counter(arr, n, bit);
}

void displayArray(int arr[],int n){
	cout<<"\n";
	for(int i = 0;i < n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
 
int main() {
	int menu_choice;
	cout<<"RADIX SORT\n";
	cout<<"~~~~~~~~~~~";
	do{
		int arr[100];
		int size;
		cout<<"\nEnter the size of the array : ";
		cin>>size;
		cout<<"\Enter the array : ";
		for(int i = 0;i < size;i++)
			cin>>arr[i];
		radixSort(arr,size);
		displayArray(arr,size);
		cout<<"\nDo you want to go again? (0 to exit)";
		cin>>menu_choice;
	}while(menu_choice);
	return 0;
}

