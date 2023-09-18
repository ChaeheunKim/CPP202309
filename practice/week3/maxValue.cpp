#include <iostream>
using namespace std;

int main() {
	int a, b, c, largest;   //a,b,c, 가장 큰 정수를 정수로 선언
	cout << "3 개의 정수를 입력하시오 : "; 
	cin >> a >> b >> c;    //a,b,c 정수로 입력 받기

	if (a > b && a > c)
		largest = a;         //a가 b,c보다 크면 largest 변수에 a 저장
	else if (b > a && b > c)
		largest = b;         //b가 a,c 보다 크면 largest 변수에 b 저장
	else
		largest = c;    //위에 두 조건이 모두 거짓이면 largest 변수에 c 저장
	cout << "가장 큰 정수는 " << largest << endl;  // 가장 큰 정수 largest 출력
	return 0;
}