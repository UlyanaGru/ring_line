import sys
from collections import defaultdict

def time_to_minutes(time_str):
    """Преобразование времени 'hh:mm' в минуты, начиная с 00:00"""
    hours, minutes = map(int, time_str.split(':'))
    return hours * 60 + minutes
def main():
    #Чтение всех строк
    data = sys.stdin.read().splitlines()
    #Поиск событий
    events = []
    for line in data:
        if not line.strip():
            continue
        parts = line.split()
        if len(parts) < 4:
            continue
        try:
            pid = int(parts[0])
            action = parts[1]
            station = int(parts[2])
            time_str = parts[3]
            #Преобразование в минуты
            time_minutes = time_to_minutes(time_str)
            events.append((time_minutes, action, station, pid))
        except (ValueError, IndexError):
            continue
    #Определение начала и конца отсчета
    start_time = time_to_minutes("05:00")
    end_time = time_to_minutes("23:30")
    total_duration = end_time - start_time
    #Начальные и конечные мероприятия, чтобы мы могли охватить весь день
    events.append((start_time, 'start', 1, -1))
    events.append((end_time, 'end', 10, -1))
    #Сортировка событий по времени
    events.sort(key=lambda x: x[0])
    #Обработка событий с использованием алгоритма развертки
    current_passengers = 0
    prev_time = start_time
    total_passenger_minutes = 0.0
    for event in events:
        time, action, station, pid = event
        #Подсчет времени с момента предыдущего события
        time_delta = time - prev_time
        if time_delta > 0:
            total_passenger_minutes += current_passengers * time_delta
        #Обновленеи количества пассажиров
        if action == 'in':
            current_passengers += 1
        elif action == 'out':
            current_passengers -= 1
        
        prev_time = time
    #Подсчет среднего
    average = total_passenger_minutes / total_duration
    #Формат вывода с 12 знаками после запятой
    print("{:.12f}".format(average))
if __name__ == "__main__":
    main()