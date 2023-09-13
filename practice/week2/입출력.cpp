#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	cout << "이름을 입력하세요: " ;    
	cin >> name;         //문자열 읽어서 name에 저장
	cout << name << "을 환영합니다.";   
	return 0;
}