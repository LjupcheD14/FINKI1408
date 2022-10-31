public class DLLTester {

    public static void main(String[] args) {
        DLL<Integer> lista = new DLL<Integer>();
        lista.insertLast(5);
        System.out.print("Listata po vmetnuvanje na 5 kako posleden element: ");
        System.out.println(lista.toString()+" i obratno "+lista.toStringR());

        lista.insertFirst(3);
        System.out.print("Listata po vmetnuvanje na 3 kako prv element: ");
        System.out.println(lista.toString()+" i obratno "+lista.toStringR());

        lista.insertLast(1);
        System.out.print("Listata po vmetnuvanje na 1 kako posleden element: ");
        System.out.println(lista.toString()+" i obratno "+lista.toStringR());

        lista.deleteFirst();
        System.out.print("Listata po brishenje na prviot element: ");
        System.out.println(lista.toString()+" i obratno "+lista.toStringR());

        DLLNode<Integer> pom = lista.find(5);
        lista.insertBefore(2, pom);
        System.out.print("Listata po vmetnuvanje na elementot 2 pred elementot 5: ");
        System.out.println(lista.toString()+" i obratno "+lista.toStringR());

        pom = lista.find(1);
        lista.insertAfter(3, pom);
        System.out.print("Listata po vmetnuvanje na elementot 3 posle elementot 1: ");
        System.out.println(lista.toString()+" i obratno "+lista.toStringR());

        pom = lista.find(1);
        lista.insertAfter(6, pom);
        System.out.print("Listata po vmetnuvanje na elementot 6 posle elementot 1: ");
        System.out.println(lista.toString()+" i obratno "+lista.toStringR());

        pom = lista.find(3);
        lista.delete(pom);
        System.out.print("Listata po brishenje na elementot 3: ");
        System.out.println(lista.toString()+" i obratno "+lista.toStringR());

        System.out.println("Momentalna dolzina na listata: "+lista.getSize());

        lista.deleteList();
        System.out.print("Pecatenje na listata po nejzino brishenje: ");
        System.out.println(lista.toString()+" i obratno "+lista.toStringR());
        System.out.println("Momentalna dolzina na listata: "+lista.getSize());


    }

}
