fun main()
{
    var ex = Car()
    println("${ex.myCar}")
    println("${ex.speed}")
    ex.speed = 123
    println("${ex.speed}")
    ex.speed = 165
    println("${ex.speed}")
}

class Car()
{
    var myCar: String = "Audi"

    get()
    {
        return field.lowercase()
    }

    var speed: Int? = null
    // set(value)
    // {
    //     if(value>149)
    //         field = value
    // }
    get()
    {
        return field
    }
}