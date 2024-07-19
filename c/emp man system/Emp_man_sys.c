#include <stdio.h>
#include <string.h>
static int len;

struct employee
{
    int ID;
    int training;
    char pass[50];
    char name[30];

    struct salary
    {
        int payment;
        int deduction;
        int total;
        int duration;
        int allowance;
        int due;
        int advance;
        int loan;
    } emp_sal;

    struct events
    {
        struct time
        {
            int hrs;
            int min;
        } eve_time;

        struct date
        {
            int day;
            int mon;
            int year;
        } eve_date;

        char description[50];
    } eve;

    struct leave
    {
        char req[5];
        char permis[5];

        int tot_lev;

        struct leave_date
        {
            int day;
            int mon;
            int year;
        } leave_date;

        int remain;
    } lev;
    struct attendance
    {
        char entry[10];
        char exit[10];
    } attend;
    struct performance
    {
        char work_history[100];
        char promotion[50];
    } perfor;
};

/*----------------------------------------------------------------------------------------------------------------*/
/*--------------------------------       U S E R   D A T A   E N T R Y       -------------------------------------*/

void add_new(struct employee *e, int len)
{
    int i;
    int j;
    int x;
    for (i = 0; i < len; i++)
    {
        printf("\n---Employee - %d---\n", i + 1);
        printf("Enter name: ");
        fgets(e[i].name, 30, stdin);
        printf("\nEnter Emp ID: ");
        scanf("%d", &e[i].ID);
        getchar();
        printf("\nSet a password: ");
        fgets(e[i].pass, 50, stdin);
        printf("\nAdd employee salary details\n");
        printf("Payment: ");
        scanf("%d", &e[i].emp_sal.payment);
        printf("\nDeduction: ");
        scanf("%d", &e[i].emp_sal.deduction);
        printf("\nTotal: ");
        scanf("%d", &e[i].emp_sal.total);
        printf("\nDuration: ");
        scanf("%d", &e[i].emp_sal.duration);
        e[i].emp_sal.allowance = 0;
        e[i].emp_sal.advance = 0;
        e[i].emp_sal.due = 0;
        e[i].emp_sal.loan = 0;
        printf("\nDo you want to add events\n1 ----> Yes\n2 ---> No\nInput:");
        scanf("%d", &x);
        getchar();
        if (x == 1)
        {
            printf("\nEvent description: ");
            fgets(e[i].eve.description, 50, stdin);
            printf("\nEvent date");
            printf("\nDay: ");
            scanf("%d", &e[i].eve.eve_date.day);
            printf("\nMonth: ");
            scanf("%d", &e[i].eve.eve_date.mon);
            printf("\nYear: ");
            scanf("%d", &e[i].eve.eve_date.year);

            getchar();
        }
        else if (x == 2)
        {
            printf("Enter 'no': ");
            fgets(e[i].eve.description, 50, stdin);
            e[i].eve.eve_date.day = 0;
            e[i].eve.eve_date.mon = 0;
            e[i].eve.eve_date.year = 0;
            printf("\n** Event details not added **\n");
        }
        printf("\nAdd attendance\n");
        printf("Entry time: ");
        fgets(e[i].attend.entry, 10, stdin);
        printf("\nExit time: ");
        fgets(e[i].attend.exit, 10, stdin);
        printf("\nLeave details\n");
        printf("Total: ");
        scanf("%d", &e[i].lev.tot_lev);
        printf("\nRemaining: ");
        scanf("%d", &e[i].lev.remain);
        getchar();
        printf("\nDo you want to enter any leave request now/'no'(IF NOT TYPE 'no'): ");
        fgets(e[i].lev.req, 5, stdin);
        for (j = 0; e[i].lev.req[j] != '\0'; j++)
            ;
        if (j == 4)
        {
            printf("Date\n");
            printf("Day: ");
            scanf("%d", &e[i].lev.leave_date.day);
            printf("Month: ");
            scanf("%d", &e[i].lev.leave_date.mon);
            printf("Year: ");
            scanf("%d", &e[i].lev.leave_date.year);
        }
        printf("Enter training record(years): ");
        scanf("%d", &e[i].training);
        getchar();
        printf("\nEmployee work history(if any or no): ");
        fgets(e[i].perfor.work_history, 100, stdin);
        printf("\nPromotion(if any or no): ");
        fgets(e[i].perfor.promotion, 50, stdin);
    }
    printf("\nSuccessfully added %d employee details\n", len);
}

