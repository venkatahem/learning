Enumeration -> Counting things

## Internal working for Day Enum

```java
public final class Day extends java.lang.Enum<Day>{
    public static final Day SUN = new Day("SUN",0);
    public static final Day MON = new Day("MON",1);
    public static final Day TUE = new Day("TUE",2);
    public static final Day WED = new Day("WED",3);
    public static final Day THU = new Day("THU",4);
    public static final Day FRI = new Day("FRI",5);
    public static final Day SAT = new Day("SAT",6);

    private static final Day[] VALUES = {SUN, MON, TUE, WED, THU, FRI, SAT};

    private Day(String naem, int ordinal){
        super(name,ordinal);
    }

    public static Day[] values() {
        return VALUES.clone();
    }

    public static Day valueOf(Sting name){
        for (Day day: VALUES){
            if(day.name().equals(name)){
                return day;
            }
        }
        throw new IllegalArgumentException("No enum constant "+name)
    }
}
```
ENUM finally converts in a class, so we can write methods also.