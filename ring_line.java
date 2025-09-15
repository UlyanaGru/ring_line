import java.util.*;
import java.util.stream.Collectors;

public class Main {
    //Конвертирует строку времени 'hh:mm' в минуты с 00:00
    private static int timeToMinutes(String timeStr) {
        String[] parts = timeStr.split(":");
        int hours = Integer.parseInt(parts[0]);
        int minutes = Integer.parseInt(parts[1]);
        return hours * 60 + minutes;
    }
    //Класс для представления события (вход/выход пассажира)
    static class Event {
        int time;           //время в минутах с 00:00
        String action;      //действие: "in" или "out"
        int station;        //номер станции
        int pid;            //идентификатор пассажира
        Event(int time, String action, int station, int pid) {
            this.time = time;
            this.action = action;
            this.station = station;
            this.pid = pid;
        }
    }
    
    