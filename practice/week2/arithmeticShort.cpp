#include <iostream>
using namespace std;

int main() {
	int two = 2;
	int eight = 8;
	int sum1 = 2;
	int sum2 = 2;

	sum1 = sum1 + sum2;      //sum1에 sum1 sum2 더한 값 저장
	sum2 += eight;           // sum2에 sum2+8 값 저장    
	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl; //출력
		
}