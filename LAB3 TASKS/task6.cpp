#include<iostream>
using namespace std;

class Matrix{	
	public:
		int rows;
		int cols;
		int **mat;
		Matrix(){
		}
		Matrix(int rows , int cols){
			this->rows=rows;
			this->cols=cols;
			mat = new int*[rows];
		    for(int i=0 ; i<rows ; i++){
			mat[i] = new int[cols]; 
	    	}  			
		}
		 
};

int main( int argc , char *argv[]){
	/*Error checking for rows and columns to be equivalent is not implemented
	  considering user willl enter correct input*/
	  
	int rows , cols , count=3 ;
	rows = stoi(argv[1]);
	cols = stoi(argv[2]);
	int **resultMatrix;
	resultMatrix = new int*[rows];
	for(int i=0 ; i<rows ; i++){
		resultMatrix[i] = new int[cols];
	}
	Matrix matrix[2]={Matrix(rows,cols),Matrix(rows,cols)};
	for(int k=0 ; k<2 ; k++){
		for(int i=0 ; i<rows ; i++){
			for(int j=0 ; j<cols ; j++){
			matrix[k].mat[i][j]=stoi(argv[count++]);			
		}						
	}	
  } 
		for(int i=0 ; i<rows ; i++){
			for(int j=0 ; j<cols ; j++){
				resultMatrix[i][j]=matrix[0].mat[i][j]+matrix[1].mat[i][j];
		}					
	}	
	
    cout<<"AFTER ADDITION : "<<endl;
	for(int i=0 ; i<rows ; i++){
		for(int j=0 ; j<cols ; j++){
			cout<<resultMatrix[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=0 ; i<rows ; i++){
		for(int j=0 ; j<cols ; j++){
			resultMatrix[i][j]=0;
		}
	}
	cout<<"AFTER MULTIPLICATION : "<<endl;
	for(int i=0 ; i<rows ; i++){
		for(int j=0 ; j<cols ; j++){
			for(int k=0 ; k<rows ; k++){				
				resultMatrix[i][j]+=matrix[0].mat[i][k]*matrix[1].mat[k][j];
			}
		}
	}
	for(int i=0 ; i<rows ; i++){
		for(int j=0 ; j<cols ; j++){
			cout<<resultMatrix[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	
	
		
	return 0;
}
