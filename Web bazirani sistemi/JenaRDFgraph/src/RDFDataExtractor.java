import org.apache.jena.rdf.model.*;
import org.apache.jena.vocabulary.RDFS;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RDFDataExtractor {
    public static void main(String[] args) {
        Model model = ModelFactory.createDefaultModel();

        String filePath = "C:\\Users\\User\\FINKI\\JenaRDFgraph\\src\\hifm-dataset.ttl";

        model.read(filePath, "TTL");

        Resource drug = model.getResource("<http://purl.org/net/hifm/data#986224");

        // Iterate over all statements where the drug is the subject
        StmtIterator iter = model.listStatements(drug, null, (RDFNode) null);

        System.out.println("Listing all relations and values for the drug:");
        while (iter.hasNext()) {
            Statement stmt = iter.nextStatement();
            Property predicate = stmt.getPredicate();
            RDFNode object = stmt.getObject();

            // Print predicate (relation) and object (value)
            System.out.print(predicate.getLocalName() + " - ");
            if (object.isLiteral()) {
                System.out.println("\"" + object.asLiteral().getString() + "\"");
            } else if (object.isResource()) {
                System.out.println(object.asResource().getURI());
            }
        }
    }
}
