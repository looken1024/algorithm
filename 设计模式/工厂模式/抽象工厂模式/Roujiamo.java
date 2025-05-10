package com.looken;

public abstract class Roujiamo {
    protected String name;

    Roujiamo(String name) {
        this.name = name;
    }

    public void prepare(RoujiaMoYLFactory factory) {
        Meat meat = factory.createMeat();
        YuanLiao yuanLiao = factory.createYuanLiao();
        System.out.println("使用：" + meat.getName() + "，" + yuanLiao.getName());
    }

    public void fire() {

    }

    public void pack() {

    }
}
