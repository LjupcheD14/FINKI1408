public class ListMirrorTest {

    public static void main(String[] args) {
        DLL<String> lista = new DLL<String>();
        lista.insertLast("ovaa");
        lista.insertLast("lista");
        lista.insertLast("kje");
        lista.insertLast("bide");
        lista.insertLast("prevrtena");

        System.out.println("Listata pred da bide prevrtena");
        System.out.println(lista.toString());

        lista.mirror();

        System.out.println("Listata otkako e prevrtena");
        System.out.println(lista.toString());
    }
}
