package com.looken;

public class XianRoujiamoYLFactory implements RoujiaMoYLFactory{
    @Override
    public Meat createMeat() {
        Meat meat = new XianMeat();
        return meat;
    }

    @Override
    public YuanLiao createYuanLiao() {
        YuanLiao yuanLiao = new XianYuanLiao();
        return yuanLiao;
    }
}
