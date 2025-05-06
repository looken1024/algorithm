public class Singleton {
    private static Singleton instance;

    private Singleton() {}

    public static Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }

    public void test() {
        System.out.println("Singleton class created");
    }

    public static void main(String[] args) {
        Singleton s1 = Singleton.getInstance();
        s1.test();
    }
}
