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
    
    