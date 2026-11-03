#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

string LayNgayHienTai() {
    auto now = chrono::system_clock::now();

    time_t timeNow = chrono::system_clock::to_time_t(now);

    tm* localTime = localtime(&timeNow);

    stringstream ss;

    ss << put_time(localTime, "%Y%m%d");

    return ss.str();
}

int main() {
    cout << LayNgayHienTai();
}