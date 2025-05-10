package com.looken;

public class SquarePegAdapter extends RoundPeg {
    private SquarePeg squarePeg;

    SquarePegAdapter(SquarePeg squarePeg) {
        super(0);
        this.squarePeg = squarePeg;
    }

    public double getRadius() {
        return squarePeg.getWidth() * Math.sqrt(2) / 2;
    }
}
