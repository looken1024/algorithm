package com.looken;

// https://refactoringguru.cn/design-patterns/strategy
public class Context {
    private Strategy strategy;

    Context(Strategy strategy) {
        this.strategy = strategy;
    }

    public int execute(int a, int b) {
        return strategy.execute(a, b);
    }

    public static void main(String[] args) {
        Context context = new Context(new StrategyAdd());
        System.out.println(context.execute(1, 2));
    }
}
