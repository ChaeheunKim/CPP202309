#include <iostream>
using namespace std;

int main() {
	cout << "char 크기 : " << sizeof('p') << endl;  //문자형 p 사이즈 출력
	cout << "int 크기 : " << sizeof(10) << endl;   //정수형 10 사이즈 출력
	cout << "double 크기 : " << sizeof(10.0) << endl; //실수형 10.0 사이즈 출력

	return 0;
}