#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;

public:
    Person(const string& name) : name(name) {}

    ~Person() {
        cout << "name destroyed" << endl;
    }

    string getName() const {
        return name;
    }

    void setName(const string& newName) {
        // 한글 한 글자 바이트 길이 (3바이트)
        int len = sizeof("가") - 1; // 맥북에선 4

        // 첫 글자 비교 (바이트 단위)
        if (name.substr(0, len) == newName.substr(0, len)) {
            name = newName;
            cout << name << "(으)로 변경 완료" << endl;
        } else {
            cout << "Family name change not allowed." << endl;
        }
    }
};

int main() {
    Person person("고길동");
    cout << "원래 이름: " + person.getName() << endl;
    person.setName("곡식");   // 첫 글자 다름 -> 거절
    person.setName("고구마");  // 첫 글자 같음 -> 성공
    person.setName("박길동");  // 첫 글자 다름 -> 거절
    cout << "최종 이름: " + person.getName() << endl;

    return 0;
}
