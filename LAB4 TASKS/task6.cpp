#include<iostream>
using namespace std;

class Invoice{
	private:
		string name;
		string description;
		int quantity;
		double price;
	
	public:
		
		Invoice(){
			
		}
		
		Invoice(string name , string description , int quantity , double price){
			this->name=name;
			this->description = description;
			this->quantity = quantity;
			this->price = price;
		}
		
		get_invoice_amount(){
			
			int amount;
					
			if(quantity<0){
				quantity=0;
			}
			
			if(amount<0){
				amount=0;
			}
						
			amount = quantity * price;
			return amount;
		}
};

int main(){
	Invoice i1("Bolt" , "Heavy Steel" , 5 , 200);
	int amount=i1.get_invoice_amount();
	cout<<"Invoice Amount : "<<amount<<endl;
	return 0;
}
