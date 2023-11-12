package lab1;

public class EncryptedFrame {
    private String frameHeader;
    private Integer pn;
    private byte[] data;
    private byte[] mic;

    public EncryptedFrame(String frameHeader, Integer pn, byte[] data, byte[] mic) {
        this.frameHeader = frameHeader;
        this.pn = pn;
        this.data = data;
        this.mic = mic;
    }

    public String getFrameHeader() {
        return frameHeader;
    }

    public void setFrameHeader(String frameHeader) {
        this.frameHeader = frameHeader;
    }

    public Integer getPn() {
        return pn;
    }

    public void setPn(Integer pn) {
        this.pn = pn;
    }

    public byte[] getData() {
        return data;
    }

    public void setData(byte[] data) {
        this.data = data;
    }

    public byte[] getMic() {
        return mic;
    }

    public void setMic(byte[] mic) {
        this.mic = mic;
    }

    @Override
    public String toString() {
        StringBuilder es = new StringBuilder();
        for (byte b : data) {
            es.append(String.format("%02X ", b));
        }
        StringBuilder sb = new StringBuilder();
        for (byte b : mic) {
            sb.append(String.format("%02X ", b));
        }
        return "EncryptedFrame = frameHeader: " + frameHeader + ", pn: " + pn + ", data: " + es + ", mic: " + sb;
    }
}
