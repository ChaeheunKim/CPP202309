#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL)); //random �Լ� ���� ����

	int answer = rand () % 100;//����
	int tries = 0; //�õ� Ƚ�� �����ϴ� ����
	int guess; //����� �Է� �����ϱ� ���� ����

	do {
		cout << "������ �����Ͽ� ���ÿ�" << endl;
		cin >> guess;  // ����ڷκ��� ���� �Է� �ޱ�
		tries++;  // �õ�Ƚ���� 1 ���ϱ�
		if (guess > answer)
			cout << "������ ������ �����ϴ�" << endl; //���亸�� ������ ������ ���ٰ� ���
		if (guess < answer)
			cout << "������ ������ �����ϴ�" << endl;  // ���亸�� ������ ������ ���ٰ� ���
		    
	} while (answer != guess);  //������ ������ �õ�Ƚ�� ��� �� ����
	cout << "�����մϴ�. �õ� Ƚ�� =" << tries << endl; 
	return 0;
}