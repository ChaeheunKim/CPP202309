#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "Good";
	string s2 = "Bad";
	bool b = (s1 == s2);
	cout << b << endl;   //s1�� s2 �޶� False -> 0 ���

	s2 = "Good";
	b = (s1 == s2);
	cout << b << endl;  //s2�� s1 ���Ƽ� TRUE -> 1���
}