public class Main {
    public static void main(String[] args) {
        Pig cesar = new Pig("Cesar", 45);
        Chicken cluck = new Chicken("Mother-clucker", 2);

        Farm farm = new Farm();

        farm.addAnimal(cesar);
        farm.addAnimal(cluck);

        farm.surveyFarm();
    }
}