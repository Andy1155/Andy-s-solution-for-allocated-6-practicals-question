#include <iostream>

using namespace std;

int FibonacciSeries(int k){
	if(k == 0) return 1;
	if(k == 1) return 1;
	return FibonacciSeries(k-1) + FibonacciSeries(k-2);
}
int main(){
	cout << "enter n for FibonacciSeries(n) :: ";
	int n; 
	cin >> n;
	cout << "F(" << n << ") = " << FibonacciSeries(n) << endl;
	
	return 0;
}
