emp_data <- list(c(1,2,3),c("a","b","c"),c("Manager","Team_Lead","Worker"),c(1000,2000,1500),c("Chennai","Banglore","Chennai"))

names(emp_data) <- c("emp_id","emp_name","emp_desig","emp_sal","emp_loc")

print(emp_data)

# emp_data

emp_data <- lapply(emp_data,function(x) replace(x,x=="Manager","CEO"))

print("changing manger to ceo")
print(emp_data)

append(emp_data,c("web","app","ml"),after=3)

print("appending projects")
print(emp_data)

emp_data[["emp_loc"]] = NULL
print("removing employee work location")
print(emp_data)