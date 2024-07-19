#string values
sports <- c("cricket","football","badminton")
print("string vector")
print(sports)
#numbers
a <- 1:10
print("number vector")
print(a)
#length
print("vector length - sports")
print(length(sports))
#indexing
print("indexing of vectors")
print(sports[3])
#multi indexing
print("multi indexing of vectors")
print(a[c(1,4,6)])
#remove first ele
print("removing elements")
a <- a[! a%in% c(1)]
print(a)
a <- a[! a%in% c(1,4,6)]
print(a)
print("assigning values to specific location")
a[5]<-10
print(a)