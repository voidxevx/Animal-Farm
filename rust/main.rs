#[allow(unused)]
trait Animal {
    fn make_noise(&self);
    fn get_name(&self) -> &str;
    fn get_age(&self) -> i32;
    fn get_leg_count(&self) -> i32;
}

#[allow(unused)]
struct Pig {
    name: &'static str,
    age: i32,
}

impl Pig {
    fn new(name: &'static str, age: i32) -> Box<Self> {
        Box::new(Self {
            name,
            age,
        })
    }
}

impl Animal for Pig {
    fn make_noise(&self) {
        print!("Oink!");
    }

    fn get_name(&self) -> &str {
        self.name
    }

    fn get_age(&self) -> i32 {
        self.age
    }

    fn get_leg_count(&self) -> i32 {
        4
    }
}

#[allow(unused)]
struct Chicken {
    name: &'static str,
    age: i32,
}

impl Chicken {
    fn new(name: &'static str, age: i32) -> Box<Self> {
        Box::new(Self {
            name,
            age,
        })
    }
}

impl Animal for Chicken {
    fn make_noise(&self) {
        print!("Cluck!");
    }

    fn get_name(&self) -> &str {
        self.name
    }

    fn get_age(&self) -> i32 {
        self.age
    }

    fn get_leg_count(&self) -> i32 {
        2
    }
}

#[derive(Default)]
struct Farm {
    animals: Vec<Box<dyn Animal>>
}

impl Farm {
    fn add_animal(&mut self, animal: Box<dyn Animal>) {
        self.animals.push(animal);
    }

    fn survey_farm(&self) {
        println!("Animals:");
        for animal in &self.animals {
            println!("\t{}, age: {}", animal.get_name(), animal.get_age());
        }
    }
}

fn main() {
    let cesar = Pig::new("Cesar", 45);
    let cluck = Chicken::new("Mother-clucker", 9);

    let mut farm = Farm::default();
    farm.add_animal(cesar);
    farm.add_animal(cluck);

    farm.survey_farm();
}