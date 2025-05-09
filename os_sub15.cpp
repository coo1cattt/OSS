#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// command 

int main() {
    // Unix ↔ DOS 명령어 변환표 정의 
    map<string, string> unixToDos;
    unixToDos["ls"] = "dir"; unixToDos["mkdir"] = "md"; unixToDos["rmdir"] = "rd";
    unixToDos["rm"] = "del"; unixToDos["cp"] = "copy"; unixToDos["mv"] = "rename";
    unixToDos["clear"] = "cls"; unixToDos["pwd"] = "cd"; unixToDos["cat"] = "type";
    unixToDos["man"] = "help"; unixToDos["date"] = "time"; unixToDos["find"] = "find";
    unixToDos["grep"] = "findstr"; unixToDos["more"] = "more"; unixToDos["diff"] = "comp";
    unixToDos["ed"] = "edlin"; unixToDos["sort"] = "sort"; unixToDos["lsattr"] = "attrib";
    unixToDos["pushd"] = "pushd"; unixToDos["popd"] = "popd"; unixToDos["ps"] = "taskmgr";
    unixToDos["kill"] = "tskill"; unixToDos["halt"] = "shutdown"; unixToDos["ifconfig"] = "ipconfig";
    unixToDos["fsck"] = "chkdsk"; unixToDos["free"] = "mem"; unixToDos["debugfs"] = "scandisk";
    unixToDos["lpr"] = "print";

    // DOS ↔ Unix 변환표 생성 (반대 방향)
    map<string, string> dosToUnix;
    for (map<string, string>::iterator it = unixToDos.begin(); it != unixToDos.end(); ++it) {
        dosToUnix[it->second] = it->first;
    }

    // 입력 파일 열기
    ifstream inputFile("command.inp");
    if (!inputFile.is_open()) {
        cerr << "Error: command.inp 파일을 열 수 없습니다." << endl;
        return 1;
    }

    // 출력 파일 열기
    ofstream outputFile("command.out");
    if (!outputFile.is_open()) {
        cerr << "Error: command.out 파일을 생성할 수 없습니다." << endl;
        return 1;
    }

    int n; // 명령어 개수
    inputFile >> n;
    string command;

    // 입력된 명령어들을 하나씩 변환
    for (int i = 0; i < n; ++i) {
        inputFile >> command;

        // Unix -> DOS 변환
        if (unixToDos.find(command) != unixToDos.end()) {
            outputFile << command << " -> " << unixToDos[command] << endl;
        }
        // DOS -> Unix 변환
        else if (dosToUnix.find(command) != dosToUnix.end()) {
            outputFile << command << " -> " << dosToUnix[command] << endl;
        }
        // 변환 불가한 경우
        else {
            outputFile << command << " -> unknown" << endl;
        }
    }

    // 파일 닫기
    inputFile.close();
    outputFile.close();

    cout << "변환 완료! command.out 파일을 확인하세요." << endl;
    return 0;
}
