public class UrlFixer {
  public static void main(String... args){
    String url = "https//www.reddit.com/r/nevertellmethebots";
    url = (String) url.replace("bots","odds" );
    String insert = ":";
    StringBuilder str = new StringBuilder(url);
    str.insert(5, insert);
    url = str.toString();
    // Accidentally I got the wrong URL for a funny subreddit. It's probably "odds" and not "bots"
    // Also, the URL is missing a crutial component, find out what it is and insert it too!
    // Try to solve it more than once using different String functions!

    System.out.println(url);
  }
  //public class simplereplace {
    //public static void main(String... args){
      //String example = "In a dishwasher far far away";
      //example = example.replace("dishwasher", "galaxy");
      // I would like to replace "dishwasher" with "galaxy" in this example, but it has a problem.
      // Please fix it for me!
      // Expected ouput: In a galaxy far far away

      //System.out.println(example);
    //}
  //}
}
