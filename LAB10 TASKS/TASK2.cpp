#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<sstream>
using namespace std;
void input_data(){
    ofstream file;
    file.open("Question 2.txt",ios::out);
    if(!file){
        cout<<"Failed to open file!";
        exit(1);
    }
    file<<"1234 Bilal Clerk 15"<<endl;
    file<<"1235 Ashar Manager 1"<<endl;
    file<<"1236 Ahmed CEO 10"<<endl;
    file<<"1237 Asad Manager 3"<<endl;
    file<<"1238 Ali Janitor 6"<<endl;
    file.close();
}

int main(){
    input_data();

    fstream file;
    file.open("Question 2.txt");
    if(!file){
        cout<<"Failed to open file!";
        return 1;
    }

    string temp;
    while(getline(file,temp)){
        int man=temp.find("Manager");
        if(man!=string::npos){
            stringstream ss(temp);
            string name,status;
            int id,years;
            ss>>id>>name>>status>>years;
            if(years>=2){
                cout<<temp;
                break;
            }
        }
    }
    file.close();

    ofstream fileb("Question 2.txt", ios::out);
    fileb<<temp<<endl;
    fileb.close();


    stringstream ss(temp);
    string name,status;
    int id,years;
    ss>>id>>name>>status>>years;
    ofstream filec("Question 2.txt", ios::out);
    filec<<++id<<" "<<name<<" "<<status<<" "<<++years<<endl;
    filec.close();
return 0;
}
