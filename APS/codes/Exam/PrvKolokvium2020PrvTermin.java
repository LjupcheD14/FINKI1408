package PrvKolk;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class DLL<E> {
    private DLLNode<E> first = null;
    private DLLNode<E> last = null;

    public DLL() {
    }

    public void deleteList() {
        this.first = null;
        this.last = null;
    }

    public int length() {
        if (this.first == null) {
            return 0;
        } else {
            DLLNode<E> tmp = this.first;

            int ret;
            for (ret = 1; tmp.succ != null; ++ret) {
                tmp = tmp.succ;
            }

            return ret;
        }
    }

    public DLLNode<E> find(E o) {
        if (this.first != null) {
            DLLNode tmp;
            for (tmp = this.first; tmp.element != o && tmp.succ != null; tmp = tmp.succ) {
            }

            if (tmp.element == o) {
                return tmp;
            }

            System.out.println("Elementot ne postoi vo listata");
        } else {
            System.out.println("Listata e prazna");
        }

        return this.first;
    }

    public void insertFirst(E o) {
        DLLNode<E> ins = new DLLNode(o, (DLLNode) null, this.first);
        if (this.first == null) {
            this.last = ins;
        } else {
            this.first.pred = ins;
        }

        this.first = ins;
    }

    public void insertLast(E o) {
        if (this.first == null) {
            this.insertFirst(o);
        } else {
            DLLNode<E> ins = new DLLNode(o, this.last, (DLLNode) null);
            this.last.succ = ins;
            this.last = ins;
        }

    }

    public void insertAfter(E o, DLLNode<E> after) {
        if (after == this.last) {
            this.insertLast(o);
        } else {
            DLLNode<E> ins = new DLLNode(o, after, after.succ);
            after.succ.pred = ins;
            after.succ = ins;
        }
    }

    public void insertBefore(E o, DLLNode<E> before) {
        if (before == this.first) {
            this.insertFirst(o);
        } else {
            DLLNode<E> ins = new DLLNode(o, before.pred, before);
            before.pred.succ = ins;
            before.pred = ins;
        }
    }

    public E deleteFirst() {
        if (this.first != null) {
            DLLNode<E> tmp = this.first;
            this.first = this.first.succ;
            if (this.first != null) {
                this.first.pred = null;
            }

            if (this.first == null) {
                this.last = null;
            }

            return tmp.element;
        } else {
            return null;
        }
    }

    public E deleteLast() {
        if (this.first != null) {
            if (this.first.succ == null) {
                return this.deleteFirst();
            } else {
                DLLNode<E> tmp = this.last;
                this.last = this.last.pred;
                this.last.succ = null;
                return tmp.element;
            }
        } else {
            return null;
        }
    }

    public E delete(DLLNode<E> node) {
        if (node == this.first) {
            this.deleteFirst();
            return node.element;
        } else if (node == this.last) {
            this.deleteLast();
            return node.element;
        } else {
            node.pred.succ = node.succ;
            node.succ.pred = node.pred;
            return node.element;
        }
    }

    public String toString() {
        String ret = new String();
        if (this.first != null) {
            DLLNode<E> tmp = this.first;

            for (ret = ret + tmp + "<->"; tmp.succ != null; ret = ret + tmp + "<->") {
                tmp = tmp.succ;
            }
        } else {
            ret = "Prazna lista!!!";
        }

        return ret;
    }

    public String toStringR() {
        String ret = new String();
        if (this.last != null) {
            DLLNode<E> tmp = this.last;

            for (ret = ret + tmp + "<->"; tmp.pred != null; ret = ret + tmp + "<->") {
                tmp = tmp.pred;
            }
        } else {
            ret = "Prazna lista!!!";
        }

        return ret;
    }

    public DLLNode<E> getFirst() {
        return this.first;
    }

    public DLLNode<E> getLast() {
        return this.last;
    }

    public void izvadiDupliIPrebroj() {
    }
}

class DLLNode<E> {
    protected E element;
    protected DLLNode<E> pred;
    protected DLLNode<E> succ;

    public DLLNode(E elem, DLLNode<E> pred, DLLNode<E> succ) {
        this.element = elem;
        this.pred = pred;
        this.succ = succ;
    }

    public String toString() {
        return this.element.toString();
    }
}


public class PrvKolokvium2020PrvTermin<E> {

    private static DLL<Integer> srediSiGiListite(DLL<Integer> firstList, DLL<Integer> secondList) {
        DLL<Integer> result = new DLL();
        DLLNode<Integer> node1 = firstList.getLast();
        DLLNode<Integer> node2 = secondList.getFirst();

        while (node1 != null && node2 != null) {
            if (node1.element > node2.element) {
                result.insertLast(node1.element);
                node1 = node1.pred;
            } else if (node1.element == node2.element) {
                result.insertLast(node1.element);
                node1 = node1.pred;
                node2 = node2.succ;
            } else {
                result.insertLast(node2.element);
                node2 = node2.succ;
            }
        }

        while (node1 != null) {
            result.insertLast(node1.element);
            node1 = node1.pred;
        }

        while (node2 != null) {
            result.insertLast(node2.element);
            node2 = node2.succ;
        }

        return result;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] parts = br.readLine().split("\\s+");
        int M = Integer.parseInt(parts[0]);
        int N = Integer.parseInt(parts[1]);
        DLL<Integer> firstList = new DLL();
        parts = br.readLine().split("\\s+");

        for (int i = 0; i < M; ++i) {
            firstList.insertLast(Integer.parseInt(parts[i]));
        }

        DLL<Integer> secondList = new DLL();
        parts = br.readLine().split("\\s+");

        for (int i = 0; i < N; ++i) {
            secondList.insertLast(Integer.parseInt(parts[i]));
        }

        DLL<Integer> resultList = srediSiGiListite(firstList, secondList);
        System.out.println(resultList);
    }


}
