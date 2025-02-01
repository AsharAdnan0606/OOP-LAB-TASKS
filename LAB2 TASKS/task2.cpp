#include<iostream>
using namespace std;
void *add( void *arr , int n , int *sum){
		
	int* arr2 = (int*)arr; 
	for(int i=0 ; i<n ; i++){
		*sum+=*(arr2+i);
	}
	
	
}
int main(){
	int n=5,sum=0;
	int arr[n]={1,2,3,4,5};
	
	add(arr,n,&sum);
	cout<<sum;
	
	return 0;
}
