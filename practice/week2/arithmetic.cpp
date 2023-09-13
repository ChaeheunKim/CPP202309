#include <iostream>
using namespace std;

int main() {
	int one = 1;   //변수 one에 정수 값 할당
	int two = 2;   //변수 two에 정수 값 할당
	int three = 3; //변수 three에 정수 값 할당
	int four = 4;  //변수 four에 정수 값 할당       

	//각 식에 맞는 연산을 하여 출력
	cout << "1 + 3 = " << one + three << endl;
	cout << "4 - 2 = " << four - two << endl;
	cout << "2 * 3 = " << two * three << endl;
	cout << "4 / 2 = " << four / two << endl;    

	cout << "2 + 3 * 4 = " << two + three * four << endl;
	cout << "2 + 3 * 4 = " << two + three * four << endl;
	cout << "1 + 4 / 2 = " << one + four / two << endl; 

	return 0;
}
