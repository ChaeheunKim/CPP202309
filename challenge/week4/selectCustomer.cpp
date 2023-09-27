#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3; //maxPeople 3명으로 선언
	string names[maxPeople]; // names 배열 문자열로 선언
	int ages[maxPeople];  //ages 배열 정수로 선언

	for (int i = 0; i < maxPeople; ++i) { // 사람 수 만큼 반복
		cout << "사람" << i + 1 << "의 이름: ";
		cin >> names[i];
		cout << "사람" << i + 1 << "의 나이: ";
		cin >> ages[i];           // 이름과 나이 입력 받고 배열에 저장
	}

	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
	cin >> ageThreshold;       // 특정 나이 입력받기

	cout << ageThreshold << "세 이상인 고객들:\n";
	int detectedPeople = 0;
	for (int i = 0; i < maxPeople; i++) {
		if (ages[i] >= ageThreshold) {    
			cout << names[i] << " (" << ages[i] << "세)\n";
			detectedPeople++;          // 특정 나이 이상인 고객 출력 후 detectedPeople에 1 더하기
		}
	}
	if (detectedPeople == 0) {
		cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다";
	}   // 특정 나이 이상인 고객이 없다면 없다고 출력

	return 0;



}