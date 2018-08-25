package main.java.music;

public abstract class StingedInstrument extends Instrument{

    protected int numberOfStrings;
    protected String soundOfInstrument;

    public String getSoundOfInstrument() {
        return soundOfInstrument;
    }

    public void setSoundOfInstrument(String soundOfInstrument) {
        this.soundOfInstrument = soundOfInstrument;
    }

    public int getNumberOfStrings() {
        return numberOfStrings;
    }

    public void setNumberOfStrings(int numberOfStrings) {
        this.numberOfStrings = numberOfStrings;
    }

    @Override
    public void play() {
        System.out.println(getNameOfInstrument() + ", a "+ getNumberOfStrings() + "-stringed instrument that goes "+ sound());
    }

    public String sound(){
        return getSoundOfInstrument();
    }
}