/*----------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------       A D M I N   P A N E L       ----------------------------------------*/

/*--------------------------------    U S E R    D A T A    M A N A G E M E N T    -------------------------------*/

void edit_user_info(struct employee *e, int j)
{
    int x;
    int y;
    int i;
    int k;
    printf("\nName: %s\n", e[j].name);
    printf("Login pass: %s\n", e[j].pass);
    printf("What do you want to do?\n");
    printf("1 --> Edit user details\n2 --> Remove user\n0 --> None\nINPUT:");
    scanf("%d", &x);
    if (x == 1)
    {
        printf("\n1 --> Edit name\n2 --> Edit pass\nINPUT: ");
        scanf("%d", &y);
        getchar();
        if (y == 1)
        {
            printf("\nEnter new/updated name: ");
            fgets(e[j].name, 30, stdin);
        }
        else if (y == 2)
        {
            printf("\nEnter new/updated pass: ");
            fgets(e[j].pass, 50, stdin);
        }
    }
    else if (x == 2)
    {
        for (i = j; i < (len - 1); i++)
        {
            for (j = (j + 1); j < len; j++)
            {
                strcpy(e[i].name, e[j].name);
                strcpy(e[i].pass, e[j].pass);
                e[i].ID = e[j].ID;
                e[i].emp_sal.payment = e[j].emp_sal.payment;
                e[i].emp_sal.deduction = e[j].emp_sal.deduction;
                e[i].emp_sal.allowance = e[j].emp_sal.allowance;
                e[i].emp_sal.duration = e[j].emp_sal.duration;
                e[i].emp_sal.due = e[j].emp_sal.due;
                e[i].emp_sal.advance = e[j].emp_sal.advance;
                e[i].emp_sal.total = e[j].emp_sal.total;
                e[i].emp_sal.loan = e[j].emp_sal.loan;
                strcpy(e[i].eve.description, e[j].eve.description);
                e[i].eve.eve_date.day = e[j].eve.eve_date.day;
                e[i].eve.eve_date.mon = e[j].eve.eve_date.mon;
                e[i].eve.eve_date.year = e[j].eve.eve_date.year;
                strcpy(e[i].attend.entry, e[j].attend.entry);
                strcpy(e[i].attend.exit, e[j].attend.exit);
                strcpy(e[i].lev.req, e[j].lev.req);
                strcpy(e[i].lev.permis, e[j].lev.permis);
                e[i].lev.tot_lev = e[j].lev.tot_lev;
                e[i].lev.remain = e[j].lev.remain;
                e[i].lev.leave_date.day = e[j].lev.leave_date.day;
                e[i].lev.leave_date.mon = e[j].lev.leave_date.mon;
                e[i].lev.leave_date.year = e[j].lev.leave_date.year;
                e[i].training = e[j].training;
                strcpy(e[i].perfor.work_history, e[j].perfor.work_history);
                strcpy(e[i].perfor.promotion, e[j].perfor.promotion);
            }
        }
        len--;
        printf("\n** USER SUCCESSFULLY REMOVED **\n");
    }
    else if (x == 0)
    {
        printf("\nNo changes made\n");
    }
}

/*--------------------------------   E V E N T S   M A N A G E M E N T   -----------------------------------------*/

void manage_events(struct employee *e, int j)
{
    int x;
    printf("\nEvent details are '''%s \n", e[j].eve.description);
    printf("Event date is %d-%d-%d\n", e[j].eve.eve_date.day, e[j].eve.eve_date.mon, e[j].eve.eve_date.year);
    printf("\nDo you want to update\n1 --> Yes\n2 --> No\nINPUT:");
    scanf("%d", &x);
    getchar();
    if (x == 1)
    {
        printf("\nEvent description: ");
        fgets(e[j].eve.description, 50, stdin);
        printf("\nEvent date");
        printf("\nDay: ");
        scanf("%d", &e[j].eve.eve_date.day);
        printf("\nMonth: ");
        scanf("%d", &e[j].eve.eve_date.mon);
        printf("\nYear: ");
        scanf("%d", &e[j].eve.eve_date.year);
    }
    if (x == 2)
    {
        printf("\nNo changes\n");
    }
}

