#include <iostream>
using namespace std;

int main() {
	int a, b, c, smallest;   //a,b,c, 가장 작은 정수를 정수로 선언
	cout << "3 개의 정수를 입력하시오 : ";
	cin >> a >> b >> c;    //a,b,c 정수로 입력 받기

	if (a < b && a < c)
		smallest = a;         //a가 b,c보다 작으면 smallest 변수에 a 저장
	else if (b < a && b < c)
		smallest = b;         //b가 a,c 보다 작으면 smallest 변수에 b 저장
	else
		smallest = c;    //위에 두 조건이 모두 거짓이면 smallest 변수에 c 저장
	cout << "가장 작은 정수는 " << smallest << endl;  // 가장 작은 정수 smallest 출력
	return 0;
}