#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10; //numCell 변수 10으로 선언
	int numList[numCell][numCell];  //numList 배열 만들기
	
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			int elem = rand() % 1000; //0-999 사이 난수 생성
			numList[i][j] = elem; //배열에 난수 저장
			cout << i << ", " << j << " : " << elem << endl;//출력
		}
	}
	cout << endl;

	int max=0;//큰 값 저장 변수
	int maxI;//큰 값이 있는 i 저장 변수
	int maxJ;//큰 값이 있는 j 저장 변수
	for (int i = 0; i < numCell; i++) { // 윗 줄 부터 차례대로 실행
		int j = 0;
		for (auto value:numList[i]) {  // 줄의 첫번째 칸부터 차례대로 실행
			
			
			if (value > max) {  
				max = value;  // 가장 큰 값을 저장
				maxI = i; // 큰 값이 있는 줄 저장
				maxJ = j; // 큰 값이 있는 칸 저장
				
				
			}
		j++;
		}
	}
	cout << "가장 큰 값은" << max << "이고,";
	cout << "i와 j는 각각" << maxI << ", " << maxJ << "입니다" << endl;
	cout << "검증 결과: " << numList[maxI][maxJ] << endl; // 출력

	return 0;

}