#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int maxPeople;
    cout << "�ִ� ��� ���� �Է��ϼ���: ";
    cin >> maxPeople;

    vector<string> names(maxPeople); // ���ڿ� ���� ����
    vector<int> ages(maxPeople);     // ���� ���� ����

    for (int i = 0; i < maxPeople; ++i) {
        cout << "���" << i + 1 << "�� �̸�: ";
        cin >> names[i];
        cout << "���" << i + 1 << "�� ����: ";
        cin >> ages[i];
    }

    int ageThreshold;
    cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
    cin >> ageThreshold;

    cout << ageThreshold << "�� �̻��� ����:\n";
    int detectedPeople = 0;
    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] >= ageThreshold) {
            cout << names[i] << " (" << ages[i] << "��)\n";
            detectedPeople++;
        }
    }
    if (detectedPeople == 0) {
        cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";
    }

    return 0;
}
