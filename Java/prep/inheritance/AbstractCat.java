package inheritance;

import abstraction.Animal;

public abstract class AbstractCat extends Animal {

    public AbstractCat(String name) {
        super(name);
    }

    @Override
    public void hello() {
    }

    /*
     * this can not be implemented since it is package protected, so make the class
     * abstract ,but this class is not of any use , so default access modifier of
     * this method needs to be changed or the Animal class can be inherited in the
     * abstraction package
     */
    // @Override
    // void bye() {
    // }

}
