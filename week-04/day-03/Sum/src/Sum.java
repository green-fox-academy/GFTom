import java.util.ArrayList;
import java.util.List;

public class Sum {

    //List<Integer> list;

    //public Sum(List<Integer> list) {
        //this.list = list;
   // }

    public int sumElements(List<Integer> list){
        int tempSumElements =0;
        for (int i = 0; i < list.size(); i++) {
            tempSumElements = tempSumElements + list.get(i);
        } return tempSumElements;
    }
}
