#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

int main() {
    // 랜덤 시드 설정
    random_device rd;  
    mt19937 gen(rd());  // 더 좋은 난수 생성기

    // 1부터 45까지 숫자 리스트 생성
    vector<int> numbers;
    for (int i = 1; i <= 45; i++) {
        numbers.push_back(i);
    }

    // 숫자 섞기 
    shuffle(numbers.begin(), numbers.end(), gen);

    // 상위 6개 숫자 출력 (앞에서 6개 추출)
    cout << "🎉 로또 번호 추첨 결과 🎉: ";
    for (int i = 0; i < 6; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
