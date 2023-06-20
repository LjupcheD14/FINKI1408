import java.util.Scanner;

public class Jun2022_1 {
    public static void orders(SLL<Order> aktivna, SLL<Order> ship) {
        SLLNode<Order> node1 = aktivna.getFirst();
        SLLNode<Order> tmp1 = null;
        int min = 999;

        while (node1 != null) {
            if (node1.element.getPriority() <= min) {
                min = node1.element.getPriority();
                tmp1 = node1;
            }
            node1 = node1.succ;
        }
        aktivna.delete(tmp1);
        ship.insertLast(tmp1.element);


        node1 = aktivna.getFirst();
        tmp1 = null;
        int min2 = 999;

        while (node1 != null) {
            if (node1.element.getPriority() <= min2) {
                min2 = node1.element.getPriority();
                tmp1 = node1;
            }
            node1 = node1.succ;
        }
        aktivna.delete(tmp1);
        ship.insertLast(tmp1.element);

    }

    public static void main(String[] args) {
        SLL<Order> active = new SLL<>();
        SLL<Order> shipping = new SLL<>();
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();
        for (int i = 0; i < n; i++) {
            int id = input.nextInt();
            int product = input.nextInt();
            int priority = input.nextInt();
            Order nov = new Order(id, product, priority);
            active.insertLast(nov);
        }
        for (int i = 0; i < m; i++) {
            int id = input.nextInt();
            int product = input.nextInt();
            int priority = input.nextInt();
            Order nov2 = new Order(id, product, priority);
            shipping.insertLast(nov2);
        }

        orders(active, shipping);
        System.out.println(active.toString());
        System.out.println(shipping.toString());
    }
}

class Order {
    private int id;
    private int product;
    private int priority;

    public Order(int id, int product, int priority) {
        this.id = id;
        this.product = product;
        this.priority = priority;
    }

    public int getId() {
        return id;
    }

    public int getProduct() {
        return product;
    }

    public int getPriority() {
        return priority;
    }

    @Override
    public String toString() {
        return String.valueOf(id);
    }

}

class SLL<E> {
    private SLLNode<E> first;

    public SLL() {
        // Construct an empty SLL
        this.first = null;
    }

    public void deleteList() {
        first = null;
    }

    public int length() {
        int ret;
        if (first != null) {
            SLLNode<E> tmp = first;
            ret = 1;
            while (tmp.succ != null) {
                tmp = tmp.succ;
                ret++;
            }
            return ret;
        } else
            return 0;

    }

    @Override
    public String toString() {
        String ret = new String();
        if (first != null) {
            SLLNode<E> tmp = first;
            ret += tmp + " ";
            while (tmp.succ != null) {
                tmp = tmp.succ;
                ret += tmp + " ";
            }
        } else
            ret = "Prazna lista!!!";
        return ret;
    }

    public void insertFirst(E o) {
        SLLNode<E> ins = new SLLNode<E>(o, first);
        first = ins;
    }

    public void insertAfter(E o, SLLNode<E> node) {
        if (node != null) {
            SLLNode<E> ins = new SLLNode<E>(o, node.succ);
            node.succ = ins;
        } else {
            System.out.println("Dadenot jazol e null");
        }
    }

    public void insertBefore(E o, SLLNode<E> before) {

        if (first != null) {
            SLLNode<E> tmp = first;
            if (first == before) {
                this.insertFirst(o);
                return;
            }
            //ako first!=before
            while (tmp.succ != before)
                tmp = tmp.succ;
            if (tmp.succ == before) {
                SLLNode<E> ins = new SLLNode<E>(o, before);
                tmp.succ = ins;
            } else {
                System.out.println("Elementot ne postoi vo listata");
            }
        } else {
            System.out.println("Listata e prazna");
        }
    }

    public void insertLast(E o) {
        if (first != null) {
            SLLNode<E> tmp = first;
            while (tmp.succ != null)
                tmp = tmp.succ;
            SLLNode<E> ins = new SLLNode<E>(o, null);
            tmp.succ = ins;
        } else {
            insertFirst(o);
        }
    }

    public E deleteFirst() {
        if (first != null) {
            SLLNode<E> tmp = first;
            first = first.succ;
            return tmp.element;
        } else {
            System.out.println("Listata e prazna");
            return null;
        }
    }

    public E delete(SLLNode<E> node) {
        if (first != null) {
            SLLNode<E> tmp = first;
            if (first == node) {
                return this.deleteFirst();
            }
            while (tmp.succ != node && tmp.succ.succ != null)
                tmp = tmp.succ;
            if (tmp.succ == node) {
                tmp.succ = tmp.succ.succ;
                return node.element;
            } else {
                System.out.println("Elementot ne postoi vo listata");
                return null;
            }
        } else {
            System.out.println("Listata e prazna");
            return null;
        }

    }

    public SLLNode<E> getFirst() {
        return first;
    }


    public SLLNode<E> find(E o) {
        if (first != null) {
            SLLNode<E> tmp = first;
            while (tmp.element != o && tmp.succ != null)
                tmp = tmp.succ;
            if (tmp.element == o) {
                return tmp;
            } else {
                System.out.println("Elementot ne postoi vo listata");
            }
        } else {
            System.out.println("Listata e prazna");
        }
        return first;
    }


}

class SLLNode<E> {
    protected E element;
    protected SLLNode<E> succ;

    public SLLNode(E elem, SLLNode<E> succ) {
        this.element = elem;
        this.succ = succ;
    }

    @Override
    public String toString() {
        return element.toString();
    }
}
