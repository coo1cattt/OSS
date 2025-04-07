#include <iostream>
#include <iomanip>

using namespace std;

// 5장 q4

int main(){

    int num;

    do{
        cout << "양의 정수 입력: ";
        cin >> num;
    } while(num <= 0);
    if(num ==1){
        cout << "1은 소수도 합성수도 아닙니다.";
        return 0;
    }

    for(int i = 2; i < num; i++){
        if(num % i == 0){
            cout << num << "--> 합성수" << endl;
            cout << i << " 로 나누어집니다." << endl;
            return 0;
        }
    }

    cout << num <<" --> 소수" << endl;

    return 0;
}
