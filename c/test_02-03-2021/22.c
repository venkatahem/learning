#include<stdio.h>
#include<string.h>
struct library
{
    int id;
    char book[30];
    char author[30];
    int price;
    char place[30];
struct dt
{
    int day:5;
    int month;
    int year;
}date;
  struct library *next;
}*ptr,*root;
void search(int id)
{
  ptr=root;
  int flag=0;
while(ptr->next!=NULL&&flag==0)
{
  if(id==ptr->id)
  flag=1;
  else
  ptr=ptr->next;
}
  if(flag==1)
  printf("Search succesful\n");
  else
  printf("Search unsuccesful\n");
}
int main(void)
{
  int i,n,temp,id;
  printf("Enter the number of books: ");
  scanf("%d",&n);
  struct library book[n];
  root=&book[0];
  ptr=root;
  printf("Enter the details:\n");
  
  for(i=0;i<n;i++)
 {
  printf("For book %d:\n",i+1);
  printf("Book id: ");
  scanf("%d%*c",&ptr->id);
  printf("Book name: ");

  fgets(ptr->book,sizeof(ptr->book),stdin);

  printf("Author name: ");
  fgets(ptr->author,sizeof(book[i].author),stdin);
  printf("Price: ");
  scanf("%d%*c",&ptr->price);
      
  printf("Day of purchase: ");
  scanf("%d",&temp);
  ptr->date.day=temp;
  printf("Month of purchase: ");
  scanf("%d",&ptr->date.month);
  printf("Year of purchase: ");
  scanf("%d",&ptr->date.year);
  
  if(i<n-1)
  ptr->next=&book[i+1];
  else
  ptr->next=NULL;

  ptr=ptr->next;
}
  printf("Enter the book id to search for: ");
  scanf("%d",&id);
search(id);
return 0;
}