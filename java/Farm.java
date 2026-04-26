import java.util.ArrayList;

public class Farm {
    private ArrayList<Animal> animals;

    public Farm() {
        animals = new ArrayList<Animal>();
    }

    public void addAnimal(Animal animal) {
        animals.add(animal);
    }

    public void surveyFarm() {
        System.out.println("Animals:");
        for (Animal animal : animals) {
            System.out.println("\t" + animal.getName() + ", age: " + animal.getAge());
        }
    }
}