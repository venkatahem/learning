any collection can be converted to a stream , and we can use declarative and functional programming on streams 

Advantages
Readability
Flexibility -> Multiple operations can be applied on same stream 
Parallelism -> Multiple processors / threads can act on the streams to perform operations on parallel 

Methods on a stream 

filter(predicate)
map(function lambda)
sorted(comparator)
distinct()
limit()
skip()
peek()
max(comparator)
get()
collect(collection type)

parallelStream()