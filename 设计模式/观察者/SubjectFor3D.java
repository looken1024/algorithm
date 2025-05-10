package com.looken;

import java.util.ArrayList;
import java.util.List;

public class SubjectFor3D implements Subject{

    private List<Observer> observers = new ArrayList<Observer>();

    private String msg;

    @Override
    public void registerObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyObservers() {
        for (Observer o : observers) {
            o.update(msg);
        }
    }

    public void setMsg(String msg) {
        this.msg = msg;
        notifyObservers();
    }
}
