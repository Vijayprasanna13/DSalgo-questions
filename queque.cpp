#include <iostream>

using namespace std;

class Queque{
	private:
	int front,rear,size;
	int* arr;
	
	public:
		Queque(int temp_size){
			size = temp_size;
			front = rear = -1;
			arr = new int [size];
		}
		
		int pushToQueque(int value){
			if(rear >= size-1 ){
				cout<<"\n Queque overflow ";
			}
			else{
				if(front == -1)
					front = 0;
				arr[++rear] = value;
			}
		}
		
		int popFromQueQue(){
			if(front == -1 || front > rear)
				cout<<"\nQueque underflow";
			else{
				return arr[front++];
			}	
		}
		
		void displayQueque(){
			int temp_front = front;
			while(temp_front <= rear){
				cout<<arr[temp_front++]<<"->";
			}
			cout<<"\b\b  ";
		}
		void details(){
			cout<<"\nfront : "<<front<<"\nrear : "<<rear<<"\nsize : "<<size;
		}
};

int main(){
	int menu_choice, size;
	cout<<"\nSize?";
	cin>>size;
	class Queque queque = Queque(size);
	do{
		cout<<"\n1.Add Element \n2.POP last element \n3.Display \nEnter choice : ";
		cin>>menu_choice;
		switch(menu_choice){
			case 1:{
				int value;
				cout<<"\nEnter Element to add : ";
				cin>>value;
				queque.pushToQueque(value);
				break;
			}
			case 2:{
				cout<<"\n"<<queque.popFromQueQue();
				break;
			}
			case 3:{
				cout<<"\n";
				queque.displayQueque();
				break;
			}
			case 4:{
				queque.details();
				break;
			}
		}
	}while(1);
}

