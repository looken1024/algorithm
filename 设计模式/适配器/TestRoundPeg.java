package com.looken;

public class TestRoundPeg {
    public static void main(String[] args) {
        RoundHole roundHole = new RoundHole(10.1);
        RoundPeg roundPeg = new RoundPeg(10.1);
        System.out.println(roundHole.fit(roundPeg));

        SquarePeg squarePeg = new SquarePeg(20.2);
        System.out.println(roundHole.fit(new SquarePegAdapter(squarePeg)));
    }
}
