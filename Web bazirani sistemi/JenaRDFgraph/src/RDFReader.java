import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.rdf.model.StmtIterator;
import org.apache.jena.rdf.model.Statement;

public class RDFReader {
    public static void main(String[] args) {

        Model model = ModelFactory.createDefaultModel();

        String inputFileName = "labfile.rdf";
        model.read(inputFileName);


        System.out.println("Printing RDF triples:");
        StmtIterator iterator = model.listStatements();
        while (iterator.hasNext()) {
            Statement stmt = iterator.nextStatement();
            String subject = stmt.getSubject().toString();
            String predicate = stmt.getPredicate().toString();
            String object = stmt.getObject().isLiteral()
                    ? "\"" + stmt.getObject().toString() + "\""
                    : stmt.getObject().toString();

            System.out.println(subject + " – " + predicate + " – " + object);
        }
    }
}
