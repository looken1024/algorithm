public enum Singleton {
    /*
     * 枚举（Enum）实现的单例模式是线程安全的，同时也是《Effective Java》中推荐的单例实现方式。
     * Java 语言规范明确规定：枚举类的初始化过程是线程安全的。
     * 枚举类型通过反射调用构造函数时会直接抛出 IllegalArgumentException（Java 禁止通过反射创建枚举实例），因此无法通过反射生成多个实例。
     * */
    INSTANCE;

    public void test() {
        System.out.println("Singleton class created");
    }

    public static void main(String[] args) {
        Singleton s1 = Singleton.INSTANCE;
        s1.test();
    }
}
