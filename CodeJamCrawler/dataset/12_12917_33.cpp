import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) throws Throwable {
		Scanner in = new Scanner(new File("a.in"));
		PrintWriter out = new PrintWriter("a.out");
		int testCount = Integer.parseInt(in.nextLine().trim());
		for (int i = 0; i < testCount; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solveStupid(in, out);
		}
		out.close();
	}

	static void solveStupid(Scanner in, PrintWriter out) {
		int n = in.nextInt();
		int[] d = new int[n + 2];
		int[] len = new int[n + 2];
		for (int i = 1; i <= n; i++) {
			d[i] = in.nextInt();
			len[i] = in.nextInt();
		}
		int allD = in.nextInt();
		d[n + 1] = allD;
		int[][] can = new int[n + 2][n + 2];
		can[1][0] = 1;
		for (int i = 2; i <= n + 1; i++) {
			for (int j = 1; j < i; j++) {
				int dist = d[i] - d[j];
				if (len[j] < dist) {
					continue;
				}
				for (int k = 0; k < j; k++) {
					if (can[j][k] == 1 && d[j] - d[k] >= dist) {
						can[i][j] = 1;
						break;
					}
				}
				if (can[i][j] == 1 && i == n + 1) {
					out.println("YES");
					return;
				}
			}
		}
		out.println("NO");
	}
}
