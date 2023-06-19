import java.util.Scanner;

class Athlete {
    private int id;
    private double time;

    public Athlete(int id, double time) {
        this.id = id;
        this.time = time;
    }

    public int getId() {
        return id;
    }

    public double getTime() {
        return time;
    }

    @Override
    public String toString() {
        return String.valueOf(id);
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

class SLL<E> {
    private SLLNode<E> first;

    public SLL() {
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
            ret += tmp;
            while (tmp.succ != null) {
                tmp = tmp.succ;
                ret += " " + tmp;
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

public class Sept2021_1 {

    //todo: implement function
    public static void competition(SLL<Athlete> prevWin, SLL<Athlete> currWin) {
        SLLNode<Athlete> node1 = prevWin.getFirst();
        SLLNode<Athlete> node2 = currWin.getFirst();
        double max = 0.00;
//        SLLNode<Athlete> tmp = null;

        while (node1 != null) {
            if (node1.element.getTime() > max) {
                max = node1.element.getTime();
//                tmp = node1;
            }
            node1 = node1.succ;
        }

        while (node2 != null) {

            if (node2.element.getTime() > max) {
                currWin.delete(node2);
            }
            node2 = node2.succ;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int prevWinnersCount = Integer.parseInt(scanner.nextLine());
        int currYearRunnersCount = Integer.parseInt(scanner.nextLine());
        SLL<Athlete> prevWinners = new SLL<Athlete>();
        SLL<Athlete> currYearRunners = new SLL<Athlete>();

        for (int i = 0; i < prevWinnersCount; i++) {
            String line = scanner.nextLine();
            String[] parts = line.split("\\s+");
            prevWinners.insertLast(new Athlete(Integer.parseInt(parts[0]), Double.parseDouble(parts[1])));
        }

        for (int i = 0; i < currYearRunnersCount; i++) {
            String line = scanner.nextLine();
            String[] parts = line.split("\\s+");
            currYearRunners.insertLast(new Athlete(Integer.parseInt(parts[0]), Double.parseDouble(parts[1])));
        }

        competition(prevWinners, currYearRunners);
        System.out.println(currYearRunners.toString());
    }
}
