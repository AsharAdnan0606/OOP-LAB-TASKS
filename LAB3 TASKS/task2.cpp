#include<iostream>
using namespace std;
class Date{
	public :
	int day;
	int month;
	int year;
	
	void get_date(int day , int month , int year){
		this->day=day;
		this->month=month;
		this->year=year;
	}
	
	void displayDate(){
		cout<<day<<"/"<<month<<"/"<<year;
	}
};

int main(int argc , char *argv[]){	
	class Date date;
 	date.get_date(stoi(argv[1]),stoi(argv[2]),stoi(argv[3]));
	 	
}
