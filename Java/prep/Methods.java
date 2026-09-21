public class Methods {

    // accessModifier returnType methodName(parameterType parameterName) {
    // // method body
    // return returnValue;
    // }

    public static void main(String[] args) {
        System.out.println("hi");
    }

    public int add(int a, int b) {
        return a + b;
    }

    // method overloading
    public int add(int a, int b, int c) {
        return a + b + c;
    }

    // method signature - only method name and parameter list
    // signature doesn't include method return type and access modifier

    public void test() {
        String str1 = "test";

        String.valueOf(0);
    }
    /* Params */
    // for parameters if the parameters are of primitive types then a deep copy of
    // these values are passed ,
    // for an object the reference is passed , any changes performed on the object
    // in the method will affect the object in the calling method

    /* Variable args */

    public int varArgs(int... list) {
        int x = 0;
        for (int a : list) {
            x = x + a;
        }
        return x;
    }

}
