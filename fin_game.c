#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DOLLAR 80;
#define EURO 90;
#define RUBBLE 1;
#define DOLLAR_SIGN '$';
#define EURO_SIGN 'Є';
#define RUBBLE_SIGN '₽';

struct Progress{
    int balance;
    int days;
};

struct Date{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct User{
    char name[100];
    char currency;
    struct Progress *progress;
    struct Date *date;
    
};

void help(void) {
    printf("This is a 365 financial challenge!\n");
    printf("It will help you to save some money for a purchase\n");
    printf("or an emergency fund. You can save in three currencies:\n");
    printf("rubbles, dollars, euros. The rules are simple:\n");
    printf("Put money away every day until a year has passed\n");
    printf("You should deposit money according to the number of day you are on.\n");
    printf("It may be more but not less. Lastly, you should not withdraw your money,\n");
    printf("unless there is a great need to. However, mind the consequences!\n");
    printf("Good luck on your financial journey!!!\n\n");
}

void create_user(struct User * user_info, struct Progress * progress_info, struct Date * date_info){
    // filling date info
    time_t t = time(NULL);
    struct tm time_data = *localtime(&t);
    short curr_day = time_data.tm_mday;
    short curr_month = 1+time_data.tm_mon;
    short curr_year = 1900+time_data.tm_year;
    date_info->day = curr_day;
    date_info->month = curr_month;
    date_info->year = curr_year;
    // filling progress info
    int balance = 0;
    int days = 0;
    progress_info->balance = balance;
    progress_info->days = days;
    // filling user info
    char name[100] = "Jake";
    char currency = DOLLAR_SIGN;
    strcpy(user_info->name, name);
    user_info->currency = currency;
    user_info->progress = progress_info;
    user_info->date = date_info;
}

void load_user(char * file_name, struct User * user_info, struct Progress * progress_info, struct Date * date_info){
    
}


void print_user_info(struct User * user_struct){
    printf("Name of the player: %s\n", user_struct->name);
    printf("Savings currency: %c\n", user_struct->currency);
    printf("Amount of savings: %d\n", user_struct->progress->balance);
    printf("The date of the beginning of the game: %hu/%hu/%hu\n", user_struct->date->day, user_struct->date->month, user_struct->date->year);
    printf("The progress of the journey: %d out of 365 days\n\n", user_struct->progress->days);

}

void save_progress(struct User * user){
    FILE *fp;
    char filename[255];
    sprintf(filename, "%s_fin_progress.txt", user->name);
    fp = fopen(filename, "w+");
    fprintf(fp, "Name: %s\n", user->name);
    fprintf(fp, "Saving currency: %c\n", user->currency);
    fprintf(fp, "Current balance: %d\n", user->progress->balance);
    fprintf(fp, "Progress: %d out of 365 days\n", user->progress->days);
    fprintf(fp, "Starting date: %hu/%hu/%hu", user->date->day, user->date->month, user->date->year);
    fclose(fp);
    printf("File was created and saved!\n");
}



int main() {
    // initializing pointers
    struct User* st_ptr = NULL;
    struct Progress* pr_ptr = NULL;
    struct Date* date_ptr = NULL;
    struct Date dat;
    date_ptr = &dat;
    struct Progress pr;
    pr_ptr = &pr;
    struct User test_user;
    st_ptr = &test_user;
    //functions
    help();
    create_user(st_ptr, pr_ptr, date_ptr);
    print_user_info(st_ptr);
    save_progress(st_ptr);
    return 0;
}