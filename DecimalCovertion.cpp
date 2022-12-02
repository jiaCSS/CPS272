#pragma once
#include<iostream>
#include<iomanip>
#include<stack>
#include<algorithm>
using namespace std;

//decimal to binary

void decimalToBinary(stack<int>obj, int decimal, int base = 2) {
	if (decimal > 1) {
		obj.push(decimal % 2);
		decimalToBinary(obj, decimal / 2, base);
	}
	cout << obj.top();
	obj.pop();	
}


//decimal to hex
void decimalToHex(stack<char>obj, int decimal, int base = 16){	

		if (decimal>0) {	
			obj.push(decimal % 16);
			switch (decimal % 16) {
			case 0:obj.push('0'); break;
			case 1:obj.push('1'); break;
			case 2:obj.push('2'); break;
			case 3:obj.push('3'); break;
			case 4:obj.push('4'); break;
			case 5:obj.push('5'); break;
			case 6:obj.push('6'); break;
			case 7:obj.push('7'); break;
			case 8:obj.push('8'); break;
			case 9:obj.push('9'); break;
			case 10:
				obj.push('A'); break;
			case 11:
				obj.push('B'); break;
			case 12:
				obj.push('C'); break;
			case 13:
				obj.push('D'); break;
			case 14:
				obj.push('E'); break;
			case 15:
				obj.push('F'); break;
			}//end switch
			if (decimal > 16) {
				decimalToHex(obj, decimal / 16, base);
			}
			
		}
		cout << obj.top();
		obj.pop();				
}


//decimal to octal
void decimalToOctal(stack<int>obj, int decimal, int base = 8) {
	
	if (decimal > 0) {
		obj.push(decimal % 8);
		
	}
	if (decimal > 8) {
		decimalToOctal(obj, decimal / 8, 8);
	}
	cout << obj.top();
	obj.pop();
}


//combine to one funtion
void multiBase(int number, int base) {
	stack<int>tobinOctal;
	stack<int>tobin;
	stack<char>tohex;
	
	switch (base) {
	case 2: 
		decimalToBinary(tobin, number); break;
	case 8:
		decimalToOctal(tobinOctal, number); break;
	case 16:
		decimalToHex(tohex, number); break;
	}
}


int main() {
	//creat obj to implment
	stack<int>decitobin;
	stack<char>decitohex;
	stack<int>decitooctal;
	int decimal;
	int base = 0;
	//decimalToBinary(decitobin, 358, 2);
	//decimalToHex(decitohex, 358, 16);
	//decimalToOctal(decitooctal, 358, 8);

	//print out
	cout << "Enter a non-negative decimal number and base (2, 16, 8): ";
	cin >> decimal;
	cin >> base;
	cout << decimal << " base " << base << " is "; 
	multiBase(decimal, base);
	cout << "\n";
	return 0;
}