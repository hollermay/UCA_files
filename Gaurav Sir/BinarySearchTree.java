public class BinarySearchTree
{
    class Node
    {
        int key;
        int value;
        Node left;
        Node right;

        Node(int key, int value)
        {
            this.key = key;
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }

    Node root;

    BinarySearchTree()
    {
        this.root = null;
    }

    public Integer get(Integer key)
    {
        return get(root, key);
    }

    private Integer get(Node x, Integer key)
    {
    if (x == null)
    {
        return null;
    }
    if (key < x.key)
    {
        return get(x.left, key);
    }
    else if (key > x.key)
    {
        return get(x.right, key);
    }
    else
    {
        return x.value;
    }
}

    public void put(Integer key, Integer value)
    {
        root = put(root, key, value);
    }

    private Node put(Node x, Integer key, Integer value)
    {
        if (x == null)
        {
            return new Node(key, value);
        }
        if (key < x.key)
        {
            x.left = put(x.left, key, value);
        }
        else if (key > x.key)
        {
            x.right = put(x.right, key, value);
        }
        else
        {
            x.value = value;
        }
        return x;
    }

    public static void main(String[] args)
    {
        BinarySearchTree bst = new BinarySearchTree();
        bst.put(5, 3);
        bst.put(3, 5);
        bst.put(1, 6);
        bst.put(7, 3);
        bst.put(9, 1);
        
        assert bst.get(5) == 3;
        assert bst.get(3) == 5;

        try (FileReader fr = new FileReader("test.txt");
             BufferedReader br = new BufferedReader(fr)) {
            int maxCount = 0;
            String mostFrequentWord = "";
        
            String line;
            while ((line = br.readLine()) != null) {
                String word = line.trim();
                Integer count = bst.get(word);
                if (count == null) {
                    count = 0;
                }
                bst.put(word, count + 1);
                if (count + 1 > maxCount) {
                    maxCount = count + 1;
                    mostFrequentWord = word;
                }
            }
            System.out.println("Most frequent word: " + mostFrequentWord + " with count: " + maxCount);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
