#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2; //s1,s2 문자열 선언
	int count = 0; //count 변수 0으로 초기화

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;  // 두 개 문자열 입력받기

	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl; //길이가 다르다면 오류 출력
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
			    count += 1;
		}
		cout << "해밍 거리는 " << count << endl;
	}   // 문자가 다른 곳의 개수 출력
	
	return 0;
}