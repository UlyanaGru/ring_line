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

int main() {
    vector<Event> events;
    string line;
    //Чтение всех строк
    while (getline(cin, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        vector<string> parts;
        string part;
        while (iss >> part) {
            parts.push_back(part);
        }
        if (parts.size() < 4) continue;
        try {
            int pid = stoi(parts[0]);
            string action = parts[1];
            int station = stoi(parts[2]);
            string timeStr = parts[3]; 
            int timeMinutes = timeToMinutes(timeStr);
            events.emplace_back(timeMinutes, action, station, pid);
        } catch (const exception& e) {
            continue;
        }
    }
    //Определение начала и конца отсчета
    int startTime = timeToMinutes("05:00");
    int endTime = timeToMinutes("23:30");
    int totalDuration = endTime - startTime;
    //Начальные и конечные мероприятия, чтобы мы могли охватить весь день
    events.emplace_back(startTime, "start", 1, -1);
    events.emplace_back(endTime, "end", 10, -1);
    //Сортировка событий по времени
    sort(events.begin(), events.end());
    //Обработка событий с использованием алгоритма развертки
    int currentPassengers = 0;
    int prevTime = startTime;
    double totalPassengerMinutes = 0.0;
    for (const auto& event : events) {
        int time = event.time;
        const string& action = event.action;    
        //Подсчет времени с момента предыдущего события
        int timeDelta = time - prevTime;
        if (timeDelta > 0) {
            totalPassengerMinutes += currentPassengers * timeDelta;
        }
        //Обновление количества пассажиров
        if (action == "in") {
            currentPassengers++;
        } else if (action == "out") {
            currentPassengers--;
        }
        prevTime = time;
    }
    //Подсчет среднего
    double average = totalPassengerMinutes / totalDuration;
    //Формат вывода с точностью .12
    cout << fixed << setprecision(12) << average << endl;
    return 0;
}