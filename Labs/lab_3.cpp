/*
 * main.cpp
 *
 *  Created on: April 20, 2015
 *      Author: mdcsaenz
 */

/*
 Infix to postfix conversion in C++
 Input Postfix expression must be in a desired format.
 Operands and operator, both must be single character.
 Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected.
 */
#include<iostream>
#include<stack>
#include<string>

using namespace std;

// Function to convert Infix expression to postfix
string InfixToPostfix(string expression);
string InfixToPrefix(string expression);

// Function to verify whether an operator has higher precedence over other
//int HasHigherPrecedence(char operator1, char operator2);

//in stack priority
char isp(char ch);

//incomgin priority
char icp(char ch);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool IsOperand(char C);

//function to erform an operation and return output
int HasHigherPrecedence(char op1, char op2);

//function to verify whether an operator is right associative or not.
int IsRightAssociative(char op);

int main()
{
	string expression;
	cout << "Choose an action to perfom:" << endl;
	
	int option = 1;
	while (option != 0){
		cout << "Enter 0 to Quit. Enter 1 for Infix to Postfix. Enter 2 for other." << endl;
		int option = 0; 
		cin >> option;
		switch (option) {
		case 0:{
			cout << "Bye" << endl;
			break; }
		case 1:{

			string expression;
			cout << "Enter Infix Expression to translate to PostFix\n";
			cin.ignore(); 
			getline(cin, expression);
			string postfix = InfixToPostfix(expression);
			cout << "Output = " << postfix << "\n";
			break;
		}
		case 2:{
			cout << "Enter Infix Expression \n" << endl;
			break;
		}

		default:{
			cout << "Enter a valid option" << endl;
		

		}
		}


	}
}

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
	stack<char> S;
	string postfix = ""; // Initialize postfix as empty string.
	for (int i = 0; i < expression.length(); i++) {
		if (IsOperand(expression[i])){
			postfix += expression[i];
		}
		else if (IsOperator(expression[i])){
			while (!S.empty() && S.top() !='(' && HasHigherPrecedence(S.top(), expression[i])){
				postfix += S.top();
				S.pop();


			}
			S.push(expression[i]);
		}
		else if (expression[i] == '('){
			S.push(expression[i]);
		}
		else if (expression[i] == ')'){
			while (!S.empty() && S.top() != '('){
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	
	}
		while (!S.empty()){
			postfix += S.top();
			S.pop();
		}
		return postfix;
	}


// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
    if(C >= '0' && C <= '9') return true;
    if(C >= 'a' && C <= 'z') return true;
    if(C >= 'A' && C <= 'Z') return true;
    return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' || C== '^')
        return true;
    
    return false;
}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op)
{
    if(op == '^') return true;
    return false;
}

char isp(char ch){
    switch(ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case '(': return 0;
        case '#': return -2;
    }
    return -1;
}

char icp(char ch){
    switch(ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case '(': return 4;
    }
    return -1;
}

int HasHigherPrecedence(char op1, char op2){
    int op1Weight=isp(op1); //top of stack
    int op2Weight=icp(op2);//incoming of it
    if(op1Weight==op2Weight)
    {
        if(IsRightAssociative(op1)) return false;
        else return true;
    }
    return op2Weight>op1Weight ?true: false;
}
