#while
i<-1
print("while loop")
while(i<6){
    print(i)
    i<-i+1
}

#for
print("for loop")
for(i in 1:5){
    print(i)
}

#repeat
i<-1
print("repeat")
repeat{
    print(i)
    i<-i+1
    if(i>5){
        break
    }
}
