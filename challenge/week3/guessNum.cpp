#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL)); //random 함수 관련 설정

	int answer = rand () % 100;//정답
	int tries = 0; //시도 횟수 저장하는 변수
	int guess; //사용자 입력 저장하기 위한 변수

	do {
		cout << "정답을 추측하여 보시오" << endl;
		cin >> guess;  // 사용자로부터 정수 입력 받기
		tries++;  // 시도횟수에 1 더하기
		if (guess > answer)
			cout << "제시한 정수가 높습니다" << endl; //정답보다 정수가 높으면 높다고 출력
		if (guess < answer)
			cout << "제시한 정수가 낮습니다" << endl;  // 정답보다 정수가 낮으면 낮다고 출력
		    
	} while (answer != guess);  //정답이 맞으면 시도횟수 출력 후 종료
	cout << "축하합니다. 시도 횟수 =" << tries << endl; 
	return 0;
}