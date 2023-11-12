package lab1;

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;

import static java.nio.charset.StandardCharsets.UTF_8;

class AES {

    private static final String CipherMode = "AES/ECB/NoPadding";

    public static EncryptedFrame encrypt(ClearTextFrame clearTextFrame, String password) {
        try {
            var content = clearTextFrame.getData().getBytes(UTF_8);
            SecretKeySpec key = createKey(password);
            Cipher cipher = Cipher.getInstance(CipherMode);
            cipher.init(Cipher.ENCRYPT_MODE, key);
            var mic = getMic(key, clearTextFrame);
            return new EncryptedFrame(clearTextFrame.getFrameHeader(), clearTextFrame.getPn(), cipher.doFinal(content), mic);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    public static ClearTextFrame decrypt(EncryptedFrame encryptedFrame, String password) {
        try {
            var content = encryptedFrame.getData();
            SecretKeySpec key = createKey(password);
            Cipher cipher = Cipher.getInstance(CipherMode);
            cipher.init(Cipher.DECRYPT_MODE, key);
            return new ClearTextFrame(encryptedFrame.getFrameHeader(), encryptedFrame.getPn(), new String(cipher.doFinal(content)));
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    public static SecretKeySpec createKey(String password) {
        byte[] data;
        if (password == null) {
            password = "";
        }
        StringBuilder sb = new StringBuilder(32);
        sb.append(password);
        while (sb.length() < 32) {
            sb.append("0");
        }
        if (sb.length() > 32) {
            sb.setLength(32);
        }
        data = sb.toString().getBytes(UTF_8);
        return new SecretKeySpec(data, "AES");
    }

    public static byte[] calculateUntilTimeFrame(SecretKeySpec secretKey, String headerFrame) throws NoSuchAlgorithmException {
        byte[] headerFrameInBytes = headerFrame.getBytes(UTF_8);
        var firstHalfHeaderFrame = Arrays.copyOfRange(headerFrameInBytes, 0, headerFrameInBytes.length / 2);
        var secondHalfHeaderFrame = Arrays.copyOfRange(headerFrameInBytes, headerFrameInBytes.length / 2,
                headerFrameInBytes.length);

        var firstHalfToCalculate = Arrays.copyOfRange(firstHalfHeaderFrame, firstHalfHeaderFrame.length / 4,
                firstHalfHeaderFrame.length);
        var secondHalfToCalculate = Arrays.copyOfRange(secondHalfHeaderFrame, secondHalfHeaderFrame.length / 4,
                secondHalfHeaderFrame.length);

        var lengthOfArray = Math.max(secretKey.getEncoded().length, firstHalfToCalculate.length);

        byte[] firstFinal = new byte[lengthOfArray];

        var firstHalfToCalculateAsString = new StringBuilder(new String(firstHalfToCalculate));
        int length = firstHalfToCalculate.length;
        while (length < lengthOfArray) {
            firstHalfToCalculateAsString.append("0");
            length++;
        }
        firstHalfToCalculate = firstHalfToCalculateAsString.toString().getBytes(UTF_8);

        int i = 0;
        for (byte b : secretKey.getEncoded()) {
            firstFinal[i] = (byte) (b ^ firstHalfToCalculate[i]);
            i++;
        }

        lengthOfArray = Math.max(firstFinal.length, secondHalfToCalculate.length);
        byte[] secondFinal = new byte[lengthOfArray];

        var secondHalfToCalculateAsString = new StringBuilder(new String(secondHalfToCalculate));
        length = secondHalfToCalculate.length;
        while (length < lengthOfArray) {
            secondHalfToCalculateAsString.append("0");
            length++;
        }
        secondHalfToCalculate = secondHalfToCalculateAsString.toString().getBytes(UTF_8);
        i = 0;
        for (byte b : firstFinal) {
            secondFinal[i] = (byte) (b ^ secondHalfToCalculate[i]);
            i++;
        }

        return secondFinal;
    }

    public static byte[] getMic(SecretKeySpec spec, ClearTextFrame clearTextFrame) throws NoSuchAlgorithmException {
        var currentMic = calculateUntilTimeFrame(spec, clearTextFrame.getFrameHeader());

        var data = clearTextFrame.getData().getBytes(UTF_8);
        var str = new String(data);
        int len = str.length();
        int n = data.length / 32;
        int temp = 0, chars = len / n;
        String[] splitData = new String[n];
        for (int i = 0; i < len; i = i + chars) {
            String part = str.substring(i, i + chars);
            splitData[temp] = part;
            temp++;
        }

        for (int i = 0; i < data.length / 32; i++) {
            var currentDataToEncrypt = splitData[i].getBytes(UTF_8);

            byte[] currentFinal = new byte[32];


            for (int j = 0; j < 32; j++) {
                currentFinal[j] = (byte) (currentMic[j] ^ currentDataToEncrypt[j]);
            }

            currentMic = currentFinal;
        }
        return Arrays.copyOfRange(currentMic, 0, currentMic.length / 2);
    }
}
