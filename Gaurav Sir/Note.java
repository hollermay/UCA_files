import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

class TreeNode {
    String word;
    int count;
    TreeNode left, right;

    TreeNode(String word) {
        this.word = word;
        this.count = 1;
        this.left = this.right = null;
    }
}

class BST {
    private TreeNode root;

    public void insert(String word) {
        if (word.length() == 10) {
            root = insertRec(root, word);
        }
    }

    private TreeNode insertRec(TreeNode root, String word) {
        if (root == null) {
            root = new TreeNode(word);
            return root;
        }
        if (word.compareTo(root.word) < 0) {
            root.left = insertRec(root.left, word);
        } else if (word.compareTo(root.word) > 0) {
            root.right = insertRec(root.right, word);
        } else {
            root.count++;
        }
        return root;
    }

    public String[] findMostFrequent() {
        return findMostFrequentRec(root, new int[]{0}, new String[]{null});
    }

    private String[] findMostFrequentRec(TreeNode root, int[] maxCount, String[] mostFrequentWord) {
        if (root != null) {
            findMostFrequentRec(root.left, maxCount, mostFrequentWord);
            if (root.count > maxCount[0]) {
                maxCount[0] = root.count;
                mostFrequentWord[0] = root.word;
            }
            findMostFrequentRec(root.right, maxCount, mostFrequentWord);
        }
        return new String[]{mostFrequentWord[0], String.valueOf(maxCount[0])};
    }
}

public class Note {
    public static void main(String[] args) {
        String filePath = "test.txt"; // Replace with your file path
        BST bst = new BST();

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] words = line.split("\\s+");
                for (String word : words) {
                    word = word.toLowerCase().replaceAll("[^a-zA-Z]", "");
                    if (!word.isEmpty()) {
                        bst.insert(word);
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        String[] mostFrequentWord = bst.findMostFrequent();
        if (mostFrequentWord[0] != null) {
            System.out.println("The most frequent word with more than 10 letters is: " + mostFrequentWord[0] + " with count: " + mostFrequentWord[1]);
        } else {
            System.out.println("No words with more than 10 letters found in the file.");
        }
    }
}