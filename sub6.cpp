#include <iostream>

using namespace std;

// opp 6 - 정수 자릿수  

int main() {
    // 사용자 입력을 받을 변수 선언
    string num;
    int position;

    // 정수 입력 받기
    cout << "정수 입력 : ";
    cin >> num;

    // 자릿수 입력 받기
    cout << "자릿수 입력 : ";
    cin >> position;

    // 문자열 길이를 이용해 자릿수 판별
    int length = num.length();

    // 입력한 자릿수가 범위를 벗어난 경우
    if (position > length || position <= 0) {
        cout << "자릿수 범위를 벗어났습니다." << endl;
    } else {
        // 오른쪽에서 원하는 자릿수의 숫자 찾기
        char find = num[length - position];
        cout << "오른쪽에서 시작해서 " << position 
             << "번째 자리에 있는 숫자는 " << find << endl;
    }

    return 0;
}
                           
