import javax.swing.*;

class Loops {

    public static void main(String[] args) {

        Loops miAmigoPedro = new Loops();
        int[] myArray = miAmigoPedro.initializeArray(
                miAmigoPedro.getRandomInt(10, 15));
        miAmigoPedro.printArray(myArray);
        miAmigoPedro.bubbleSort(myArray);
        miAmigoPedro.printArray(myArray);
    }

    int getRandomInt(int min, int max) {

        return (int) (Math.random() * (max - min + 1) + min);
    }

    int getRandomInt() {

        return (int) (Math.random() * 100);
    }

    int[] initializeArray(int size) {

        int[] myArray = new int[size];
        for (int i = 0; i < size; i++) {
            myArray[i] = getRandomInt();
        }
        return myArray;
    }

    void printArray(int[] arr) {

        StringBuilder output = new StringBuilder();
        for (int j : arr) output.append(j).append(" ");
        JOptionPane.showMessageDialog(null, output.toString());
    }

    void bubbleSort(int[] arr) {
        int n = arr.length;
        boolean swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // swap arr[j] and arr[j+1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            // IF no two elements were swapped in the inner loop, then the array is already sorted
            if (!swapped) {
                break;
            }
        }
    }
}
