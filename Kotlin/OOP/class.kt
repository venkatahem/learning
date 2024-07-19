fun main()
{
    var me = Person("Venki","Hem")
    var new = Person()
    var new1 = Person(lastName = "Hemanth")
}

// class Person // Valid class but without any properties

class Person (firstName: String = "Venkata", lastName: String = "Hem")
{
    init
    {
        println("Initailised a person with firstname = $firstName and lastname = $lastName")
    }
}