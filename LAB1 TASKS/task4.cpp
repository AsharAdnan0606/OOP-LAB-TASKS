#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	float weight;
	cout<<"Enter Weight(in Kg): ";
	cin>>weight;
	printf("Weight in Kg : %.2fkg\n",weight);
	weight=weight*2.2;
	printf("Weight in pound : %.2flb",weight);
	
	return 0;
	
	
	
}
