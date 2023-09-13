#include <iostream>
#include <string>
using namespace std;

int main() {
	char character = 'C';  //문자형 변수에 C 할당
	int integer = 100;    //정수형 변수에 100 할당
	double precision = 3.14159;    //precision 는 실수형
	bool is_true = true;        //is_true는 논리형
	string word = "Hello World"; //word는 문자열

	cout << "char : " << character << endl;
	cout << "int : " << integer << endl;
	cout << "double : " << precision << endl;
	cout << "bool : " << is_true << endl;
	cout << "string : " << word << endl;

	return 0;
}
