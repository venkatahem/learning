stu_list <- list(c("A","B","C"),c(3001,3002,3003),c("web_dev","app_dev","ML"))

print(stu_list)

names(stu_list) <- c("stu_names","stu_id","proj_domain")
print("project domain")

print(stu_list$proj_domain)