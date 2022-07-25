#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int A[30];

bool ismember(int a, int A[], int size) {
    for (int i = 0; i < size; i++) {
        if (A[i] == a)   return true;
    }
    return false;
}
int powerOf2(int a){
	int ans = 1;
	for(int i = 0; i < a; i++){
		ans *= 2;
	}
	return ans;
}
void powerset(int A[], int size) {
	cout << "\n printing powerset of the set A" << endl;
	int binaryOfAndy;
	for(binaryOfAndy = 0; binaryOfAndy < powerOf2(size); binaryOfAndy++){
		int binaryA = binaryOfAndy;
		cout << binaryOfAndy + 1 << ") {";
		int k = size - 1; // last element of the set;
		while(k >= 0 && binaryA > 0){
			
			if(binaryA % 2 == 1){
				cout << A[k] << " ";
			}
			binaryA /= 2;
			k--;
		}
		cout << "}" << endl;
	}
	return;
}

int main()
{
    cout << "enter size of the set :: ";
    int size0;
    cin >> size0;
    const int size = size0;

    cout << "enter values of the set :: " << endl;
    int cardinalityOfA = 0;

    for (int i = 0; i < size; i++) {
        int a;
        cin >> a;
        if (!ismember(a, A, i)) {
            cardinalityOfA++;
        }
        A[i] = a;
    }
    cout << "cardinality of A is " << cardinalityOfA << endl;
    
    cout << "enter a number to check in the set :: ";
    int checkingNumber;
    cin >> checkingNumber;
    
    if(ismember(checkingNumber, A, size)){
    	cout << "Found, The checking number is in A" << endl;
	}
	else cout << "Not Found, The checking number is not in A" << endl;
    
	powerset(A, size);
	
    return 0;
}
