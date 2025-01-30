#include<iostream>
#include<string>
using namespace std;
int main(int argc , char *argv[]){
	int sum=0,n=5;
	for(int i=1 ; i<=n ; i++){
		sum+=stoi(argv[i]);
	} 

	cout<<sum;
	
	return 0;
}
