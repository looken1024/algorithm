package com.looken;

public class StrategyAdd implements Strategy {

    @Override
    public int execute(int a, int b) {
        return a + b;
    }
}
