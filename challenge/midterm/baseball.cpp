#include <iostream>
#include <string>
using namespace std;
bool numCheck(int number, int& firstNum, int& secondNum, int& thirdNum);


int main() {

	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum; // 정답의 첫번째 자리수
	int secondNum; // 정답의 두번째 자리수
	int thirdNum; // 정답의 세번째 자리수

	while (1) {

		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		same = numCheck(randomNum, firstNum, secondNum, thirdNum);
		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
			if (to_string(userNumber).length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

			same = numCheck(userNumber, guessFirst, guessSecond, guessThird);
			if (same == false) {
				cout << "중복된 숫자가 있습니다" << endl;
				continue; // 중복 출력
			}
			if (same == true) {
				break;
			}



		}

		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록작성
		string randomNumStr = to_string(randomNum);
		string userstr = to_string(userNumber);//입력받은 수와 랜덤 수 문자열로 바꾸기
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (randomNumStr[i] == userstr[j]) { //입력받은 수와 랜덤 수가 같은 숫자가 있다면
					if (i == j) {   //같은 위치일 때 
						strike++;
					}
					else {     // 다른 위치일 때
						ball++;
					}
				}
			}
		}
		//힌트 출력
		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
		// 정답 시 출력하고 종료
		if (strike == 3) {

			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1;
	}


	return 0;
}
//numcheck 함수
bool numCheck(int number, int& firstNum, int& secondNum, int& thirdNum) {
	firstNum = number / 100;
	secondNum = (number / 10) % 10;
	thirdNum = number % 10; //자릿 수 추출
	bool same = false;
	if (firstNum != secondNum && thirdNum != secondNum && firstNum != thirdNum) {
		same = true;
	}  // 모든 수가 다른 지 체크

	return same;
}
//정답: 567