/*-----------------------------------   P E R F O R M A N C E   M A N A G E M E N T   ----------------------------*/

void manage_performance(struct employee *e, int j)
{
    int x;
    printf("\nPresent work history is %s\n", e[j].perfor.work_history);
    printf("\nPresent promotion status is %s", e[j].perfor.promotion);
    printf("\nDo you want to update\n1 --> Yes\n2 --> No\nINPUT:");
    scanf("%d", &x);
    getchar();
    if (x == 1)
    {
        printf("\nWork history: ");
        fgets(e[j].perfor.work_history, 100, stdin);
        printf("\nPromotion: ");
        fgets(e[j].perfor.promotion, 50, stdin);
        printf("\nUpdated\n");
    }
    if (x == 2)
    {
        printf("\nNo changes\n");
    }
}

/*------------------------------------   T R A I N I N G   M A N A G E M E N T  ----------------------------------*/

void manage_training(struct employee *e, int j)
{
    int x;
    printf("\nPresent record is %d years", e[j].training);
    printf("\nDo you want to update\n1 --> Yes\n2 --> No\nINPUT:");
    scanf("%d", &x);
    if (x == 1)
    {
        printf("Enter training record(years): ");
        scanf("%d", &e[j].training);
        printf("\nUpdated\n");
    }
    if (x == 2)
    {
        printf("\nNo changes\n");
    }
}
/*--------------------------------------   F I N A N C E   M A N A G E M E N T  ----------------------------------*/

void manage_finance(struct employee *e, int j)
{
    int x;
    printf("Finance\nAllowance: %d\nAdvance: %d\nDue: %d\nLoan: %d\n", e[j].emp_sal.allowance, e[j].emp_sal.advance, e[j].emp_sal.due, e[j].emp_sal.loan);
    printf("\nDo you want to update\n1 --> Yes\n2 --> No\nINPUT:");
    scanf("%d", &x);
    if (x == 1)
    {
        printf("\nAllowance: ");
        scanf("%d", &e[j].emp_sal.allowance);
        printf("\nAdvance: ");
        scanf("%d", &e[j].emp_sal.advance);
        printf("\nDue: ");
        scanf("%d", &e[j].emp_sal.due);
        printf("\nLoan: ");
        scanf("%d", &e[j].emp_sal.loan);
        printf("\nUpdated\n");
    }
    if (x == 2)
    {
        printf("\nNo changes\n");
    }
}

/*------------------------------------   N E W   U S E R   A D D I T I O N  --------------------------------------*/

