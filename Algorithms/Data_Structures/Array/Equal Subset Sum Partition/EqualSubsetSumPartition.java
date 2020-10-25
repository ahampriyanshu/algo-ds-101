package teste;

import java.util.Arrays;
import java.util.Scanner;

public class EqualSubsetSumPartition {
	public boolean isPartion(Integer[] array) {
		int elementsSum = Arrays.stream(array).mapToInt(Integer::intValue)
				.sum();
		int startIndex = 0;
		if (isOddNumber(elementsSum)) {
			return false;
		}
		return this.verifyPartion(array, elementsSum / 2, startIndex);
	}

	private boolean isOddNumber(int elementsSum) {
		return (elementsSum % 2) != 0;
	}

	private boolean verifyPartion(Integer[] array, int elementsSum,
			int currentIndex) {
		if (elementsSum == 0) {
			return true;
		}
		if ((array.length == 0) || (currentIndex >= (array.length - 1))) {
			return false;
		}
		if (array[currentIndex] <= elementsSum) {
			if (verifyPartion(array, elementsSum - array[currentIndex],
					currentIndex + 1)) {
				return true;
			}
		}
		return verifyPartion(array, elementsSum, currentIndex + 1);
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter the length of the array:");
		int length = scanner.nextInt();
		Integer[] array = new Integer[length];
		System.out.println("Enter the elements of the array:");

		for (int i = 0; i < length; i++) {
			array[i] = scanner.nextInt();
		}

		EqualSubsetSumPartition ps = new EqualSubsetSumPartition();
		System.out.println(ps.isPartion(array));
	}

}
