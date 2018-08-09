import javax.swing.*;

import java.awt.*;
import java.util.Random;

import static javax.swing.JFrame.EXIT_ON_CLOSE;

public class Drawing {


  public static void oneRectDraw(Graphics graphics, int x, int y){
    int width = 40;
    int height = 40;
    Random rand = new Random();
    //int rgb = Color.HSBtoRGB((float)hue,(float)0.5,(float)0.5);
    //Color color = new Color(rgb);
    int red = rand.nextInt(255);
    int green = rand.nextInt(240);
    graphics.setColor(new Color(red, green, 0));
    //graphics.setColor(Color.GREEN);
    graphics.drawRect(x, y, width, height);
  }

  public static void mainDraw(Graphics graphics){
    // draw four different size and color rectangles.
    // avoid code duplication.
    Random rand = new Random();
    int x = rand.nextInt(50) + 1;
    int y = rand.nextInt(50) + 1;
    for (int i = 0; i < 3; i++) {
      oneRectDraw(graphics, x + (i * 5), y + (i * 5));
    }
  }

  //    Don't touch the code below
  static int WIDTH = 320;
  static int HEIGHT = 343;
  public static void main(String[] args) {
    JFrame jFrame = new JFrame("Drawing");
    jFrame.setSize(new Dimension(WIDTH, HEIGHT));
    jFrame.setDefaultCloseOperation(EXIT_ON_CLOSE);
    jFrame.add(new ImagePanel());
    jFrame.setLocationRelativeTo(null);
    jFrame.setVisible(true);
  }
  static class ImagePanel extends JPanel{
    @Override
    protected void paintComponent(Graphics graphics) {
      super.paintComponent(graphics);
      mainDraw(graphics);

    }
  }

}