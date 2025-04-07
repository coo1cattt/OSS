#include <iostream>
#include <iomanip>

using namespace std;

// 5장 q3

int main(){

    int size;

    do{
        cout << "표의 크기 입력(2~10): ";
        cin >> size;
    } while(size<2 or size>10);

    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= size; j++){
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
  
    return 0;
}
