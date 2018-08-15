import java.awt.*;

public class PostIt {

    String backGroundColor;
    String textPostIt;
    String textColor;

    public PostIt(String backGroundColor, String textPostIt, String textColor) {
        this.backGroundColor = backGroundColor;
        this.textPostIt = textPostIt;
        this.textColor = textColor;
    }

    @Override
    public String toString() {
    return "an "+ backGroundColor + " with " + textColor + " text: " + textPostIt;
    }
}

