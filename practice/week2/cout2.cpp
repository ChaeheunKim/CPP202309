#include <iostream>
#include <string>
using namespace std;

int main() {
	char character = 'C';  //character를 문자형으로 저장
	int integer = 100;    //integer 은 정수형
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