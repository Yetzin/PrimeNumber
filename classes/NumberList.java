package classes;

public class NumberList {
    private static NumberList INSTANCE;
    public long[] list;

    private NumberList(int i) {
        this.list = new long[i];
    }

    public static NumberList getInstance() {
        return getInstance(0);
    }

    public static NumberList getInstance(int i) {
        if (INSTANCE == null) {
            INSTANCE = new NumberList(i);
        }

        return INSTANCE;
    }
}
