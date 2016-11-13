#include <iostream>
using namespace std;
class Matrix{
	private:
		int matrix[50][50];
		int row;
		int column;
	public:
		Matrix(int m,int n){
			row = m;
			column = n;
			for(int i = 0;i < row; i++){
				for(int j = 0; j < column; j++)
				cin>>matrix[i][j];
				//cout<<"\n";
			}
		}
		void printMatrix(){
			cout<<"\nThe Matrix : \n";
			for(int i = 0;i < row; i++){
				for(int j = 0; j < column; j++)
				cout<<matrix[i][j]<<" ";
				cout<<"\n\n";
			}
		} 
		
		int checkFeasability(class Matrix matrix1,class Matrix matrix2){
			return (matrix1.row == matrix2.row && matrix1.column == matrix2.column);
		}
		
		void subtract(class Matrix matrix1,class Matrix matrix2){
			//class Matrix matrix = Matrix(matrix1.row,matrix1.column);
			cout<<"The subtracted matrix : \n";
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~\n";
			for(int i = 0;i < matrix1.row;i++){
				for(int j = 0;j < matrix1.column;j++)
					cout<<matrix1.matrix[i][j] - matrix2.matrix[i][j]<<" ";
					cout<<"\n";
				}
			//printMatrix();
		}   		
};

int main(){
	int choice;
	do{	
		int row,column;
		//accept the first matrix
		cout<<"\nThe first matrix";
		cout<<"\n~~~~~~~~~~~~~~~~";
		cout<<"\nEnter the number of rows : ";
		cin>>row;
		cout<<"\nEnter the number of column : ";
		cin>>column;
		class Matrix matrix1 = Matrix(row,column);
		matrix1.printMatrix();
		//accept the second matrix
		cout<<"\nThe second matrix : ";
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\nEnter the number of rows : ";
		cin>>row;
		cout<<"\nEnter the number of column : ";
		cin>>column;
		class Matrix matrix2 = Matrix(row,column);
		matrix2.printMatrix();
		
		if(matrix1.checkFeasability(matrix1,matrix2)){
			cout<<"\nSubtraction possible : \n";
			matrix1.subtract(matrix1,matrix2);
		}
		else 
			cout<<"\nSubtraction not possible";
			cout<<"\nDo you want to go again? (hit 0 to break) : ";
			cin>>choice;
		
	}while(choice);
	return 0;
}
