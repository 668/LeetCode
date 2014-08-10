#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		if (tokens.size() == 1)	return stoi(*tokens.begin());
		stack<int> numbers;
		vector<string>::iterator it = tokens.begin();
		int op1 = 0;
		int op2 = 0;
		while (it != tokens.end())
		{
			if (*it == "+" || *it == "-" || *it == "*" || *it == "/")
			{
				op2 = numbers.top();
				numbers.pop();
				op1 = numbers.top();
				numbers.pop();
				if (*it == "+")
					numbers.push(op1 + op2);
				else if (*it == "-")
					numbers.push(op1 - op2);
				else if (*it == "*")
					numbers.push(op1 * op2);
				else
					numbers.push(op1 / op2);
			}
			else
				numbers.push(stoi(*it));
			it++;
		}
		return numbers.top();
	}
};