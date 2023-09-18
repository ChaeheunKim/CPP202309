#include <iostream>
using namespace std;

int main() {
	int number;    //number 변수 정수로 선언
	cout << "숫자를 입력하시오 : ";      
	cin >> number;  //정수 입력 받기
	if (number == 0)
		cout << "zero\n"; //입력받은 정수가 0이면 다음 줄에 zero 출력
	else if (number == 1) 
		cout << "one\n";   //입력받은 정수가 1이면 다음 줄에 one 출력
	else
		cout << "many\n";  // 입력받은 정수과 0과 1이 아니면 다음 줄에 many 출력

		return 0;
		

}