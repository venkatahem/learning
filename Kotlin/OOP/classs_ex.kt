fun main()
{
    var sam20 = Mobile("Samsung","S20 Ultra","Android 12")
    var asus = Mobile("Asus","Zenfone 7","ANdroid 11")
    var iphone = Mobile("Apple","iPhone 13","iOS 15")
}

class Mobile(brand: String, model: String,osType: String)
{
    init
    {
        println("Mobile brand is $brand with model name: $model is running on $osType")
    }
}