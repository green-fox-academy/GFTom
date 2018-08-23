import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class ApplesTest {

    private Apples a;

    @Before
    public void createApples() {
        a = new Apples("Starking");
    }

    @Test
    public void getApple() {
        a.getApple();
        assertEquals("Starking", a.getApple());
    }
}