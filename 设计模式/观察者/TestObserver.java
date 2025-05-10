package com.looken;

public class TestObserver {
    public static void main(String[] args) {
        SubjectFor3D subject = new SubjectFor3D();

        Observer1 observer1 = new Observer1(subject);
        Observer2 observer2 = new Observer2(subject);

        subject.setMsg("Hello World");
    }
}