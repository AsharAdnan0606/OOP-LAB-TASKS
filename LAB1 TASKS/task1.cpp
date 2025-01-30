#include<iostream>
#include<string>
using namespace std;
int main(int arc , char *argv[])
{
	int n=4;
	float arr[n],max=0,sec_max=0;
	for(int i=1 ; i<=n ; i++){
	    arr[i-1]=atoi(argv[i]);
	}
	max=stof(argv[1]);
		for(int j=1 ; j<n ; j++){
			if(max<arr[j]){
				max=arr[j];
			}
		}		
	sec_max=stof(argv[1]);
		for(int j=1 ; j<n ; j++){
			if(sec_max<arr[j] && arr[j]<max){
			sec_max=arr[j];
			}
		}
	cout<<sec_max;	
}

