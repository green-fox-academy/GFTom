import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

import static org.junit.Assert.*;

public class TrickyAverageTest {
    static TrickyAverage trickyAverage;

    @BeforeClass
    public static void init (){
        trickyAverage = new TrickyAverage();
    }

    @Test
    public void testSimpleTrickyAverage(){
        int[] array = {1,3,4,7};
        double expectedAverage = 2.5;
         double resultTrickyAverage = trickyAverage.getTrickyAvg(array);
        assertEquals(expectedAverage, resultTrickyAverage, 0.0001);
    }
    @Test
    public void test2SimpleTrickyAverage(){
        int[] array = {};
        double expectedAverage = 0;
        double resultTrickyAverage = trickyAverage.getTrickyAvg(array);
        assertEquals(expectedAverage, resultTrickyAverage, 0.0001);
    }

    @Test
    public void test3SimpleTrickyAverage(){
        int[] array = {6};
        double expectedAverage = 3;
        double resultTrickyAverage = trickyAverage.getTrickyAvg(array);
        assertEquals(expectedAverage, resultTrickyAverage, 0.0001);
    }
}

