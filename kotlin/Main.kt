interface Animal {
    val legCount: Int

    fun makeNoise()
    fun getName(): String
    fun getAge(): Int
}

class Pig(val m_name: String, val m_age: Int) : Animal {
    override val legCount: Int = 4

    override fun makeNoise() {
        print("Oink!")
    }

    override fun getName(): String {
        return m_name
    }

    override fun getAge(): Int {
        return m_age
    }

}

fun main() {
    val cesar = Pig("Cesar", 45)
}