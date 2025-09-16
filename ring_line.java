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
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Event> events = new ArrayList<>();
        //Чтение всех входных строк
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine().trim();
            if (line.isEmpty()) continue;
            String[] parts = line.split("\\s+");
            if (parts.length < 4) continue;
            try {
                int pid = Integer.parseInt(parts[0]);
                String action = parts[1];
                int station = Integer.parseInt(parts[2]);
                String timeStr = parts[3];
                int timeMinutes = timeToMinutes(timeStr);
                events.add(new Event(timeMinutes, action, station, pid));
            } catch (NumberFormatException e) {
                continue; //Пропускаем некорректные строки
            }
        }
        scanner.close();
    
    