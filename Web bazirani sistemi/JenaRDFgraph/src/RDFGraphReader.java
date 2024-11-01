import org.apache.jena.rdf.model.*;
import org.apache.jena.vocabulary.VCARD;

import java.io.FileInputStream;
import java.io.IOException;

public class RDFGraphReader {

    public static void main(String[] args) {
        Model model = ModelFactory.createDefaultModel();
        String filePath = "C:\\Users\\User\\FINKI\\JenaRDFgraph\\src\\outputfile1.ttl";

        try (FileInputStream inputStream = new FileInputStream(filePath)) {
            model.read(inputStream, null, "TURTLE");
            System.out.println("RDF graph loaded successfully from " + filePath);
        } catch (IOException e) {
            System.err.println("Error reading the RDF file: " + e.getMessage());
        }

        String myResourceURI = "https://www.facebook.com/davitkov.lj/";

        Resource myResource = model.getResource(myResourceURI);
        if (myResource != null) {
            System.out.println("Resource found: " + myResource);


            Property fullNameProperty = VCARD.FN;
            if (myResource.hasProperty(fullNameProperty)) {
                Literal fullName = myResource.getProperty(fullNameProperty).getLiteral();
                System.out.println("Full Name: " + fullName.getString());
            }

            Property firstNameProperty = VCARD.Given;
            Property lastNameProperty = VCARD.Family;

            if (myResource.hasProperty(firstNameProperty)) {
                Literal firstName = myResource.getProperty(firstNameProperty).getLiteral();
                System.out.println("First Name: " + firstName.getString());
            }
            if (myResource.hasProperty(lastNameProperty)) {
                Literal lastName = myResource.getProperty(lastNameProperty).getLiteral();
                System.out.println("Last Name: " + lastName.getString());
            }

            Property friendProperty = VCARD.FN;
            if (myResource.hasProperty(friendProperty)) {
                Resource friendResource = myResource.getProperty(friendProperty).getResource();
                System.out.println("Friend's URI: " + friendResource.getURI());
            }

        } else {
            System.out.println("Resource not found with URI: " + myResourceURI);
        }
    }
}
