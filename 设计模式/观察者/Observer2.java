package com.looken;

public class Observer2 implements Observer {

    public Observer2(Subject subject) {
        subject.registerObserver(this);
    }

    @Override
    public void update(String msg) {
        System.out.println("Observer2 收到：" + msg);
    }
}
