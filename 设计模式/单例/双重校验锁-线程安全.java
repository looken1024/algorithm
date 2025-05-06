public class Singleton {
    private volatile static Singleton instance;

    private Singleton() {}

    public static Singleton getInstance() {
        if (instance == null) {
            synchronized (Singleton.class) {
                if (instance == null) {
                    instance = new Singleton();
                }
            }
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
