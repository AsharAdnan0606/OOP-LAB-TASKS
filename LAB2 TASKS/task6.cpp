#include<iostream>
#include<string>
#include<vector>
#define n 2
using namespace std;
struct person{
	int id;
	string name;
	
};

struct course{
   string subject[2];
   struct person Person;
};


int main(){
	vector<course>Courses; 

	for(int i=0 ; i<n ; i++){
		struct course c1;
		cout<<"Enter ID of Person"<<i+1<<" : ";
		cin>>c1.Person.id;
		cout<<"Enter Name of Person"<<i+1<<" : ";
		cin>>c1.Person.name;
		for(int j=0 ; j<2 ; j++){
		cout<<"Enter Subject"<<j+1<<" of Person"<<i+1<<" : ";
		cin>>c1.subject[j];
		}
		Courses.push_back(c1);
				
	}
	cout << "\nStored Data:\n";
    for (const auto &c : Courses) {
        cout << "Person ID: " << c.Person.id << endl;
        cout << "Person Name: " << c.Person.name << endl;
        cout << "Subjects: " << c.subject[0] << ", " << c.subject[1] << endl;
        cout<<"------------------------------"<<endl;
    }
		
	return 0;
}
