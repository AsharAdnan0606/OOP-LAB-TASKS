#include<iostream>
#include<string>
using namespace std;
int main(int argc , char *argv[]){
	int n=5,sum=0;
	int arr[n];
	for(int i=1 ; i<=n ; i++){
		sum+=stoi(argv[i]);
	}
	cout<<sum;		
	return 0;
}
