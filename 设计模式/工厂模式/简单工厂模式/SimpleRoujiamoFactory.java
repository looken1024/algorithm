package com.looken;

public class SimpleRoujiamoFactory {
    public Roujiamo creatRoujiaMo(String type) {
        Roujiamo roujiaMo = null;
        switch (type) {
            case "1":
                roujiaMo = new Roujiamo1();
                break;
            case "2":
                roujiaMo = new Roujiamo2();
                break;
        }
        return roujiaMo;
    }

    public static void main(String[] args) {
        Roujiamo roujiamo1 = new SimpleRoujiamoFactory().creatRoujiaMo("1");
        System.out.println(roujiamo1.name);
    }
}
