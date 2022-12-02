#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<stack>
#include<algorithm>
#include<fstream>

using namespace std;

//using stack to push in to stack and remove it until empty stack. 
bool balancingBrace(ifstream& fin) {
    stack<char>brace;
    while (fin.peek() != EOF) {
        //push into stack
        char ch = fin.get();
        if (ch == '(' || ch == '{' || ch == '[') {
            brace.push(ch);
        }

        //switch 
        switch (ch) {
        
        case ')':
            if (brace.top() == '(') {
                brace.pop();
            }
            else return false;
            break;

        case '}':
            if (brace.top() == '{') {
                brace.pop();
            }
            else return false;
            break;

        case ']':
            if (brace.top() == '[') {
                brace.pop();
            }
            else return false;
            break;

        default: 
            break;
        }
    }   
    return (brace.empty());//return empty means match.
}

int main() {
    string filename;
    ifstream fin;
    for (int i = 0; i < 2; i++) {

        cout << "please enter file name: ";
        cin >> filename;
        fin.open(filename);

        if (balancingBrace(fin))
            cout << filename << " is balanced" << endl;
        else
            cout << filename << " is not balanced\n" << endl;
        fin.close();
    }

        
  
   

    
    
    

    
    
    

    
    




    return 0;
}