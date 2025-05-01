#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    cout<<"Enter string = ";
    string n;
    getline(cin,n);

    ofstream file;
    file.open("Question 1.txt", ios::app);
    if(!file){
        cout<<"Failed to open file!";
        return 1;
    }

    for(int i=0;i<n.size();i++){
        char temp=n[i]+i+1;
        file<<temp;
        //char + position where position is index+1
    }
    file<<endl;
    file.close();




    ifstream fileb;
    fileb.open("Question 1.txt", ios::in);
    if(!fileb){
        cout<<"Failed to open file!";
        return 1;
    }
    string hemp;
    while(getline(fileb,hemp)){
        for(int i=0;i<hemp.size();i++){
            char jba=hemp[i]-i-1;
            cout<<jba;
        }
        cout<<endl;
    }
return 0;
}
