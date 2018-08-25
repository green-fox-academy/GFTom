package main.java.music;

public class ElectricGuitar extends StingedInstrument {

    public ElectricGuitar() {
        setNameOfInstrument("ElectricGuitar");
        setNumberOfStrings(6);
        setSoundOfInstrument("Twang");
    }

    public ElectricGuitar(int numberOfStrings) {
        setNameOfInstrument("ElectricGuitar");
        setNumberOfStrings(numberOfStrings);
        setSoundOfInstrument("Twang");
    }
}
