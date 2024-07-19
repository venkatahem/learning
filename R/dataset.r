batch1 <- data.frame(
    reg_no = c(3001,3002,3003,3004,3005),
    stu_name = c("a","b","c","d","e"),
    cgpa = c(9.1,9.3,9.2,9.2,9.5)
)

# batch1
print("batch1")
print(batch1)

grades <- c("a","a+","a","a","o")

batch1 <- cbind(batch1,grades)

print("Adding grades column")
print(batch1)

print("batch2")


batch2 <- data.frame(
    reg_no = c(3501,3502,3503,3504,3505),
    stu_name = c("a","b","c","d","e"),
    cgpa = c(9.1,9.3,5.2,9.2,9.5)
)

#batch2

print(batch2)
grades <- c("a","a+","a","a","o")
batch2 <- cbind(batch2,grades)
print(batch2)

batch_info <- rbind(batch1,batch2)


batch_info

batch_info$class <- as.factor(ifelse(batch_info$cgpa>=6.0,"pass"
,"fail"))

print("Combining two batches")

print(batch_info)