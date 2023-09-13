#include <iostream>
using namespace std;

int main() {
	int two = 2;  //two 변수에 정수 2 값 할당
	int eight = 8; //eight 변수에 정수 8 값 할당
	int sum1 = 2; //sum1 변수에 정수 2 값 할당
	int sum2 = 2; //sum2 변수에 정수 2 값 할당

	sum1 = sum1 + sum2;      //sum1에 sum1과 sum2 더한 값 할당
	sum2 += eight;           // sum2에 sum2에 8 더한 값 할당    
	cout << "sum1 = " << sum1 << endl;
	cout << "sum2 = " << sum2 << endl; //출력
		
}
