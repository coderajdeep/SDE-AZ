import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.lang.String;

public class Main {
    public static boolean NodeIntersection(String[] nodes, Map<String, String> graph) throws Exception {
        Set<String> visited = new HashSet<>();
        for (String node : nodes) {
            Set<String> currentVisited = new HashSet<>();
            String listNode = node;
            do {
                if (currentVisited.contains(listNode))
                    throw new Exception("Error Thrown!");
                if (visited.contains(listNode))
                    return true;
                visited.add(listNode);
                currentVisited.add(listNode);
                listNode = graph.get(listNode);
            } while (listNode != null);
        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        Map<String, String> graph = new HashMap<>();
        InputStreamReader rd = new InputStreamReader(System.in, StandardCharsets.UTF_8);
        BufferedReader in = new BufferedReader(rd);
        String InputString;
        while ((InputString = in.readLine()) != null) {
            if (InputString.contains("->")) {
                String[] inputs = InputString.split("->");
                String node1 = inputs[0];
                String node2 = inputs[1];
                graph.put(node1, node2);
            }

            else if (InputString.contains(",")) {

                String[] inputs = InputString.split(",");

                for (int i = 0; i < inputs.length; i++) {
                    inputs[i] = inputs[i].trim();
                }

                try {
                    boolean result = NodeIntersection(inputs, graph);
                    if (result) {
                        System.out.println("True");
                    } else {
                        System.out.println("False");
                    }
                }

                catch (Exception e) {
                    System.out.println("Error Thrown!");
                }
            }
        }
    }
}