-  `static` keyword can be applied to variables, methods , blocks and nested classes

-  anything with `static` keyword becomes a part of class instead of object/instance

-  can be used when we want anything to be shared, - count of students 

-  static method can not use non-static data member or call non-static method directly, because these are part of object, not the class.

-  this and super cannot be used in static context.
    -  this is associated with the object
    -  super is associated with the parent object
    -  while static members are a part of class

-  static blocks are used to setup static members or one time setup for any class 
    -  example - database manager class setting up the connection

-  static methods
    -  for frequently utilized methods as a Utils class

-  instances 
    -  if a single instance of the class needs to be shared
    -  make the constructor private and make the class instance static and share it via any static method