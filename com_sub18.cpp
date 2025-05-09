#include <chrono>
#include <iostream>

using namespace std;

#define SIZE 20240

int matrix[SIZE][SIZE] = {};

int main(){
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<SIZE; ++i){
        for(int j=0; j<SIZE; ++j){
            matrix[i][j] = 1;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = end - start;
    auto elapsedTime =
    chrono::duration_cast<chrono::microseconds>(elapsed);
    cout << elapsedTime.count() <<endl;
    return 0;
}

