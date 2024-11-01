//import org.apache.jena.rdf.model.Model;
//import org.apache.jena.rdf.model.ModelFactory;
//import org.apache.jena.rdf.model.Resource;
//import org.apache.jena.rdf.model.Property;
//
//import org.apache.jena.rdf.model.StmtIterator;
//import org.apache.jena.rdf.model.Statement;
//
//public class Main {
//    public static void main(String[] args) {
//
//        Model model = ModelFactory.createDefaultModel();
//
//        String myURI = "https://www.facebook.com/davitkov.lj";
//
//        Resource me = model.createResource(myURI);
//
//        // Define the vCard namespace
//        String vCardNamespace = "http://www.w3.org/2006/vcard/ns#";
//        Property fullNameProperty = model.createProperty(vCardNamespace, "fn");
//        Property emailProperty = model.createProperty(vCardNamespace, "email");
//        Property telProperty = model.createProperty(vCardNamespace, "tel");
//        Property adrProperty = model.createProperty(vCardNamespace, "adr");
//
//        // Define the FOAF namespace
//        String foafNamespace = "http://xmlns.com/foaf/0.1/";
//        Property foafNameProperty = model.createProperty(foafNamespace, "name");
//        Property foafMboxProperty = model.createProperty(foafNamespace, "mbox");
//        Property foafHomepageProperty = model.createProperty(foafNamespace, "homepage");
//        Property foafKnowsProperty = model.createProperty(foafNamespace, "knows");
//        Property foafDepictionProperty = model.createProperty(foafNamespace, "depiction");
//
//        // Add properties to the resource
//        String fullName = "Ljubomir Davitkov";
//        String email = "ljubo.davitkov@gmail.com";
//        String phoneNumber = "+123456789";
//        String address = "Bozidar Adzija number 12, Skopje";
//        String friendURI = "https://www.facebook.com/janev.gj";
//        String homepage = "https://www.facebook.com/davitkov.lj";
//        String depiction = "https://www.facebook.com/photo/?fbid=6584912014865717&set=a.154585761231740";
//
//        // Adding properties
//        me.addProperty(fullNameProperty, fullName);
//        me.addProperty(emailProperty, email);
//        me.addProperty(telProperty, phoneNumber);
//        me.addProperty(adrProperty, address);
//        me.addProperty(foafNameProperty, fullName);
//        me.addProperty(foafMboxProperty, email);
//        me.addProperty(foafHomepageProperty, homepage);
//        me.addProperty(foafKnowsProperty, model.createResource(friendURI));
//        me.addProperty(foafDepictionProperty, depiction);
//
//        System.out.println("Printing with model.listStatements():");
//        StmtIterator iterator = model.listStatements();
//
//        // Iterate over the statements and print them
//        while (iterator.hasNext()) {
//            Statement stmt = iterator.nextStatement();
//            String subject = stmt.getSubject().toString();
//            String predicate = stmt.getPredicate().toString();
//            String object = stmt.getObject().isLiteral()
//                    ? "\"" + stmt.getObject().toString() + "\""
//                    : stmt.getObject().toString();
//
//            System.out.println(subject + " – " + predicate + " – " + object);
//        }
//    }
//}

import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.rdf.model.Resource;
import org.apache.jena.rdf.model.StmtIterator;
import org.apache.jena.rdf.model.Statement;


public class Main {
    public static void main(String[] args) {

        Model model = ModelFactory.createDefaultModel();

        String myURI = "https://www.facebook.com/davitkov.lj";

        Resource me = model.createResource(myURI);

        System.out.println("Printing with model.listStatements():");
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

        System.out.println("Printing with model.write() in RDF/XML:");
        model.write(System.out, "RDF/XML");

        System.out.println("\nPrinting with model.write() in Pretty RDF/XML:");
        model.write(System.out, "RDF/XML-ABBREV");

        System.out.println("\nPrinting with model.write() in N-Triples:");
        model.write(System.out, "N-TRIPLES");

        System.out.println("\nPrinting with model.write() in Turtle:");
        model.write(System.out, "TURTLE");
    }
}

