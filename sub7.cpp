#include <iostream>
#include <iomanip>

using namespace std;

// opp 7 - if(fd,cd)

int main() {
    
    int num;
    double fd, cd;

    cout << "선택하세요 (1:화씨->섭씨, 2:섭씨->화씨) ==> ";
    cin >> num;

    if(num==1){
        cout << "화씨 온도 입력 : ";
        cin >> fd;
        cd = (5.0 / 9.0) * (fd - 32.0);
        cout << fixed << setprecision(5);
        cout << "섭씨온도는 " << cd << "입니다." << endl;
    }

    else if (num==2) {
        cout << "섭씨 온도 입력 : ";
        cin >> cd;
        fd = (cd * 9.0)/ 5.0 + 32;
        cout << fixed << setprecision(5);
        cout << "화씨온도는 " << fd << "입니다." << endl;
    }
    
    else{
        cout << "1,2 중에 하나를 입력하세요." << endl;
    }

    return 0;
}
                           
