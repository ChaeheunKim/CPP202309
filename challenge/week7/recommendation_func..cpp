#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
const int NUM_USERS = 3;
const int NUM_ITEMS = 3; //사용자와 항목 개수 3으로 설정
int userpreferences[NUM_USERS][NUM_ITEMS];


void initializePreferences(int userpreferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자" << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해) ";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userpreferences[i][j]; // 선호도 입력 받기
		}
	}
}

void findRecommendedItems(const int userpreferences[NUM_USERS][NUM_ITEMS]) {
	//각 사용자에 대한 추천 항목 찾기
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceindex = 0; // 추천 항목 초기화
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userpreferences[i][j] > userpreferences[i][maxPreferenceindex]) {
				maxPreferenceindex = j; //선호도가 가장 큰 것을 추천항목으로 설정]
			}
		}
		// 사용자에게 추천하는 항목 출력
		cout << "사용자" << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceindex + 1) << std::endl;
	}
}

int main() {
	initializePreferences(userpreferences);
	findRecommendedItems(userpreferences);
	return 0;  // 함수 가져와서 출력
}