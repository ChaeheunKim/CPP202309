#include <iostream>
using namespace std;
const int numCell = 3; // �������� ���� ���� ����
char board[numCell][numCell]{}; // �������� ��Ÿ���� 2���� �迭
bool isValid(int x, int y);
bool checkwin(char currentUser);
int main() {
    // ������ �����ϴ� �� �ʿ��� ���� ����

    int k = 0; // ���� �������� üũ�ϱ� ���� ����
    char currentUser = 'X'; // ���� ������ ���� �����ϱ� ���� ����
    int x, y = 0; // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����

    // ������ �ʱ�ȭ
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            board[i][j] = ' ';
        }
    }

    // ������ ���� �ݺ�
    while (true) {
        // 1. ���� �������� ���
        // TODO 1.1: 3�ο� �������� ����
        switch (k % 3) {
        case 0:
            currentUser = 'X';
            break;
        case 1:
            currentUser = 'O';
            break;
        case 2:
            currentUser = 'H';  // H�� ���� �߰�
        }
        cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �����Դϴ�. -> ";

        // 2. ��ǥ �Է� �ޱ�
        cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
        int x, y;
        cin >> x >> y;

        // 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
        // TODO FUNC 1: isValid �Լ� ���� �� ȣ��
        if (!isValid(x, y)) {
            continue;
        }

        // 4. �Է¹��� ��ǥ�� ���� ������ �� ����
        board[x][y] = currentUser;

        // 5. ���� ���� �� ���
        // TODO 1.2: numCell ���ڿ� ���� ������ ���
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                cout << board[i][j];
                if (j < numCell - 1) {
                    cout << "  |";
                }
            }
            cout << endl;
            if (i < numCell - 1) {
                for (int t = 0; t < numCell; t++) {
                    cout << "----" ;
                }
                cout << endl;
            }
        }
        cout << endl;
    

        bool isWin = false; // �¸� ����
        // TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
        // 6.1. ����/���� �� üũ�ϱ�
        isWin = checkwin(currentUser);

        // 6.2. �밢���� üũ�ϱ�
        // TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��
        int a = 0, b = 0; //�밢�� ���� üũ ����
        for (int i = 0; i < numCell; i++) {
            if (board[i][i] == currentUser) {
                a++;
                if (a >= numCell) {
                    cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
                    isWin = true;
                }
            }
            if (board[i][numCell - i - 1] == currentUser) {
                b++;
                if (b >= numCell) {
                    cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
                    isWin = true;
                }  
            }
        }
        // �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
        if (isWin == true) {
            cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
            break;
        }

        // 7. ��� ĭ �� á���� üũ�ϱ�
        int checked = 0;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    checked++;
                }
            }
        }
        if (checked == 0) {
            cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
            break;
        }

        k++;
    }

    return 0;
}
//checkwin �Լ�
bool checkwin(char currentUser) {
    bool isWin = false;
    int c = 0, d = 0; // ����, ���� ���� üũ ����

    for (int i = 0; i < numCell; i++) {
        c = 0; // ���� ���� üũ ���� �ʱ�ȭ
        d = 0; // ���� ���� üũ ���� �ʱ�ȭ

        for (int j = 0; j < numCell; j++) {
            if (board[i][j] == currentUser) {
                c++;
            }
            if (board[j][i] == currentUser) {
                d++;
            }
        }

        if (c >= numCell) {
            isWin = true;
            cout << "���ο� ��� ���� �������ϴ�!!" << endl;
            break; 
        }

        if (d >= numCell) {
            isWin = true;
            cout << "���ο� ��� ���� �������ϴ�!!" << endl;
            break;
        }
    }
    return isWin;
}
//isValid �Լ�
bool isValid(int x, int y) {
    if (x >= numCell || y >= numCell) {
        cout << x << "," << y << ": x�� y �� �ϳ��� ������ ����ϴ�." << endl;
        return false;
    }
    else if (board[x][y] != ' ') {
        cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�." << endl;
        return false;
    }
    return true;
}