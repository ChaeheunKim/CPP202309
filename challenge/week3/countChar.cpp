#include <iostream>
using namespace std;

int main() {
	int vowel = 0;
	int consonant = 0;   //자음, 모음 개수 변수 0으로 초기화
	cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

	char ch; //사용자 입력 저장하기 위한 변수

	while (cin >> ch) {
		switch(ch) {
		case 'a':
			vowel = vowel + 1;  //사용자가 a 입력하면 모음에 개수 1 추가
			break;
		case 'e':
			vowel = vowel + 1; //사용자가 e 입력하면 모음에 개수 1 추가
			break;
		case 'i':
			vowel = vowel + 1; //사용자가 i 입력하면 모음에 개수 1 추가
			break;
		case 'o':
			vowel = vowel + 1; //사용자가 o 입력하면 모음에 개수 1 추가
			break;
		case 'u':
			vowel = vowel + 1; //사용자가 u 입력하면 모음에 개수 1 추가
			break;
		default:
			consonant = consonant + 1; //사용자가 자음 입력하면 자음에 개수 1 추가

		}
	}
	cout << "모음 : " << vowel << endl;
	cout << "자음 : " << consonant << endl;  //출력
	return 0;
}