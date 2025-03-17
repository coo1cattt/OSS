#include <iostream>

using namespace std;

// 2337310 송하얼 객체 과제 2-1

int main(){

    unsigned int sec;
    int h, m, s;

    
    cout << "초를 입력하시오(0부터 30억까지) : ";
    cin >> sec;
  
    h = sec / 3600;
    m = (sec % 3600) / 60;
    s = sec % 60;

    cout << h << "시간" << m << "분" << s << "초" << endl; 


    return 0;
}