#include <iostream>
#include <vector>

class IAnimal {
public:
    virtual ~IAnimal() = default;

    virtual void makeNoise() const = 0;
    virtual const char *getName() const = 0;
    virtual int getAge() const = 0;
    virtual int getLegCount() const = 0;

protected:
    IAnimal() = default;
};

class Pig final : public IAnimal {
public:
    Pig(const char *name, int age) 
        : IAnimal()
        , m_Name(name)
        , m_Age(age)
    {}

    virtual ~Pig() = default;

    virtual void 
    makeNoise() const override {
        std::cout << "Oink!";
    }

    virtual const char *getName() const override { return m_Name; }
    virtual int getAge() const override { return m_Age; }
    virtual int getLegCount() const override { return 4; }

private:
    const char *m_Name;
    int m_Age;
};

class Chicken final : public IAnimal {
public:
    Chicken(const char *name, int age) 
        : IAnimal()
        , m_Name(name)
        , m_Age(age)
    {}

    virtual ~Chicken() = default;

    virtual void 
    makeNoise() const override {
        std::cout << "Oink!";
    }

    virtual const char *getName() const override { return m_Name; }
    virtual int getAge() const override { return m_Age; }
    virtual int getLegCount() const override { return 4; }

private:
    const char *m_Name;
    int m_Age;
};

class Farm {
public:
    Farm() = default;
    ~Farm() = default;

    void addAnimal(IAnimal *animal) {
        m_Animals.push_back(animal);
    }

    void surveyFarm() {
        std::cout << "Animals:\n";
        for (const auto &animal : m_Animals) {
            std::cout << "\t" << animal->getName() << ", age: " << animal->getAge() << "\n";
        }
    }

private:
    std::vector<IAnimal*> m_Animals;
};


int 
main() {
    Pig *cesar = new Pig("Cesar", 45);
    Chicken *cluck = new Chicken("Mother-clucker", 7);

    Farm farm{};

    farm.addAnimal(cesar);
    farm.addAnimal(cluck);

    farm.surveyFarm();

    return 0;
}