#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(int argc , char *argv[]){
	float score=0,n=5;
	for(int i=3 ; i<n+3 ; i++){
		score+=stof(argv[i]);
	}
	score=score/5;
	cout<<"Student Name : "<<argv[1]<<" "<<argv[2]<<endl;
	cout<<"Test Score : ";
	for(int i=3 ; i<n+3 ; i++){
		printf("%.2f ",stof(argv[i]));
	}
	printf("\nAverage Test Score : %.2f",score);
	return 0;
}
