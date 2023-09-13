#include <iostream>
using namespace std;

int main() {
	int F; 
	cout << "화씨온도:";
	cin >> F;  //화씨온도 정수형으로 입력받기

	cout << "섭씨온도 = " << (5.0 / 9.0) * (F - 32); //섭씨온도 계산한 값 출력
}

