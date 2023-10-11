#include <iostream>
using namespace std;

int main() {
	const int numCell = 3; //numCell을 3이라고 선언
	char board[numCell][numCell]{}; // 배열의 모든 칸 초기화
	int x, y; //사용자에게 입력받는 x,y 좌표 저장 변수

	//보드판 초기화
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	//게임 코드
	int k = 0; //누구 차례인지 알기 위한 변수 0으로 초기화
	char currentUser = 'X'; //현재 유저 돌 'X'로 저장
	while (true) {
		int u=0;//모든 칸이 찼는 지 판단하기 위한 변수 u 초기화
		
		//1.누구 차례인지 출력
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다";
			currentUser = 'X';
			break;             //첫번째 유저 차례 출력
		case 1:
			cout << k % 2 + 1 << "번 유저(O)의 차례입니다";
			currentUser = 'O';
			break;  //두번째 유저 차례 출력
		}
		//2. x,y 좌표 입력 받기
		cout << "(x,y)좌표를 입력하세요: ";
		cin >> x >> y;

		//3. 입력받은 좌표의 유효성 체크
		//3-1. 칸을 벗어나는 경우 메시지 출력
		if (x >= numCell or y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			continue;  
		}
		//3-2.돌이 모두 차있는 경우 메시지 출력
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ":이미 돌이 차있습니다." << endl;
			continue;
		}
		
		//4.입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		//5.현재 보드 판 출력
		for (int i = 0; i < numCell; i++) {
			cout << "---l---l---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];  //보드판에 있는 o or x or 공백 출력
				if (j == numCell - 1) {
					break;
				}
				cout << "  l";
			}
			cout << endl;
		}
		cout << "---l---l---" << endl;

		
		//6.모든 칸이 찼으면 종료
		for (int s = 0; s < numCell; s++) {
			for (int t = 0; t < numCell; t++) {
				if (board[s][t] != ' ') {
					u = u + 1; //칸이 찼다며 u에 1 더하기
				}				
			}
		}
		if (u >= 9) {
			cout << "칸이 다 찼습니다. 종료합니다.";
			break;   //u가 9 이상이 되면 종료
		}

		//7.빙고 시 승자 출력 후 종료
		bool win = false;
		for (int c = 0; c < numCell; c++) {
			if (board[c][0] == currentUser && board[c][1]==currentUser && board[c][2]==currentUser) {
				cout << "가로에 모두 돌이 놓였습니다.";
				win = true;  //가로에 놓인 게 모두 같을 시 출력
			}
			if (board[0][c] == currentUser && board[1][c] == currentUser && board[2][c] ==currentUser) {
				cout << "세로에 모두 돌이 놓였습니다.";
				win = true; //세로에 놓인 게 모두 같을 시 출력
			}
		}
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다.";
			win = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다.";
			win = true;  // 대각선에 놓인 게 모두 같을 시 출력
		}
		if (win == true) {
			cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다" << endl;
			cout << "종료합니다" << endl;
			break;
			
		}
		k++;
	}
	return 0;
}