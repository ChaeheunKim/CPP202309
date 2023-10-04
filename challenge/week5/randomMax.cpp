#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10; //numCell ���� 10���� ����
	int numList[numCell][numCell];  //numList �迭 �����
	
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			int elem = rand() % 1000; //0-999 ���� ���� ����
			numList[i][j] = elem; //�迭�� ���� ����
			cout << i << ", " << j << " : " << elem << endl;//���
		}
	}
	cout << endl;

	int max=0;//ū �� ���� ����
	int maxI;//ū ���� �ִ� i ���� ����
	int maxJ;//ū ���� �ִ� j ���� ����
	for (int i = 0; i < numCell; i++) { // �� �� ���� ���ʴ�� ����
		int j = 0;
		for (auto value:numList[i]) {  // ���� ù��° ĭ���� ���ʴ�� ����
			
			
			if (value > max) {  
				max = value;  // ���� ū ���� ����
				maxI = i; // ū ���� �ִ� �� ����
				maxJ = j; // ū ���� �ִ� ĭ ����
				
				
			}
		j++;
		}
	}
	cout << "���� ū ����" << max << "�̰�,";
	cout << "i�� j�� ����" << maxI << ", " << maxJ << "�Դϴ�" << endl;
	cout << "���� ���: " << numList[maxI][maxJ] << endl; // ���

	return 0;

}