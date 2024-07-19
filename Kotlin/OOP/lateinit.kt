fun main()
{
    var me = Exp()
    println("${me.name}")
}

class Exp()
{
    lateinit var name: String  // Late initialization, should not use var name befor initialization

    init
    {
        this.name = "Default"
    }
}