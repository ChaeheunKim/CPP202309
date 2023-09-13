#include <iostream>
using namespace std;

int main() {
	int x = 1; //x를 1로 초기화
	cout << "x = " << x++ << endl; //x 출력 후 x에 1 더하기
	cout << "x = " << x++ << endl; //x 출력 후 x에 1 더하기
	cout << "x = " << ++x << endl; //x에 1 더한 후 출력하기
	cout << "x = " << x-- << endl;  //x 출력 후 x에 1 뺴기
	cout << "x = " << x-- << endl;  //x 출력 후 x에 1 뺴기
	cout << "x = " << --x << endl;  //x에 1 뺸 후 출력하기

	return 0;

}
