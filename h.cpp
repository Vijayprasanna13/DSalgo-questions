#include <iostream>
using namespace std;

void draw(int i,int n){
	if(i > n*n)
		return;
	else if(i%n < (i/n+1))
		cout<<"*";
	if(i%n == 0)
		cout<<"\n";
	draw(++i,n);
}

int main(){
	draw(1,4);
	return 0;
}
