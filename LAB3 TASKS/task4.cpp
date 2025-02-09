#include<iostream>
#include<string>
using namespace std;

class Employee{
	public : 	 
	 string FirstName;
	 string LastName;
	 double salary;		 	 
};

void EmployeeTest(class Employee E[] , int n){
	for(int i=0 ; i<n ; i++){
		cout<<E[i].salary<<endl;			
	}
}

int main( int argc , char *argv[]){
	class Employee e[2];
	int count=0, n=2;
	for(int i=0 ; i<n ; i++){
		e[i].FirstName=argv[++count];
		e[i].LastName=argv[++count];
		e[i].salary=stod(argv[++count]);
		if(e[i].salary<0){
			e[i].salary=0;
		}			
	}
	 cout<<"Initial Salary : "<<endl;
	 EmployeeTest(e,n);
	 
	for(int i=0 ; i<n ; i++){
		e[i].salary+=(0.10*e[i].salary);
	}	
	 cout<<"Salary After Raise : "<<endl;
	EmployeeTest(e,n);
	
	return 0;
}
