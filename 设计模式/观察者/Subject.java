package com.looken;

public interface Subject {

    public void registerObserver(com.looken.Observer o);

    public void removeObserver(com.looken.Observer o);

    public void notifyObservers();

}
