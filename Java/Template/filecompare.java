import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class filecompare {

    public static void main(String[] args) {
        String file1Path = "file1.txt"; // Replace with the path to your first file
        String file2Path = "file2.txt"; // Replace with the path to your second file
        String logFilePath = "log.txt"; // Path to the log file

        compareAndCreateLog(file1Path, file2Path, logFilePath);
        System.out.println("Comparison completed. Differences logged in log.txt");
    }

    private static void compareAndCreateLog(String file1Path, String file2Path, String logFilePath) {
        try (BufferedReader reader1 = new BufferedReader(new FileReader(file1Path));
             BufferedReader reader2 = new BufferedReader(new FileReader(file2Path));
             BufferedWriter writer = new BufferedWriter(new FileWriter(logFilePath))) {

            int lineNum = 1;
            String line1, line2;

            while ((line1 = reader1.readLine()) != null && (line2 = reader2.readLine()) != null) {
                String[] words1 = line1.split("\\s+");
                String[] words2 = line2.split("\\s+");

                for (int i = 0; i < Math.min(words1.length, words2.length); i++) {
                    if (!words1[i].equals(words2[i])) {
                        // Write the mismatching word and its position to the log file
                        writer.write("Line " + lineNum + ", Word " + (i + 1) + ":");
                        writer.newLine();
                        writer.write("File 1: " + words1[i]);
                        writer.newLine();
                        writer.write("File 2: " + words2[i]);
                        writer.newLine();
                        writer.newLine();
                    }
                }

                lineNum++;
            }

            System.out.println("Comparison completed.");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
