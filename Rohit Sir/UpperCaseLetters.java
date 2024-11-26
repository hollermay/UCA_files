import java.util.*;
import java.util.stream.*;
import java.lang.*;
import java.io.*;

class UpperCaseLetters  {
    public static void main(String[] args) throws IOException {
        List<String> names = Arrays.asList("Alice","Bob","Charlie","David");

        List<String> filtered = names.stream()
                .filter((name) -> name.charAt(0) == 'A')
                .collect(Collectors.toList());

        //uppercase all letters
        List<String> filteredNames = names.stream()
                .filter((name) -> name !=null)
                .map(String::toUpperCase)
                .collect(Collectors.toList());


        // Combining All names
        Optional<String> combinedName = names.stream() // Optional String is an advanced concept.
                .filter((name) -> name!=null)
                .reduce((a,b) -> a+b);

        System.out.println(combinedName.get());
        //When you don't pass an argument you need atleast two arguments to combine
    }

}
