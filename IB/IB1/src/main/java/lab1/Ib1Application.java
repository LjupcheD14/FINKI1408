package lab1;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class Ib1Application {

    public static void main(String[] args){
        final String secretKey = "thesecretkeyisbignowbecauseofbig";

        String originalString = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed sem est, gravida ut ipsum eu, ultricies faucibus orci. Donec id miu";
        final ClearTextFrame clearTextFrame = new ClearTextFrame("thisheaderframeishereforthepurposesofthetestingofthisexerciseaaa", 2, originalString);

        EncryptedFrame encryptedFrame = AES.encrypt(clearTextFrame, secretKey);
        ClearTextFrame decryptedFrame = AES.decrypt(encryptedFrame, secretKey);

        System.out.println("Original data: " + originalString);
        System.out.println(clearTextFrame);
        System.out.println(encryptedFrame);
        System.out.println(decryptedFrame);
    }
}
