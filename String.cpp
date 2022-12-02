#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

bool reverseString(stack<char>&obj, const string&pattern) {
	//push into the stack
	size_t sz = 0;
	while (pattern[sz] != '#') {
		obj.push(pattern[sz]);
		sz++;

	}
	//remove from stack
	sz++;
	for (size_t i=sz; i < pattern.length(); i++) {
		if (obj.top() != pattern[i])
			return false;
		obj.pop();
	}
	return true;
}

int main() {
	//create stack obj and inplment
	stack<char>string1;
	string pattern;
	cout << "Input a string : ";
	getline(cin, pattern);
	while (pattern.length() > 2) {
		if (reverseString(string1, pattern)) {
			cout << pattern << " matches the pattern" << endl;
		}
		else {
			cout << pattern << " does not match the pattern" << endl;
		}
		cout << "Input a string: ";
		getline(cin, pattern);
	}


	return 0;
}
