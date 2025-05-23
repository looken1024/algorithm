public class Singleton {
    /*
     * 单例模式的饿汉式：
     * (1) 私有化该类的构造函数
     * (2) 通过new在本类中创建一个本类对象
     * (3) 定义一个公有的方法，将在该类中所创建的对象返回
     *
     * 优点：从它的实现中我们可以看到，这种方式的实现比较简单，在类加载的时候就完成了实例化，避免了线程的同步问题。
     * 缺点：由于在类加载的时候就实例化了，所以没有达到Lazy Loading(懒加载)的效果，也就是说可能我没有用到这个实例，但是它
     * 也会加载，会造成内存的浪费(但是这个浪费可以忽略，所以这种方式也是推荐使用的)。
    */
    private static final Singleton instance = null;

    static {
        instance = new Singleton();
    }

    private Singleton() {}

    public static Singleton getInstance() {
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
