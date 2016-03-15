#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;

long long eval(long long a, long long b, char op) {
	if (op == '*') {
		return a * b;
	}
	else if (op == '+') {
		return a + b;
	}
	else if (op == '-') {
		return a - b;
	}
	else {
		assert(0);
	}
}

void MinAndMax(int i, int j) {
	//comments
}


long long Parentheses(const string& exp) {
	int X = exp.size();

	int *m = new int[X*X];


	for (size_t i = 0; i < X; )
	{
		if (i * 2 % 2 == 0) {
			m[i*X + i] = atoi(&exp.at(i));
			i = i*2;
		}
	}


	for (size_t i = 0; i < X; i++)
	{
		for (size_t j = 0; j < X; j++)
		{
			std::cout << m[i*X + j] << " ";
		}
		std::cout << std::endl;
	}



	return 0;
}


long long get_maximum_value(const string &exp) {
	//write your code here
	int X = exp.size();

	int *m = new int[X*X];

	for (size_t i = 0; i < X; i++)
	{
		m[i*X+i] = 1;
	}


	for (size_t i = 0; i < X; i++)
	{
		for (size_t j = 0; j < X; j++)
		{
			std::cout << m[i*X + j] << " ";

		}
		std::cout << std::endl;
	}


	return 0;
}

int main() {
	string s;
	std::cin >> s;
	//std::cout << get_maximum_value(s) << '\n';
	std::cout << Parentheses(s) << '\n';
}
