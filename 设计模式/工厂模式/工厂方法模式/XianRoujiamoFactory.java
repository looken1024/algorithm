package com.looken;

public class XianRoujiamoFactory {
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
}
