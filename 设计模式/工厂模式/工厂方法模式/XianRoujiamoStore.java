package com.looken;

public class XianRoujiamoStore extends RoujiamoStore {

    private XianRoujiamoFactory factory;

    XianRoujiamoStore(XianRoujiamoFactory factory) {
        this.factory = factory;
    }

    public Roujiamo sell(String type) {
        Roujiamo roujiamo = factory.creatRoujiaMo(type);
        roujiamo.prepare();
        roujiamo.fire();
        roujiamo.pack();
        return roujiamo;
    }

    public static void main(String[] args) {
        RoujiamoStore store = new XianRoujiamoStore(new XianRoujiamoFactory());
        Roujiamo roujiamo = store.sell("1");
        System.out.println(roujiamo.name);
    }
}
