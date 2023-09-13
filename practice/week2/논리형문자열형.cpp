#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "Good";
	string s2 = "Bad";
	bool b = (s1 == s2);
	cout << b << endl;   //s1과 s2 달라서 False -> 0 출력

	s2 = "Good";
	b = (s1 == s2);
	cout << b << endl;  //s2와 s1 같아서 TRUE -> 1출력
}