import java.util.Scanner;

class SLLNode {
    String name;
    int price;
    SLLNode succ;

    public SLLNode(String name, int price, SLLNode succ) {
        this.name = name;
        this.price = price;
        this.succ = succ;
    }

    @Override
    public String toString() {
        return name;
    }
}

class SLL {
    SLLNode first;

    public SLL() {
        this.first = null;
    }

    public void insertFirst(String name, int price) {
        SLLNode ins = new SLLNode(name, price, first);
        first = ins;
    }

    public void insertLast(String name, int price) {
        if (first != null) {
            SLLNode tmp = first;
            while (tmp.succ != null)
                tmp = tmp.succ;
            SLLNode ins = new SLLNode(name, price, null);
            tmp.succ = ins;
        } else {
            insertFirst(name, price);
        }
    }

    @Override
    public String toString() {
        StringBuilder ret = new StringBuilder();
        if (first != null) {
            SLLNode tmp = first;
            ret.append(tmp).append("\n");
            while (tmp.succ != null) {
                tmp = tmp.succ;
                ret.append(tmp).append("\n");
            }
        } else
            ret = new StringBuilder("NO ELEMENTS");
        return ret.toString();
    }

}

public class PrvKolk2021_1 {

    public static void removeCakes(SLL cakes) {
        // TODO: implement method
        SLLNode node = cakes.first;
        double avg = 0.0;
        int sum = 0;
        int counter = 0;

        while (node != null) {
            counter++;
            sum += node.price;
            node = node.succ;
        }

        avg = sum / counter;

        node = cakes.first;

        while (node.succ != null) {
            if (cakes.first.price > avg) {
                cakes.first = cakes.first.succ;
            }
            if (node.succ.price > avg) {
                node.succ = node.succ.succ;
                continue;
            }
            node = node.succ;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        SLL cakes = new SLL();

        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            String[] parts = line.split("\\s+");
            cakes.insertLast(parts[0], Integer.parseInt(parts[1]));
        }

        removeCakes(cakes);
        System.out.println(cakes.toString());
    }
}
