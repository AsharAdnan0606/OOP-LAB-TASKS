#include<iostream>
#include<string>
using namespace std;
class Glass{	
	public:
		int liquidLevel;
		
		void drink(int liquidDrank){
			liquidLevel-=liquidDrank;
		}
		
		void refill(){
			if(liquidLevel<100){
				liquidLevel=200;
				cout<<"Liquid Refilled "<<"(Liquid Level: "<<liquidLevel<<" )"<<endl;
			}else{
				cout<<"Liquid Level Remaining : "<<liquidLevel<<endl;
			}
		}
};
int main(int argc , char *argv[]){
	Glass g1;
	g1.liquidLevel=200;
	int count=0;
	for(int i=0 ; i<argc-1 ; i++){
	g1.drink(stoi(argv[++count]));
	g1.refill();	
 }			
	return 0;
}
