public class Chicken implements Animal {
    private String name;
    private int age;

    public Chicken(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void makeNoise() {
        System.out.print("Cluck!");
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public int getLegCount() {
        return 2;
    }
}