package lab1;

public class ClearTextFrame {
    private String frameHeader;
    private Integer pn;
    private String data;

    public ClearTextFrame(String frameHeader, Integer pn, String data) {
        this.frameHeader = frameHeader;
        this.pn = pn;
        this.data = data;
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

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return "ClearTextFrame = frameHeader: " + frameHeader + ", pn: " + pn + ", data: " + data;
    }
}
