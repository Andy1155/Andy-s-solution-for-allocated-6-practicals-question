#include <iostream>

using namespace std;

class Relation {
	private:
	int numberOfElements;
	int numberOfRelations;
	bool relation[100][100] = {{false}};
	
	public:
	void inputNumberOfElements();
	void inputRelation();
	void printMatrix();
	bool isReflexive();
	bool isSymmetric();
	bool isAntiSymmetric();
	bool isTransitive();
	
};

void Relation :: inputNumberOfElements(){
	
	cout << "enter number of elements :: ";
	cin >> numberOfElements;
	cout << "\n elements are { ";
	for(int i = 0; i < numberOfElements; i++){
		cout << i << " ";
	}
	cout << "}" << endl;
	
	return; 
}

void Relation :: inputRelation(){
	
	cout << "enter number of relations :: ";
	cin >> numberOfRelations;
	cout << "enter " << numberOfRelations << " relations in form \"a b\" :: " << endl;
	for(int i = 0; i < numberOfRelations; i++){
		int a, b;
		cin >> a >> b;
		relation[a][b]=true;
	}
	
	return;
}

void Relation :: printMatrix(){
	cout << "Matrix of the relation :: " << endl << endl;
	cout << "    ";
	for(int i = 0; i < numberOfElements; i++){
		cout << i << " ";
	}
	cout << endl;
	for(int i = 0; i < numberOfElements; i++){
		cout << i << " |";
		for(int j = 0; j < numberOfElements; j++){
			cout << " " << relation[i][j];
		}
		cout << " |" << endl; 
	} 
}

bool Relation :: isReflexive(){
	for(int i = 0; i < numberOfElements; i++){
		if(!relation[i][i])
			return false;
	}
	return true;
}

bool Relation :: isSymmetric(){
	for(int i = 0; i < numberOfElements; i++){
		for(int j = 0; j <= i; j++){
			if(relation[i][j] && !relation[j][i] && i != j)
				return false;
		}
	}
	return true;
};

bool Relation :: isAntiSymmetric(){
	for(int i = 0; i < numberOfElements; i++){
		for(int j = 0; j < numberOfElements; j++){
			if(relation[i][j] && relation[j][i] && i != j){
				return false;
			}
		}
	}
	return true;
};

bool Relation :: isTransitive(){
	for(int i = 0; i < numberOfElements; i++){
		for(int j = 0; j < numberOfElements; j++){
			if(relation[i][j]){
				for(int k = 0; k < numberOfElements; k++){
					if(relation[j][k] && !relation[i][k]){
						return false;
					}
				}
			}
		}
	}
	return true;
};

int main(){
	Relation rel;
	rel.inputNumberOfElements();
	rel.inputRelation();
	rel.printMatrix();
	cout << "symmetric :: " << rel.isSymmetric() << endl;
	cout << "reflexive :: " << rel.isReflexive() << endl;
	cout << "antisymmetric :: " << rel.isAntiSymmetric() << endl;
	cout << "transitive :: " << rel.isTransitive() << endl;
	
	return 0;
}