void add_new_user(struct employee *e, int len)
{
    int i;
    int x;
    int j;
    i = (len - 1);
    printf("\n---Employee - %d---\n", i + 1);
    printf("\nEnter Emp ID: ");
    scanf("%d", &e[i].ID);
    getchar();
    printf("Enter name: ");
    fgets(e[i].name, 30, stdin);
    printf("\nSet a password: ");
    fgets(e[i].pass, 50, stdin);
    printf("\nAdd employee salary details\n");
    printf("Payment: ");
    scanf("%d", &e[i].emp_sal.payment);
    printf("\nDeduction: ");
    scanf("%d", &e[i].emp_sal.deduction);
    printf("\nTotal: ");
    scanf("%d", &e[i].emp_sal.total);
    printf("\nDuration: ");
    scanf("%d", &e[i].emp_sal.duration);
    e[i].emp_sal.allowance = 0;
    e[i].emp_sal.advance = 0;
    e[i].emp_sal.due = 0;
    e[i].emp_sal.loan = 0;
    printf("\nDo you want to add events\n1 ----> Yes\n2 ---> No\ninput:");
    scanf("%d", &x);
    getchar();
    if (x == 1)
    {
        printf("\nEvent description: ");
        fgets(e[i].eve.description, 50, stdin);
        printf("\nEvent date");
        printf("\nDay: ");
        scanf("%d", &e[i].eve.eve_date.day);
        printf("\nMonth: ");
        scanf("%d", &e[i].eve.eve_date.mon);
        printf("\nYear: ");
        scanf("%d", &e[i].eve.eve_date.year);

        getchar();
    }
    else if (x == 2)
    {
        printf("Enter 'no': ");
        fgets(e[i].eve.description, 50, stdin);
        e[i].eve.eve_date.day = 0;
        e[i].eve.eve_date.mon = 0;
        e[i].eve.eve_date.year = 0;
        printf("\n** Event details not added **\n");
    }
    printf("\nAdd attendance\n");
    printf("Entry time: ");
    fgets(e[i].attend.entry, 10, stdin);
    printf("\nExit time: ");
    fgets(e[i].attend.exit, 10, stdin);
    printf("\nLeave details\n");
    printf("Total: ");
    scanf("%d", &e[i].lev.tot_lev);
    printf("\nRemaining: ");
    scanf("%d", &e[i].lev.remain);
    getchar();
    printf("\nDo you want to enter any leave request now/'no'(IF NOT TYPE 'no'): ");
    fgets(e[i].lev.req, 5, stdin);
    for (j = 0; e[i].lev.req[j] != '\0'; j++)
        ;
    if (j == 4)
    {
        printf("Date\n");
        printf("Day: ");
        scanf("%d", &e[i].lev.leave_date.day);
        printf("Month: ");
        scanf("%d", &e[i].lev.leave_date.mon);
        printf("Year: ");
        scanf("%d", &e[i].lev.leave_date.year);
    }
    printf("Enter training record(years): ");
    scanf("%d", &e[i].training);
    getchar();
    printf("\nEmployee work history(if any or no): ");
    fgets(e[i].perfor.work_history, 100, stdin);
    printf("\nPromotion(if any or no): ");
    fgets(e[i].perfor.promotion, 50, stdin);
}

/*------------------------------------   U S E R   I N F O   D I S P L A Y  --------------------------------------*/

void display(struct employee *e, int j)
{
    printf("\nEmployee name: %s\n", e[j].name);
    printf("Salary\nPayment: %d\nDeduction: %d\nTotal: %d\nDuration: %d\n", e[j].emp_sal.payment, e[j].emp_sal.deduction, e[j].emp_sal.total, e[j].emp_sal.duration);
    printf("Total leaves: %d\n", e[j].lev.tot_lev);
    printf("Remaining: %d", e[j].lev.remain);
}

/*-------------------------------   A T T E N D A N C E   M A N A G E M E N T   ----------------------------------*/

void manage_attendance(struct employee *e, int j)
{
    int x;
    printf("\nAttendance\nEntry: %s\nExit: %s", e[j].attend.entry, e[j].attend.exit);
    printf("\nDo you want to update\n1 --> Yes\n2 --> No\nINPUT:");
    scanf("%d", &x);
    getchar();
    if (x == 1)
    {
        printf("\nEntry: ");
        fgets(e[j].attend.entry, 10, stdin);
        printf("\nExit: ");
        fgets(e[j].attend.exit, 10, stdin);
        printf("\nUpdated\n");
    }
    if (x == 2)
    {
        printf("\nNo changes\n");
    }
}

/*------------------------------------------   L E A V E   M A N A G E M E N T  ----------------------------------*/

void manage_leave_req(struct employee *e, int j)
{
    int i;
    int x;
    x = 1;
    for (i = 0; e[j].lev.req[i] != '\0'; i++)
        ;
    if (i == 3)
    {
        printf("No request\n");
        printf("Total: %d\n", e[j].lev.tot_lev);
        printf("Remaining: %d\n", e[j].lev.remain);
    }
    else if (i == 4)
    {
        printf("Resequest placed for leave on %d-%d-%d\n", e[j].lev.leave_date.day, e[j].lev.leave_date.mon, e[j].lev.leave_date.year);
        printf("Total: %d\n", e[j].lev.tot_lev);
        printf("Remaining: %d\n", e[j].lev.remain);
        printf("Do you want to grant(yes\\no): ");
        fgets(e[j].lev.permis, 5, stdin);
        for (x = 0; e[j].lev.req[x] != '\0'; x++)
            ;
        if (x == 3)
        {
            printf("Total: %d\n", e[j].lev.tot_lev);
            printf("Remaining: %d\n", e[j].lev.remain);
        }
        else if (x == 4)
        {
            e[j].lev.remain--;
            printf("Total: %d\n", e[j].lev.tot_lev);
            printf("Remaining: %d\n", e[j].lev.remain);
        }
    }
}

