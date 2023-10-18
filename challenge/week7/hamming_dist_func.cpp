#include <iostream>
#include <string>
using namespace std;


string toLowerStr(string str) {
	string s1 = str;
	for (char& c : s1) {
		c = tolower(c);
	}
	return s1;  // 문자열 소문자로 변환
}

string toUpperStr(string str) {
	string s1 = str;
	for (char& c : s1) {
		c = toupper(c);
	}
	return s1;  //문자열 대문자로 변환
}

int calcHammingDist(string s1, string s2) {
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);  // 문자열을 모두 소문자로 변환
	int count = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count += 1;
	}     // 일치 하지 않는 부분의 개수를 count에 저장
	return 0;
}

int main() {
	string s1, s2; //s1,s2 문자열 선언

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;  // 두 개 문자열 입력받기

	if (s1.length() != s2.length()) {
		cout << "오류: 길이가 다름" << endl;
	}//길이가 다르다면 오류 출력
	else {
		int count = calcHammingDist(s1, s2); // 대,소문자 무시
		cout << "해밍 거리는 " << count << endl;
	}   // 문자가 다른 곳의 개수 출력

	return 0;
}