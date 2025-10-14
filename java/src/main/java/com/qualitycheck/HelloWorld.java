package com.qualitycheck;

import java.util.logging.Logger;

public class HelloWorld {
    private static final Logger LOGGER = Logger.getLogger(HelloWorld.class.getName());

    public static void main(String[] args) {
        final int firstNumber = 10;
        final int secondNumber = 20;
        LOGGER.info("Sum: " + (firstNumber + secondNumber));
    }
}