/*-------------------------------------       A D M I N   L O G I N       ----------------------------------------*/

void admin_log(struct employee *e, int len)
{
    int a;
    int b;
    int i;
    int j;

    printf("\nHello!! Admin\nWhat do you want to do?\n");
    do
    {
        printf("\n1 --> View employee details\n2 --> Update\\modify employee details\n3 --> Add new employee details\n4 --> Verify leave request\n5 --> Manage Finance\n6 --> Manage Attendance\n7 --> Manage Performnce\n8 --> Manage Events\n0 --> Logout\nINPUT:");
        scanf("%d", &a);
        // getchar();
        if (a == 1)
        {
            printf("\nEnter Employee ID: ");
            scanf("%d", &b);

            for (i = 0; i < len; i++)
            {
                if (e[i].ID == b)
                {
                    j = i;
                }
            }
            display(e, j);
        }
        else if (a == 2)
        {
            printf("\nEnter Employee ID: ");
            scanf("%d", &b);

            for (i = 0; i < len; i++)
            {
                if (e[i].ID == b)
                {
                    j = i;
                }
            }
            edit_user_info(e, j);
        }
        else if (a == 3)
        {
            len++;
            add_new_user(e, len);
        }
        else if (a == 4)
        {
            printf("\nEnter Employee ID: ");
            scanf("%d", &b);
            getchar();

            for (i = 0; i < len; i++)
            {
                if (e[i].ID == b)
                {
                    j = i;
                }
            }
            manage_leave_req(e, j);
        }
        else if (a == 5)
        {
            printf("\nEnter Employee ID: ");
            scanf("%d", &b);

            for (i = 0; i < len; i++)
            {
                if (e[i].ID == b)
                {
                    j = i;
                }
            }
            manage_finance(e, j);
        }
        else if (a == 6)
        {
            printf("\nEnter Employee ID: ");
            scanf("%d", &b);

            for (i = 0; i < len; i++)
            {
                if (e[i].ID == b)
                {
                    j = i;
                }
            }
            manage_attendance(e, j);
        }
        else if (a == 7)
        {
            printf("\nEnter Employee ID: ");
            scanf("%d", &b);

            for (i = 0; i < len; i++)
            {
                if (e[i].ID == b)
                {
                    j = i;
                }
            }
            manage_performance(e, j);
        }
        else if (a == 8)
        {
            printf("\nEnter Employee ID: ");
            scanf("%d", &b);

            for (i = 0; i < len; i++)
            {
                if (e[i].ID == b)
                {
                    j = i;
                }
            }
            manage_events(e, j);
        }

    } while (a != 0);
}

/*----------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------       U S E R   P A N E L       ----------------------------------------*/

void user_display(struct employee *e, int j, int len)
{
    printf("\nEmployee name: %s\n", e[j].name);
    printf("Salary\nPayment: %d\nDeduction: %d\nTotal: %d\nDuration: %d\n", e[j].emp_sal.payment, e[j].emp_sal.deduction, e[j].emp_sal.total, e[j].emp_sal.duration);
    printf("Total leaves: %d\n", e[j].lev.tot_lev);
    printf("Remaining: %d\n", e[j].lev.remain);
}

/*----------------------------------     A T T E N D A N C E    M A I N T A I N E N C E   -----------------------*/

void man_attend(struct employee *e, int j, int len)
{
    printf("\nEntry time: ");
    fgets(e[j].attend.entry, 50, stdin);
    printf("\nExit time: ");
    fgets(e[j].attend.exit, 10, stdin);
}

/*---------------------------------------------      E V E N T S     ---------------------------------------------*/

void user_events(struct employee *e, int j, int len)
{
    printf("\nEvent details are '''%s \n", e[j].eve.description);
    printf("Event date is %d-%d-%d\n", e[j].eve.eve_date.day, e[j].eve.eve_date.mon, e[j].eve.eve_date.year);
}

/*--------------------------------------     L E A V E      R E Q U E S T   -------------------------------------*/

