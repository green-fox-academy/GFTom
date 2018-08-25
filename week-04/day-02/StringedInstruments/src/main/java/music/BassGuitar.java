package main.java.music;

public class BassGuitar extends  StingedInstrument {

    public BassGuitar() {
        setNameOfInstrument("BassGuiter");
        setNumberOfStrings(4);
        setSoundOfInstrument("Duum-duum-duum");
    }

    public BassGuitar(int numberOfStrings) {
        setNameOfInstrument("BassGuiter");
        setNumberOfStrings(numberOfStrings);
        setSoundOfInstrument("Duum-duum-duum");
    }
}
