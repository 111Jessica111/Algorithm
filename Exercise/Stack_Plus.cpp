#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int Correct(string a,int i) {
	if (a[i] == ')') {
		if (a[i - 1] == '(')
			return 1;
		else 
			return 0;
	}
	else if (a[i] == ']') {
		if (a[i - 1] == '[')
			return 1;
		else
			return 0;
	}
	else
		return 0;
}


int main() {
	std::stack<char> str;
	int i, j;
	string a;
	cin >> a;
	int a_len = a.size();
	std::vector<int> myVector(a_len);

	j = 0;
	i = 0;

	while (i < a_len) {
		if (j == 0) {
			str.push(a[i++]);
			j++;
		}
		else {
			if (Correct(a, i)) {
				str.pop();
				myVector[i] = 1;
				myVector[i - 1] = 1;
				i++;
				j--;
			}
			else {
				str.push(a[i]);
				i++;
				j++;
			}
		}
	}

	for (i = 0; i < a_len; i++) {
		if (myVector[i] == 0) {
			if (a[i] == '(') {
				cout << a[i] << ')';
			}
			else if (a[i] == '['){
				cout << a[i] << ']';
			}
			else if (a[i] == ')') {
				cout << '(' << a[i];
			}
			else {
				cout << '[' << a[i];
			}
		}
		else {
			cout << a[i];
		}
	}

	return 0;
}