#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
class Users{
public:
    int user_id;
    string first_name,last_name,address,email;
    Users(int a,string f,string l,string ad,string e):user_id(a),first_name(f),last_name(l),address(ad),email(e){}
    Users(){}
    virtual string show(){
        return to_string(user_id)+","+first_name+","+last_name+","+address+","+email;
    }
};
class Products{
public:
    int product_id,price;
    string product_name,description;
    Products(int p,string n, string d,int cash):product_id(p),product_name(n),description(d),price(cash){}
    Products(){}
    virtual string show(){
        return to_string(product_id)+","+product_name+","+description+","+to_string(price);
    }
};
class Orders : public Users , public Products{
public:
    int order_id,total_paid;
    string product_ordered,user;
    Orders(int oid,string pro,string use,int paid):order_id(oid),product_ordered(pro),user(use),total_paid(paid){}
    string show()override{
        return to_string(order_id)+","+user+","+product_ordered+","+to_string(total_paid);
    }
};
void writeDummyData(){
    ofstream file("Question 3.txt");
    if(!file){
        cout<<"Error opening file.\n";
        exit(1);
    }

    vector<Users>dummyUsers={
        Users(1,"Linus","Torvalds","Finland","linus@example.com"),
        Users(2,"Alan","Turing","UK","alan@crypto.com"),
        Users(3,"Ada","Lovelace","UK","ada@math.org"),
        Users(4,"Grace","Hopper","USA","grace@navy.mil")
    };

    for(auto& u:dummyUsers){
        file<<u.show()<<endl;
    }
    file.close();
}
int main(){
    writeDummyData();

    ifstream fileb("Question 3.txt");
    if(!fileb){
        cout<<"Could not open file.\n";
        return 1;
    }

    string line;
    cout<<"Data for user Linus:\n";
    while(getline(fileb,line)){
        stringstream ss(line); // conv string to stream data
        string token;
        vector<string>fields;
        while(getline(ss,token,','))fields.push_back(token);

        if(fields.size()>=2 && fields[1]=="Linus"){
            cout<<line<<endl;
        }
    }
    fileb.close();
    return 0;
}
