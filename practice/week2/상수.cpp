#include <iostream>
#define PI 3.14159265359   //PI가 기호함수
using namespace std;

int main(){ 
	int income = 1000;    // 1000이 리터럴 함수
    const double TAX_RATE = 0.25;  // TAX_RATE가 상수 변수
    income = income - TAX_RATE * income;

    double x = 100;
    x = x * PI;

    cout << x << endl;
    return 0;
}