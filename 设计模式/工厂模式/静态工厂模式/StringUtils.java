package com.looken;

public class StringUtils {
    public static boolean isEmpty(String s) {
        return s == null || s.isEmpty();
    }

    public static void main(String[] args) {
        System.out.println(isEmpty(""));
    }
}

