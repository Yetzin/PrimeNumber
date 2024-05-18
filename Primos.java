import classes.Threader;

public class Primos {
    public static void main(String[] args) {
        int i = Integer.valueOf(args[0]);

        Threader threader = new Threader(i);

        long primo = threader.getResult();

        System.out.println("El número primo en la posición " + i + " es " + primo);
    }
}
