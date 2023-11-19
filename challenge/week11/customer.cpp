#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int maxPeople;
    cout << "�ִ� ��� ���� �Է��ϼ���: ";
    cin >> maxPeople; // ��� �� �Է� �ޱ�

    vector<string> names; // ���ڿ� ���� ����
    vector<int> ages;     // ���� ���� ����

    for (int i = 0; i < maxPeople; ++i) {
        cout << "���" << i + 1 << "�� �̸�: ";
        cin >> names[i];
        names.push_back(names[i]); //�̸� ���Ϳ� �Է¹��� �̸� �߰�
        cout << "���" << i + 1 << "�� ����: ";
        cin >> ages[i];
        ages.push_back(ages[i]); //���� ���Ϳ� �Է¹��� ���� �߰�
    }

    int ageThreshold;
    cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
    cin >> ageThreshold;  // Ư�� ���� �Է¹ޱ�

    cout << ageThreshold << "�� �̻��� ����:\n";
    int detectedPeople = 0; // Ư�� ���̺��� ���̰� ���� ����� ��
    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] >= ageThreshold) {
            cout << names[i] << " (" << ages[i] << "��)\n";
            detectedPeople++;  // Ư�� ���̺��� ���̰� ���� ��� ���
        }
    }
    if (detectedPeople == 0) {
        cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";
    } // Ư�� ���̺��� ���̰� ���� ����� ������ ���

    return 0;
}
