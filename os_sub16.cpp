#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

// test

struct Person {
    string id;
    string first;
    string last;

    Person(string id, string first, string last)
        : id(id), first(first), last(last) {}
};

bool sortById(const Person &a, const Person &b) {
    return a.id < b.id;
}

int main() {
    ifstream inFile("test.inp");
    if (!inFile.is_open()) {
        cerr << "file open fail" << endl;
        return 1;
    }

    ofstream outFile("test.out");
    if (!outFile.is_open()) {
        cerr << "file write fail" << endl;
        return 1;
    }

    int n;
    inFile >> n;

    vector<Person> people;
    map<string, int> lastCount;

    for (int i = 0; i < n; ++i) {
        string id, first, last;
        inFile >> id >> first >> last;
        people.push_back(Person(id, first, last));
        lastCount[last]++;
    }

    sort(people.begin(), people.end(), sortById);

    int maxFirst = 0, maxLast = 0;
    for (const auto &p : people) {
        maxFirst = max(maxFirst, (int)p.first.size());
        maxLast = max(maxLast, (int)p.last.size());
    }

    for (const auto &p : people) {
        outFile << setw(5) << setfill(' ') << p.id << " ";
        outFile << left << setw(maxFirst) << p.first << " ";
        outFile << left << setw(maxLast) << p.last << endl;
    }
    outFile << "\n";

    for (const auto &entry : lastCount) {
        if (entry.second > 1) {
            outFile << entry.first << " " << entry.second << endl;
        }
    }

    return 0;
}
