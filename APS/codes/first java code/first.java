//base class

class Bicycle {
    public int gear;
    public int speed;

    // the class has one constructor

    public Bicycle(int gear, int speed) {
        this.gear = gear;
        this.speed = speed;
    }
//
//    public void applyBrake(int decrement) {
//        speed -= decrement;
//    }

    public void applyBrake(int decrement) {
        speed -= decrement;
    }

    public void speedUp(int increment) {
        speed += increment;
    }

    // toString() method to print info of Bicycle

    public String toString() {
        return ("No of gears are " + gear + "\n" + "speed of bicycle is " + speed);
    }
}

// derived class

class MountainBike extends Bicycle {
    public int seatHeight;

    // the MountainBike subclass has one constructor

    public MountainBike(int gear, int speed, int startHeight){
        // invoking base-class(Bicycle) constructor
        super(gear, speed);
        seatHeight = startHeight;
    }

    public void setHeight(int newValue){
        seatHeight = newValue;
    }

    //overriding toString() method of Bicycle to print more info

    @Override
    public String toString(){
        return (super.toString() + "\nseat height is " +seatHeight);
    }

}

public class Main {

    public static void main(String args[]){
        Bicycle b = new Bicycle(1, 60);
        System.out.println(b.toString());
        MountainBike mb = new MountainBike(3,100,25);
        System.out.println(mb.toString());
    }

}
