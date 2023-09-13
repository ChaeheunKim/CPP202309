#include <iostream>
using namespace std;

int main() {
	int x = 1; //변수 x에 정수 1 할당
	cout << "x = " << x++ << endl; //x 출력 후 x에 1 더하기
	cout << "x = " << x++ << endl; //x 출력 후 x에 1 더하기
	cout << "x = " << ++x << endl; //x에 1 더한 후 출력하기
	cout << "x = " << x-- << endl;  //x 출력 후 x에 1 빼기
	cout << "x = " << x-- << endl;  //x 출력 후 x에 1 빼기
	cout << "x = " << --x << endl;  //x에 1 뺀 후 출력하기

	return 0;

}
