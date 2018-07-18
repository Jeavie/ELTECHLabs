package org.jeavie;

import java.util.Arrays;

/**
 * @author Jeavie
 * Date created: 7/18/18
 * @version 0.1
 */
public class Main {

    /**
     * main method
     * @param args
     */

    public static void main(String[] args) {

        /** @param array is int array initialized with numbers*/
        int [] array = {1, 2, 5, 0, 9, 3, 4, 6, 8, 7};

        Arrays.sort(array);

        System.out.println("Sorted arr[] : " + Arrays.toString(array));
    }
}