#include <iostream>
using namespace std;

int main() {
	const int numCell = 3; //numCell�� 3�̶�� ����
	char board[numCell][numCell]{}; // �迭�� ��� ĭ �ʱ�ȭ
	int x, y; //����ڿ��� �Է¹޴� x,y ��ǥ ���� ����

	//������ �ʱ�ȭ
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	//���� �ڵ�
	int k = 0; //���� �������� �˱� ���� ���� 0���� �ʱ�ȭ
	char currentUser = 'X'; //���� ���� �� 'X'�� ����
	while (true) {
		int u=0;//��� ĭ�� á�� �� �Ǵ��ϱ� ���� ���� u �ʱ�ȭ
		
		//1.���� �������� ���
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "�� ����(X)�� �����Դϴ�";
			currentUser = 'X';
			break;             //ù��° ���� ���� ���
		case 1:
			cout << k % 2 + 1 << "�� ����(O)�� �����Դϴ�";
			currentUser = 'O';
			break;  //�ι�° ���� ���� ���
		}
		//2. x,y ��ǥ �Է� �ޱ�
		cout << "(x,y)��ǥ�� �Է��ϼ���: ";
		cin >> x >> y;

		//3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		//3-1. ĭ�� ����� ��� �޽��� ���
		if (x >= numCell or y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x�� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
			continue;  
		}
		//3-2.���� ��� ���ִ� ��� �޽��� ���
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ":�̹� ���� ���ֽ��ϴ�." << endl;
			continue;
		}
		
		//4.�Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		//5.���� ���� �� ���
		for (int i = 0; i < numCell; i++) {
			cout << "---l---l---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];  //�����ǿ� �ִ� o or x or ���� ���
				if (j == numCell - 1) {
					break;
				}
				cout << "  l";
			}
			cout << endl;
		}
		cout << "---l---l---" << endl;

		
		//6.��� ĭ�� á���� ����
		for (int s = 0; s < numCell; s++) {
			for (int t = 0; t < numCell; t++) {
				if (board[s][t] != ' ') {
					u = u + 1; //ĭ�� á�ٸ� u�� 1 ���ϱ�
				}				
			}
		}
		if (u >= 9) {
			cout << "ĭ�� �� á���ϴ�. �����մϴ�.";
			break;   //u�� 9 �̻��� �Ǹ� ����
		}

		//7.���� �� ���� ��� �� ����
		bool win = false;
		for (int c = 0; c < numCell; c++) {
			if (board[c][0] == currentUser && board[c][1]==currentUser && board[c][2]==currentUser) {
				cout << "���ο� ��� ���� �������ϴ�.";
				win = true;  //���ο� ���� �� ��� ���� �� ���
			}
			if (board[0][c] == currentUser && board[1][c] == currentUser && board[2][c] ==currentUser) {
				cout << "���ο� ��� ���� �������ϴ�.";
				win = true; //���ο� ���� �� ��� ���� �� ���
			}
		}
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�.";
			win = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�.";
			win = true;  // �밢���� ���� �� ��� ���� �� ���
		}
		if (win == true) {
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�" << endl;
			cout << "�����մϴ�" << endl;
			break;
			
		}
		k++;
	}
	return 0;
}