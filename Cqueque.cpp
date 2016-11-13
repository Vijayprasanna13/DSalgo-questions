/*
Define an ADT CQueue (circular Queque) with required data members. Simulate the CQueue using an array of size as 10 by default, when not provided by the user,
Include functions to
 (i) Insert an element into the cqueue 
 (ii) Delete an element from the CQueue 
 (iii) Check for CQueue overflow and underflow and  display the elements in the cQueuue after every insertion and deletion.
Write a menu driven to simulate these queue opertaions.
*/

#include <iostream>

using namespace std;

class CQueue{
	private:
	int* array;
	int size;
	int rear;
	int front;
	public:
		CQueue(int s = 10){										//Class for CQueue 
			size = s;
			array = new int [size];
			front = rear = -1;
		}
		void insertToCQueuue(int value){							//Insert an element to the circular queue
			if(front == rear +1 || rear == size-1 && front == 0){	//check if CQ is empty 
				cout<<"\nCQueue OverFlow";
				return;
			}			
			else if(rear == -1){								
					front = 0;
					rear= 0;
					array[rear] = value;
					
				}
			else if(rear == size-1){
				rear = 0;
			}
			else{
				rear = rear+1;
			}
			array[rear] = value;
		}
		void deleteFromCQueue(){
			int temp_element = array[front];
			if(front == -1){						//check if CQ is empty
				cout<<"\n CQueue underflow";
				return;
			}
				
			else if(rear == front){
					rear = front = -1;
				}
			else if(front == size-1){
					front = 0;
			}
			else
				front = front+1;
			cout<<"\n"<<temp_element<<" has been deleted";
		}
		void printCQueue(){
			cout<<"\nThe CQ:\n";
			if(front == -1){
				cout<<"\nThe CQueque is empty, nothing to display\n";
				return;
			}
				
			int temp_rear = rear,temp_front = front;
			while(1){
				cout<<array[temp_front]<<"\n";
				if(temp_front == temp_rear)
					break;
				else if(temp_front == size-1)
					temp_front = 0;
				else 
					temp_front++;
			}
		}
};

int main(){
	cout<<"CQueue\n";
	cout<<"~~~~~~~~~~\n";
	int menu_choice;
	do{
		int size,menu_choice;
		cout<<"Size of the CQueue (default will be 10) : ";
		cin>>size;
		class CQueue queue = CQueue(size);
		do{
			cout<<"1.Insert 2.Delete [0 to exit] : ";
			cin>>menu_choice;
			switch(menu_choice){
				case 1: {
					int value;
					cout<<"\nEnter the value to be inserted : ";
					cin>>value;
					queue.insertToCQueuue(value);
					queue.printCQueue();
					break;
				}
				case 2:{
					queue.deleteFromCQueue();
					queue.printCQueue();
					break;
				}
			} 
		}while(menu_choice);
		cout<<"\nDo you want to go again? (0 to exit) : ";
		cin>>menu_choice;
	}while(menu_choice);
	return 0;
}
