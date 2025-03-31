#include <iostream>

using namespace std;

// opp 3

int main(){

    unsigned int sec;
    int h, m, s;
   
    cout << "시간, 분, 초를 입력하시오 (0부터 30억까지) : " << endl;
    cin >> h >> m >> s;

    cout << h << "시간" ;
    cout << m << "분" ;
    cout << s << "초" << endl;

  
    sec = h * 3600 + m * 60 + s;

    cout << "초로 환산 : " << sec << "초 입니다." << endl;


    return 0;
}
