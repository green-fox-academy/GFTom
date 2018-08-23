import org.testng.annotations.Test;

import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.Assert.*;

public class SumTest {

    private Sum a;

    @Test
    public void sumMultipleElements() {
        a = new Sum();
        assertEquals(15, a.sumElements(Arrays.asList(1,2,3,4,5)));
    }

    @Test
    public void sumSingleElement() {
        a = new Sum();
        assertEquals(5, a.sumElements(Arrays.asList(5)));
    }

    @Test
    public void sumEmptyList() {
        a = new Sum();
        assertEquals(0, a.sumElements(Arrays.asList()));
    }

    @Test(expectedExceptions = Exception.class)
    public void sumNullList() {
        a = new Sum();
        a.sumElements(null);

    }
}

