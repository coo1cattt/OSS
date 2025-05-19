#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// class

class RandomInteger
{
    private:
        int low;
        int high;
        int value;
    public:
        RandomInteger(int low, int high);
        RandomInteger(const RandomInteger& random) = delete;
        // 합성 복사 생성자 만들지 말라는 의미 (랜덤인데 복사하면 이상하니까)
        ~RandomInteger();
        void print() const;
};

RandomInteger::RandomInteger(int lw, int hh)
:low(lw), high(hh) // 파라미터로 받은 내용 그대로 데이터 멤버 저장
{
    srand(time(0));
    int temp = rand();
    value = temp %(high - low + 1) + low; // 계산 후 데이터 멤버 저장
} 

RandomInteger::~RandomInteger()
{

}

void RandomInteger::print() const
{
    cout << value << endl;
}

int main()
{
    RandomInteger r1(100, 200);
    cout << "100~200 사이의 랜덤 수: ";
    r1.print();
    RandomInteger r2(400, 600);
    cout << "400~600 사이의 랜덤 수: ";
    r2.print();
    RandomInteger r3(1500, 2000);
    cout << "1500~2000 사이의 랜덤 수: ";
    r3.print();
    // RandomInteger r4(r3); 오류 (why?)
    return 0;
}
