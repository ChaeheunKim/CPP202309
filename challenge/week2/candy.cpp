#include <iostream>
using namespace std;

int main() {
	int money , price;
	cout << "현재 가지고 있는 돈 : ";
	cin >> money;
	cout << "사탕 가격: ";
	cin >> price;   //돈과 가격을 정수형으로 입력받기
    
	cout << "최대로 살 수 있는 캔디 = " << money / price << endl; //돈을 가격으로 나눈 몫(최대로 살 수 있는 캔디 수) 출력
	cout << "캔디 구입 후 남은 돈 = " << money % price << endl;  //돈을 가격으로 나눈 나머지(남은 돈) 출력
	return 0;
}