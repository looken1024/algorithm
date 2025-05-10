package com.looken;

public class Observer1 implements Observer {

    public Observer1(Subject subject) {
        subject.registerObserver(this);
    }

    @Override
    public void update(String msg) {
        System.out.println("Observer1 收到：" + msg);
    }
}
