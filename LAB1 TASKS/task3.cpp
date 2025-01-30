#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int id,units;
	float rate,amount,subcharge=0,total;
	string name;
	cin>>id;
	cin>>name;
	cin>>units;
	cout<<"Customer ID: "<<id<<endl;
	cout<<"Customer Name: "<<name<<endl;
	cout<<"Units Consumed : "<<units<<endl;
	if(units>0 && units<200){
		rate=16.20;
		amount=units*rate;
	}else if(units>=200 && units<300){
		rate=20.10;
		amount=units*rate;
	}else if(units>=300 && units<500){
		rate=27.10;
		amount=units*rate;
	}else if(units>=500){
		rate=35.90;
		amount=units*rate;
	}else{
		cout<<"Incorrect Units Entered\n";
	}
	printf("Amount Charges @Rs %.2f per unit: %.2f",rate,amount);
	if(amount>18000){
		subcharge=0.15*amount;
	}
	cout<<"\nSubcharge Amount: "<<subcharge<<endl;
	total=subcharge+amount;
	printf("Net Amount Paid by the Customer: %.2f",total );
	
return 0;	
	
}
