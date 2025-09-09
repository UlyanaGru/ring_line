#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <map>

using namespace std;

//Преобразование времени 'hh:mm' в минуты, начиная с 00:00
int timeToMinutes(const string& timeStr) {
    size_t colonPos = timeStr.find(':');
    int hours = stoi(timeStr.substr(0, colonPos));
    int minutes = stoi(timeStr.substr(colonPos + 1));
    return hours * 60 + minutes;
}

struct Event {
    int time;
    string action;
    int station;
    int pid;
    Event(int t, const string& a, int s, int p) : time(t), action(a), station(s), pid(p) {}
    bool operator<(const Event& other) const {
        return time < other.time;
    }
};