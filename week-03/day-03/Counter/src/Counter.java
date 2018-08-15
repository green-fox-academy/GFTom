public class Counter {

    int counterValue;
    int tempCounterValue;

    public Counter(){
        this(0);
    }

    public Counter(int counterValue){
        this.counterValue = counterValue;
        tempCounterValue = counterValue;
    }

    public void add(int number){
        counterValue = counterValue + number;
    }

    public void add(){
        counterValue++;
    }

    public int get(){
        return counterValue;
    }

    public void reset(){
        counterValue = tempCounterValue;
    }
}