void leave_req_user(struct employee *e, int j, int len)
{
    int i;
    printf("\nDo you want to request for a leave(yes\\no)?: ");
    fgets(e[j].lev.req, 5, stdin);
    for (i = 0; e[j].lev.req[i] != '\0'; i++)
        ;
    if (i == 4)
    {
        printf("Date\n");
        printf("Day: ");
        scanf("%d", &e[j].lev.leave_date.day);
        printf("Month: ");
        scanf("%d", &e[j].lev.leave_date.mon);
        printf("Year: ");
        scanf("%d", &e[j].lev.leave_date.year);
    }
}

/*---------------------------------------     I N F O    U P D A T E   -------------------------------------------*/

void update_user(struct employee *e, int j, int len)
{
    int i;
    printf("\nWhat do you want to update??\n");
    printf("\n1 --> Name\n2 --> Password\nINPUT:");
    scanf("%d", &i);
    getchar();
    if (i == 1)
    {
        printf("\nUpdate your name: ");
        fgets(e[j].name, 30, stdin);
    }
    else if (i == 2)
    {
        printf("\nUpdate your password: ");
        fgets(e[j].pass, 50, stdin);
    }
}

/*----------------------------------------     U S E R     L O G I N  --------------------------------------------*/

void user(struct employee *e, int len, int id)
{
    int a;
    int i;
    int j;
    for (i = 0; i < len; i++)
    {
        if (e[i].ID == id)
        {
            j = i;
        }
    }
    printf("\nHello user %d\n", id);
    printf("What do you want to do??\n");
    do
    {
        printf("\n1 --> Display your info\n2 --> Update your data\n3 --> Manage attendance\n4 --> View events\n5 --> Request leave\n0 --> Logout\nINPUT: ");
        scanf("%d", &a);
        getchar();
        if (a == 1)
        {
            user_display(e, j, len);
        }
        else if (a == 2)
        {
            update_user(e, j, len);
        }
        else if (a == 3)
        {
            man_attend(e, j, len);
        }
        else if (a == 4)
        {
            user_events(e, j, len);
        }
        else if (a == 5)
        {
            leave_req_user(e, j, len);
        }
    } while (a != 0);
}

/*----------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------       M A I N       -----------------------------------------------*/

int main()
{
    int admin;
    char admin_pass[50];
    int id;
    char pass[50];
    int i;
    int j;
    int x;
    int z;
    struct employee e[20];
    printf("\nSETUP ADMIN ID: ");
    scanf("%d", &admin);
    getchar();
    printf("\nAdmin Pass: ");
    fgets(admin_pass, 50, stdin);
    printf("\nEnter the no.of employee details to add: ");
    scanf("%d", &len);
    getchar();
    add_new(e, len);
    do
    {
        printf("\n1 --> User Login\n2 --> Admin login\n0 --> Exit\nINPUT: ");
        scanf("%d", &z);
        if (z == 1)
        {
            printf("\nEnter your id: ");
            scanf("%d", &id);
            getchar();
            for (i = 0; i < len; i++)
            {
                if (e[i].ID == id)
                {
                    j = i;
                }
            }
            printf("Enter your password: ");
            fgets(pass, 50, stdin);
            x = 1;
            for (i = 0; pass[i] != '\0'; i++)
            {
                if (pass[i] != e[j].pass[i])
                {
                    x = 0;
                }
            }
            if (x)
            {
                user(e, len, id);
            }
            else
            {
                printf("\n**Wrong USERNAME/ID OR PASSWORD\n");
            }
        }
        else if (z == 2)
        {
            printf("\nEnter Admin ID: ");
            scanf("%d", &id);
            getchar();

            if (id == admin)
            {
                printf("\nEnter pass: ");
                fgets(pass, 50, stdin);
                x = 1;
                for (i = 0; pass[i] != '\0'; i++)
                {
                    if (pass[i] != admin_pass[i])
                    {
                        x = 0;
                    }
                }
                if (x)
                {
                    admin_log(e, len);
                }
                else
                {
                    printf("\n**Wrong PASSWORD**\n");
                }
            }
            else
            {
                printf("\n**Wrong ID**\n");
            }
        }
    } while (z != 0);
    return 0;
}
