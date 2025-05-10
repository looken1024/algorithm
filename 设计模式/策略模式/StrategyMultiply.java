package com.looken;

public class StrategyMultiply implements Strategy {

    @Override
    public int execute(int a, int b) {
        return a * b;
    }
}
