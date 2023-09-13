#include <iostream>
using namespace std;

int main() {
	int C;
	cout << "섭씨온도:";
	cin >> C;   // 섭씨온도 정수형으로 입력받기

	cout << "화씨온도 = " << (C *(9.0/5.0))+32; //화씨온도 계산해서 출력
}

