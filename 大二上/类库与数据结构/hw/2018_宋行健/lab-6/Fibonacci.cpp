#include<iostream>
using namespace std;
int fib(int num){
	if(num==2 || num==1)
		return 1;
	else
		return fib(num-1)+fib(num-2);
}

int main(){
	int n;
	cin>>n; 
	cout<<"fibonacci("<<n<<"): "<<fib(n);
	return 0;
}
