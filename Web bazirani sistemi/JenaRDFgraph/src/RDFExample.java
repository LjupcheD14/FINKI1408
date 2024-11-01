import org.apache.jena.rdf.model.*;
import org.apache.jena.vocabulary.RDFS;

public class RDFExample {
    public static void main(String[] args) {
        String hifmDataNS = "http://purl.org/net/hifm/data#";
        String drugbankNS = "http://purl.org/net/hifm/drugbank";
        String hifmOntNS = "http://purl.org/net/hifm/hifm-ont#";

        Model model = ModelFactory.createDefaultModel();

        model.read("C:\\Users\\User\\FINKI\\JenaRDFgraph\\src\\hifm-dataset.ttl", "TTL");

        Resource selectedDrug = model.createResource(hifmDataNS + "988332");

        System.out.println("Selected Drug: " + selectedDrug.getURI());

        if (selectedDrug.hasProperty(model.createProperty(hifmOntNS + "refPriceWithVAT"))) {
            String priceWithVAT = selectedDrug.getProperty(model.createProperty(hifmOntNS + "refPriceWithVAT")).getObject().toString();
            System.out.println("Price with VAT: " + priceWithVAT);
        } else {
            System.out.println("Price with VAT not found for the selected drug.");
        }

        System.out.println("\nSimilar Drugs and Their Prices:");
        StmtIterator iter = model.listStatements(selectedDrug, model.createProperty(hifmOntNS + "similarTo"), (RDFNode) null);

        while (iter.hasNext()) {
            Statement stmt = iter.nextStatement();
            Resource similarDrug = stmt.getObject().asResource();
            
            String similarDrugName = similarDrug.getProperty(RDFS.label).getObject().toString();
            String similarDrugPrice = "Price not available";

            if (similarDrug.hasProperty(model.createProperty(hifmOntNS + "refPriceWithVAT"))) {
                similarDrugPrice = similarDrug.getProperty(model.createProperty(hifmOntNS + "refPriceWithVAT")).getObject().toString();
            }

            System.out.println("Drug Name: " + similarDrugName + ", Price with VAT: " + similarDrugPrice);
        }
    }
}
