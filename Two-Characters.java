import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'alternate' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts STRING s as parameter.
     */
    
    public static int alternate2(String s) {
        List<Integer> vec = new ArrayList<>();

        for (int i = 0; i < s.length() - 1; ++i) {
            for (int j = i + 1; j < s.length(); ++j) {
                StringBuilder str = new StringBuilder();
                for (int k = 0; k < s.length(); ++k) {
                    if (s.charAt(k) == s.charAt(i) || s.charAt(k) == s.charAt(j)) {
                        str.append(s.charAt(k));
                    }
                }

                boolean check = true;
                for (int k = 0; k < str.length() - 1; ++k) {
                    if (str.charAt(k) == str.charAt(k + 1)) {
                        check = false;
                        break;
                    }
                }

                if (check) vec.add(str.length());
            }
        }

        return vec.isEmpty() ? 0 : Collections.max(vec);
    }    
}


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int l = Integer.parseInt(bufferedReader.readLine().trim());

        String s = bufferedReader.readLine();

        int result = Result.alternate(s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
