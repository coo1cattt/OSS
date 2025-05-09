#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// batch

int main() {
    ifstream inputFile("batch.inp");
    ofstream outputFile("batch.out");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "파일 열기 실패!" << endl;
        return 1;
    }

    int numPrograms;
    inputFile >> numPrograms;

    vector<vector<int> > programs(numPrograms);

    // 각 프로그램의 작업 시간 입력
    for (int i = 0; i < numPrograms; ++i) {
        int time;
        while (inputFile >> time && time != -1) {
            programs[i].push_back(time);
        }
    }

    int currentTime = 0;      // 현재 시간 (총 소요 시간 추적)
    int cpuIdleTime = 0;      // CPU 유휴 시간
    int lastCpuEndTime = 0;   // 마지막 CPU 작업 종료 시점

    // 모든 프로그램을 순차적으로 처리
    for (int i = 0; i < numPrograms; ++i) {
        for (size_t j = 0; j < programs[i].size(); ++j) {
            if (j % 2 == 0) { // CPU 작업
                if (currentTime < lastCpuEndTime) {
                    currentTime = lastCpuEndTime; // CPU가 끝날 때까지 대기
                }
                currentTime += programs[i][j]; // CPU 작업 시간 추가
                lastCpuEndTime = currentTime;  // CPU 종료 시점 갱신
            } else { // I/O 작업
                cpuIdleTime += programs[i][j]; // I/O 작업 시간 동안 CPU 유휴
                currentTime += programs[i][j]; // I/O 작업 시간 추가
            }
        }
    }

    outputFile << cpuIdleTime << " " << currentTime << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
