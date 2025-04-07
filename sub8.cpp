#include <iostream>
#include <iomanip>

using namespace std;

// 3/31 for q#3

int main(){

    int score, sum=0;
    double average;

    int counter = 0;

    for(int counter=0; counter<4; counter++)
    {
        cout << "점수 입력 (0~100): ";
        cin >> score;
        sum += score;
        
    }
    
    average = static_cast<double>(sum)/4;
    cout << fixed << setprecision(2) << showpoint;
    cout << "평균 점수 = " << average;

    return 0;
}
