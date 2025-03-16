#include<iostream>
using namespace std;

class Student{
		
	public:
		
		string studentName;
		int studentId;
		
		Student(){
		}
		
		Student(string name , int id) : studentName(name) , studentId(id){			
		}
		
		void setStudentInfo(string studentName , int studentId){
			this->studentName=studentName;
			this->studentId=studentId;
		}
		
		void getStudentInfo(){
			cout<<"Student Name : "<<studentName<<endl;
			cout<<"Student ID : "<<studentId<<endl;
		}
};

class Marks : public Student{
		
	public:
		
		int Subject1;
		int Subject2;
		int Subject3;
		int Subject4;
		
		Marks(){
		}
		
		Marks(int Subject1 , int Subject2 , int Subject3 ,int Subject4){
			this->Subject1=Subject1;
			this->Subject2=Subject2;
			this->Subject3=Subject3;
			this->Subject4=Subject4;	
		}
		
		void setMarks(int Subject1 , int Subject2 , int Subject3 , int Subject4 ){
			this->Subject1=Subject1;
			this->Subject2=Subject2;
			this->Subject3=Subject3;
			this->Subject4=Subject4;
		}
		
		void getMarks(){
			cout<<"Marks of Subject 1 : "<<Subject1<<endl;
			cout<<"Marks of Subject 2 : "<<Subject2<<endl;
			cout<<"Marks of Subject 3 : "<<Subject3<<endl;
			cout<<"Marks of Subject 4 : "<<Subject4<<endl;
		}
};

class Result : public Marks{

	public:
	    float percentage;
		float averageMarks;
		static float totalMarks;
	
		void calculateResult(){
			averageMarks=(Subject1 + Subject2 + Subject3 + Subject4)/4;
			cout<<"Average Marks : "<<averageMarks;
		}
		
		void static getTotalMarks(){
			cout<<"Total Marks : "<<totalMarks<<endl;
		}
				
};

float Result::totalMarks=100;

int main(){
	Result r1;
	r1.setStudentInfo("Ashar" , 606);
	r1.setMarks(80 , 85 , 83 , 80);
	r1.getStudentInfo();
	r1.getMarks();
	r1.getTotalMarks();
	r1.calculateResult();
	
	

	return 0;
}
