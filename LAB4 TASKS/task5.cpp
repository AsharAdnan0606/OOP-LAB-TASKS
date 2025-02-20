#include<iostream>
#include<vector>
using namespace std;

class Account{
	private:
		
		int balance;
				
	public:
		
		void set_balance(int balance){
			this->balance=balance;			
		}
		
		int get_balance(){
			return balance;
		}
		
		void add_amount(int amount){
			balance+=amount;
		}
		
		void withdraw_amount(int amount){
			balance-=amount;
		}
		
	
};

int main(int argc , char*argv[]){
	int balance;
	Account a1;
	a1.set_balance(stoi(argv[1]));
	a1.add_amount(2000);
	a1.withdraw_amount(1000);
	balance =a1.get_balance();
	cout<<"Current Balance : "<<balance<<endl;
	
	return 0;
}
