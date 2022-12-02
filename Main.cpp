#include "Complex.h"
#include<iostream>
#include <sstream>

using namespace std;


int main() {
	//creat objects 
	Complex complex1, complex2;
	char op=' ';
	
	cout << "Enter first complex numnber: ";
	cin >> complex1;

	cout << "Enter second complex numnber: ";
	cin >> complex2;
	
	cout << "Please enter operator: ";
	cin >> op;
	
	//if loop through different calculation
	if (op == '+') {

		Complex add = complex1 + complex2;
		cout << "The result = " << add << endl;
	
	}
	else if (op == '-') {
	
		Complex sub = complex1 - complex2;
		cout << "The result = " << sub << endl;
	
	}
	else if (op == '*') {
	
		Complex mul = complex1 * complex2;
		cout << "The result = " << mul << endl;
	
	}
	else if (op == '/') {
	
		Complex div = complex1 / complex2;
		cout << "The result = " << div << endl;
	
	}
	else {
		cout << "Invalid Enter for this complex calculation.";
	}



	return 0;
}