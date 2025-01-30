#include<iostream>
using namespace std;
int main(){
	string name;
	int adult_tickets_sold,child_tickets_sold,gross_amount,amount_donated,net_sale,adult_tprice,child_tprice;
	float per_donated;
	cout<<"Enter Movie Name : ";
	cin>>name;
	cout<<"Enter Adult Tickets Price : ";
	cin>>adult_tprice;
	cout<<"Enter Child Tickets Price: ";
	cin>>child_tprice;
	cout<<"Enter Adult Tickets Sold : ";
	cin>>adult_tickets_sold;
	cout<<"Enter Child Tickets Sold : ";
	cin>>child_tickets_sold;
	cout<<"Enter Percentage of Gross Amount to be donated: ";
	cin>>per_donated;
	gross_amount=(adult_tickets_sold*adult_tprice)+(child_tickets_sold*child_tprice);
	amount_donated=(per_donated*gross_amount)/100;
	net_sale=gross_amount-amount_donated;
	cout<<"Movie Name : "<<name<<endl;
	cout<<"Number Of Tickets Sold : "<<child_tickets_sold+adult_tickets_sold<<endl;
	cout<<"Gross Amount : "<<gross_amount<<"$"<<endl;
	cout<<"Percentage of gross Amount Donated : "<<per_donated<<"%"<<endl;
	cout<<"Amount Donated : "<<amount_donated<<endl;
	cout<<"Net Sale : "<<net_sale<<"$";
	
	
	
	
	
	
	return 0;
}
