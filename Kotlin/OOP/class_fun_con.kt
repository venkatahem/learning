fun main()
{
    var me = Person("Siva","Kumar",12)
    me.hobby = "playing cricket"
    me.age = 34
    me.statehobby()
    //println("Age is ${me.age}")
}

class Person(firstName: String,lastName: String)
{
    var age: Int? = null
    var hobby: String = "Not defined"
    var firstName = firstName
    
    init
    {
        println("\nCreated a person with first name: ${firstName} ,last name: $lastName")
    }

    constructor(firstName: String,lastName: String,age: Int):this(firstName,lastName)
    {
        this.age = age
    }

    fun statehobby()
    {
        println("${firstName}'s hobby is $hobby and age is $age\n");
    }
}