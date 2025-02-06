#include<iostream>
using namespace std;
struct person{
	int id;
	string name;
};
int main(){
	int N;
	cout<<"Enter Number Of Structure : ";
	cin>>N;
	struct person Person[N];
	for(int i=0 ; i<N ; i++){
			cout<<"Enter ID of Person "<<i+1<<": ";
			cin>>Person[i].id;
			cout<<"Enter Name of Person "<<i+1<<": ";
			cin>>Person[i].name;		
	}
	cout<<"Data Before Sorting : "<<endl;
	for(int i=0 ; i<N ; i++){
		cout<<"ID : "<<Person[i].id<<"  NAME : ";
		cout<<Person[i].name<<endl;
	}
	cout<<"Sorting via ID : "<<endl;
	
	for(int i=0 ; i<N ; i++){
		for(int j=i ;j<N-1; j++){		
		if(Person[i].id>Person[i+1].id){
			int temp=Person[i].id;
			Person[i].id=Person[i+1].id;
			Person[i+1].id=temp;
			string temp2=Person[i].name;
			Person[i].name=Person[i+1].name;
			Person[i+1].name=temp2;
    	}
	}
		
  }
  for(int i=0 ; i<N ; i++){
		cout<<"ID : "<<Person[i].id<<"  NAME : ";
		cout<<Person[i].name<<endl;
	}
  
    
  for(int i=0 ; i<N ; i++){
		for(int j=i ;j<N-1; j++){		
		if(Person[i].name>Person[i+1].name){
			string temp=Person[i].name;
			Person[i].name=Person[i+1].name;
			Person[i+1].name=temp;
			int temp2=Person[i].id;
			Person[i].id=Person[i+1].id;
			Person[i+1].id=temp2;
		}
	}
}

    cout<<"Sorting via Name : "<<endl;
    
	for(int i=0 ; i<N ; i++){
		cout<<"ID : "<<Person[i].id<<"  NAME : ";
		cout<<Person[i].name<<endl;
	}


	
	
	

	return 0;
}
