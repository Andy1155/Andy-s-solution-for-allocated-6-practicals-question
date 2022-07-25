#include <iostream>

using namespace std;

int matrix[100][100];

void drawAdjacency(bool direct){
	int numberOfVertices, numberOfEdges;
	cout << "enter number of vertices :: ";
	cin >> numberOfVertices;
	cout << "vertices are :: ";
	for(int i = 0; i < numberOfVertices; i++){
		cout << i << " ";
	}
	cout << endl;
	
	cout << "enter number of edges :: ";
	cin >> numberOfEdges;
	cout << "enter " << numberOfEdges << " edges in form \"a b\" ::" << endl;
	for(int i = 0; i < numberOfEdges; i++){
		int a, b;
		cin >> a >> b;
		matrix[a][b]++;
		if(!direct){
			matrix[b][a]++;
		}
		else;
	}
	
	cout << "Adjacency Matrix :: " << endl << endl;
	
	cout << "   ";
	for(int i = 0; i < numberOfVertices; i++){
		cout << i << " ";
	}
	cout << endl;
	for(int i = 0; i < numberOfVertices; i++){
		cout << i << " |";
		for(int j = 0; j < numberOfVertices; j++){
			cout << " " << matrix[i][j];
		}
		cout << " |" << endl;
	}
	
	cout << endl << endl;
	
	for(int i = 0; i < numberOfVertices; i++){
		for(int j = 0; j < numberOfVertices; j++){
			if(i == j && matrix[i][j] != 0){
				cout << "above matrix is not Complete graph" << endl;
				return;
			}	
			if(i != j && matrix[i][j] != 1){
				cout << "above matrix is not Complete graph" << endl;
				return;
			}
		}
	}
	cout << "above matrix is Complete graph" << endl;
	return;
}

int main(){

	cout << "directed or not, Y/N :: ";
	char ch;
	cin >> ch;
	if(ch == 'Y' || ch == 'y'){
		drawAdjacency(true);
	}
	if(ch == 'N' || ch == 'n'){
		drawAdjacency(false);
	}
	
	return 0;
}
