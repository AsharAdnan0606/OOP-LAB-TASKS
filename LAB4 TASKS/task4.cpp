#include<iostream>
#include<string>
using namespace std;

class Circle{
	private:
		int radius;
	
	public:
		void set_radius(int radius){
			this->radius = radius;
		}	
		
		float get_area(){
			int area;
			area=3.142*(radius*radius);
			return area;			
		}
		
		float get_per(){
			int per;
			per=2*3.142*radius;
			return per;			
		}
};

int main(int argc , char*argv[]){
	float area,per;
	Circle c1;
	c1.set_radius(stoi(argv[1]));
	area=c1.get_area();
	per=c1.get_per();
	cout<<"Area : "<<area<<endl;
	cout<<"Perimeter : "<<per<<endl;
	
	return 0;
}
