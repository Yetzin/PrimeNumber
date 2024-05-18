package classes;

public class Threader {
    NumberList numbers;
    int i;

    public Threader(int i) {
        this.i = i;
        this.numbers = NumberList.getInstance(i);
        this.numbers.list[0] = 2;
        // if (i > 1) {
        //     this.numbers.list[1] = 3;
        // }
    }

    public long getResult() {
        return this.numbers.list[this.i-1];
    }
}
