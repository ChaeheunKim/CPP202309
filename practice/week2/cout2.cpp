#include <iostream>
#include <string>
using namespace std;

int main() {
	char character = 'C';  //문자형 변수에 C 할당
	int integer = 100;    //정수형 변수에 100 할당
	double precision = 3.14159;    //실수형 변수에 3.14159 할당
	bool is_true = true;        //논리형 변수에 true 할당
	string word = "Hello World"; //문자열 변수에 Hello World 할당
 
	cout << "char : " << character << endl;
	cout << "int : " << integer << endl;
	cout << "double : " << precision << endl;
	cout << "bool : " << is_true << endl;
	cout << "string : " << word << endl; //출력

	return 0;
}
