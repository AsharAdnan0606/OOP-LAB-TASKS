#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    cout<<"TYPE -1 TO EXIT\n";
    int choice;
    while(1){
        cin>>choice;
        if(choice==-1){
            exit(1);
        }else{
            char temp;
            cin>>temp;

            ofstream file;
            file.open("Question 4.txt", ios::app);
            if(!file){
                cout<<"Failed to open file!";
                return 1;
            }
            file<<temp;
            file.close();
            
            ifstream fileb;
            fileb.open("Question 4.txt", ios::in);
            if(!fileb){
                cout<<"Failed to open file!";
                return 1;
            }
            int count=0;
            string jba;
            while(getline(fileb,jba)){
                count+=jba.size();
            }
            if(count>=1000000){
                cout<<"File size has increased more than 1 MB\n";
                file.close();
                exit(1);
            }
        }
    }
return 0;
}
