package com.qualitycheck;

import java.util.logging.Logger;

public class HelloWorld {
    private static final Logger LOGGER = Logger.getLogger(HelloWorld.class.getName());

    public static void main(String[] args) {
        final int firstNumber = 10;
        final int secondNumber = 20;
        final int sum = firstNumber + secondNumber;

        // ✅ Guard the log statement with a level check
        if (LOGGER.isLoggable(java.util.logging.Level.INFO)) {
            LOGGER.info("Sum: " + sum);
        }
    }
}

