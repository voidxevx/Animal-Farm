public class Pig implements Animal {
    private String name;
    private int age;

    public Pig(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void makeNoise() {
        System.out.print("Oink!");
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public int getLegCount() {
        return 4;
    }
}