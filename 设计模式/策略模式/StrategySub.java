package com.looken;

public class StrategySub implements Strategy {

    @Override
    public int execute(int a, int b) {
        return a - b;
    }
}
