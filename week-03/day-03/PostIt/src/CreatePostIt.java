import java.awt.*;

 class CreatePostIt {
 public static void main(String[] args) {
    PostIt postIt1 = new PostIt(Color.orange, "Idea 1", Color.blue);
    PostIt postIt2 = new PostIt(Color.pink, "Awesome", Color.black);
    PostIt postIt3 = new PostIt(Color.yellow, "Superb", Color.green);

    System.out.println(postIt1);
    System.out.println(postIt2);
    System.out.println(postIt3);
  }
}
