#include <iostream>
using namespace std;

int main() {
	int userInput; //userInput 정수로 선언
	
	for (int i = 0; i < 10; ++i) {
		cout << "정수를 10번 입력하세요(0을 입력하면 종료) : " << endl;
		cin >> userInput;  //사용자로부터 정수 입력 받기
		cout << "입력 값 : " << userInput << "횟수 : " << i << endl;	 //입력 값과 횟수 출력
		if (userInput == 0) 
			break;  // 0 입력하면 종료
	}
	return 0;
}