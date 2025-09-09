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