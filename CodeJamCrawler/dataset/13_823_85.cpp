import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


public class countSquarePalindromes {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int low, high;
		Scanner s = new Scanner(new File("test.txt"));
		PrintStream p = new PrintStream(new File("out.txt"));
		System.setOut(p);
		s.nextLine();
		int i = 0;
		while(s.hasNextInt()) {
			i++;
			low = s.nextInt();
			high = s.nextInt();
			System.out.printf("Case #%d: %d\n", i, countFairSquare(low, high));
		}
		s.close();
		p.close();
	}
	public static int countFairSquare(int low, int high) {
		int count = 0;
		for(int i = (int) Math.ceil(Math.sqrt(low)); i <= Math.sqrt(high); i++) {
			if(isPalindrome(i) && isPalindrome(i*i)) {
				count++;
			}
		}
		return count;
	}
	
	
	public static boolean isPalindrome(int i) {
		if(i - 10 < 0)
			return true;
		int hold = i;
		int rem = 0, rev = 0;
		while (i != 0) {
            rem = i % 10;
            rev = rev * 10 + rem;
            i = i / 10;
        }

        // if original and reverse of number is equal means
        // number is palindrome in Java
        if (hold == rev) {
            return true;
        }
        return false;
    }

}
