package com.qualitycheck;

public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, PMD test!");
    }

    public void longMethod() {
        int sum = 0;
        for (int i = 0; i < 100; i++) {
            sum += i;
        }
        System.out.println(sum);
    }
}
