#include<iostream>
#include<string>
using namespace std;

class User{
	public :
		int age;
		string name;
		
		void get_name(string Name){
			string name = Name;
		}
		
		void get_age(int Age){
			int age= Age;
		}
		
		void display_output(){
			cout<<"My Name is "<<name<<" and I'm "<<age;
		}	
};

int main(int argc , char * argv[]){	
        class User user;       
	    user.get_name(argv[1]);
	    user.get_age(stoi(argv[2]));
	    user.display_output();
		
	return 0;
}
