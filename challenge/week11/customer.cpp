#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int maxPeople;
    cout << "최대 사람 수를 입력하세요: ";
    cin >> maxPeople; // 사람 수 입력 받기

    vector<string> names; // 문자열 벡터 선언
    vector<int> ages;     // 정수 벡터 선언

    for (int i = 0; i < maxPeople; ++i) {
        cout << "사람" << i + 1 << "의 이름: ";
        cin >> names[i];
        names.push_back(names[i]); //이름 벡터에 입력받은 이름 추가
        cout << "사람" << i + 1 << "의 나이: ";
        cin >> ages[i];
        ages.push_back(ages[i]); //나이 벡터에 입력받은 나이 추가
    }

    int ageThreshold;
    cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
    cin >> ageThreshold;  // 특정 나이 입력받기

    cout << ageThreshold << "세 이상인 고객들:\n";
    int detectedPeople = 0; // 특정 나이보다 나이가 많은 사람의 수
    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] >= ageThreshold) {
            cout << names[i] << " (" << ages[i] << "세)\n";
            detectedPeople++;  // 특정 나이보다 나이가 많은 사람 출력
        }
    }
    if (detectedPeople == 0) {
        cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다";
    } // 특정 나이보다 나이가 많은 사람이 없으면 출력

    return 0;
}
