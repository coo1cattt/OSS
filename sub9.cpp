#include <iostream>
#include <fstream>

using namespace std;

//  q#12 bye 출력

int main(){

    int n, sum = 0;
    
    ifstream fin; // 2줄 코딩
    fin.open("a.txt");

    while(fin >> n){
        sum += n;
    }  
    fin.close();

    ofstream fout("b.txt"); // 1줄 코딩
    fout << "SUM = " << sum << endl;
    fout.close();
    cout << "Bye!" << endl;


    return 0;
}
