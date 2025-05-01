#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void addtask();
void display();
void removetask();

int main(){
    int choice;
    while(1){
        cout<<"----------------------"<<endl;
        cout<<"1. Add Tasks"<<endl;
        cout<<"2. View Tasks"<<endl;
        cout<<"3. Mark Tasks as done"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"----------------------"<<endl;
        cin>>choice;
        switch(choice){
            case 1: addtask(); break;
            case 2: display(); break;
            case 3: removetask(); break;
            case 4: return 0;
            default: cout<<"Invalid Command!\n";
        }
    }
return 0;
}

void addtask(){
    ofstream file;
    file.open("Question 5.txt", ios::app);
    if(!file){
        cout<<"Failed to open file!";
        exit(1);
    }
    string task;
    cout<<"Enter Task = ";
    getchar();
    getline(cin,task);
    file<<task<<endl;
    cout<<"Task Added Successfully!\n";
    file.close();
}
void display(){
    ifstream file;
    file.open("Question 5.txt", ios::in);
    if(!file){
        cout<<"Failed to open file!";
        exit(1);
    }
    string task;
    int i=1;
    cout<<"Tasks :\n";
    while(getline(file,task)){
        cout<<i<<". "<<task<<endl;
        i++;
    }
    file.close();
}
void removetask(){
    ifstream file;
    file.open("Question 5.txt", ios::in);
    if(!file){
        cout<<"Failed to open file!";
        exit(1);
    }
    vector<string> task;
    string temp,histask;
    cout<<"Enter Completed Task = ";
    getchar();
    getline(cin,histask);
    while(getline(file,temp)){
        if(temp!=histask){
            task.push_back(temp);
        }
    }
    file.close();

    ofstream fileb;
    fileb.open("Question 5.txt",ios::out);
    if(!fileb){
        cout<<"Failed to open file!";
        exit(1);
    }
    for(int i=0;i<task.size();i++){
        fileb<<task[i]<<endl;
    }
    fileb.close();
    cout<<"Marked task as done!\n";
}
