#include <iostream>
#include <string>
using namespace std;

int main() {
	const int STUDENT = 5; // STUDENT를 5로 선언
	const int SUBJECT = 3; // SUBJECT를 3으로 선언
	int scores[STUDENT][SUBJECT]; // 2차원 배열 생성
	string studentNames[STUDENT]
		= { "영수","영희","철수","미미","쥬쥬" };
	string subjectNames[SUBJECT]
		= { "수학","영어","CPP" }; //배열에 학생이름과 과목이름 저장

	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 성적을 하나씩 입력하세요" << endl;
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];   // 학생들 성적 입력받아 저장
		}

	}
	double sum = 0;
	double average = 0;  //sum, average 변수 0으로 초기화
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 평균 점수는";
		
	    for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];  //sum에 학생들 성적 누적하여 더하기
		}
		average = sum / SUBJECT; // sum을 과목 개수로 나눠서 평균 구하기
		cout << average << "입니다" << endl; //평균 출력
		
	}
	return 0;
	

}