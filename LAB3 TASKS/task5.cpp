#include<iostream>
using namespace std;

class Book{	
    private:
	 string BookName;
	 string Isbn;
	 string Author;
	 string Publisher;
	
	public:
	 void setBookinfo(string BookName , string Isbn , string Author , string Publisher){
	 	this->Author=Author;
	 	this->BookName=BookName;
	 	this->Isbn=Isbn;
	 	this->Publisher=Publisher;	 	
	 } 
	 string getbookinfo(){
	 	string description;
	 	description = Author + " " + BookName + " " + Isbn + " "+ Publisher;
	 	return description;	 	
	 }			
};

int main( int argc , char *argv[]){
	int n=2,count=0;
	Book book[n];
	if(argc!=4*n+1){
		cout<<"Incomplete Arguments!"<<endl;
		return 1;	
	}else{
	for(int i=0 ; i<n ; i++){
		string book_name;
		string isbn;
		string author;
		string publisher;
		book_name=argv[++count];
		isbn = argv[++count];
		author = argv[++count];
		publisher = argv[++count];	
		book[i].setBookinfo(book_name , isbn , author , publisher);				
	}
	for(int i=0 ; i<n ; i++){
		cout<<"Book "<<i+1<<" Details : ";
		string description;	
		description = book[i].getbookinfo();
		cout<<description<<endl;
	}
   }
	return 0;	
}
