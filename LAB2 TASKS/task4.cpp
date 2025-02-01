#include<iostream>
#include<string>
using namespace std;
struct employee{
	string employee_name;
	int employee_id;
	int employee_salary;	
};
struct organization{
	struct employee Employee;
	string organization_name;
	int organization_number;	
};

void enter_data(struct organization &o1){
	cout<<"Enter Organization Name : ";
	cin>>o1.organization_name;
	cout<<"Enter Organization Number : ";
	cin>>o1.organization_number;
	cout<<"Enter Employe ID : ";
	cin>>o1.Employee.employee_id;
	cout<<"Enter Employe Name : ";
	cin>>o1.Employee.employee_name;
	cout<<"Enter Employe Salary : ";
	cin>>o1.Employee.employee_salary;
}

void display_data(struct organization O1){
	cout<<O1.organization_name<<endl;
	cout<<O1.organization_number<<endl;
	cout<<O1.Employee.employee_id<<endl;
	cout<<O1.Employee.employee_name<<endl;
	cout<<O1.Employee.employee_salary<<endl;
}

int main(){
	struct organization o1;
	enter_data(o1);
	display_data(o1);	
	return 0;
}

