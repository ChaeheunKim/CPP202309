#include <iostream>
using namespace std;

int main() {
	int choice;   //choice 정수로 선언

	cout << "1. 파일 저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;     //메뉴 사용자에게 설명하고, 사용자로부터 메뉴 번호 입력받기

	if (choice == 1)
		cout << "파일 저장을 선택했습니다" << endl;    //사용자가 1번을 입력했다면 파일 저장을 선택했다는 문장 출력
	else if (choice == 2)
		cout << "파일 닫기를 선택했습니다" << endl;    //사용자가 2번을 입력했다면 파일 닫기를 선택했다는 문장 출력
	else if (choice == 3)
		cout << "프로그램을 종료합니다." << endl;    //사용자가 3번을 입력했다면 프로그램을 종료한다는 문장 출력
	else
		cout << "잘못된 선택입니다" << endl;   //사용자가 그 외에 번호를 입력했다면 잘못된 선택이라는 문장 출력

	return 0;


}