#include <stdio.h>
#include <string.h>

struct contact{
    char firstName[25];
    char lastName[25];
    char phoneNumber[25];
    char address[25];
    char email[25];
};
FILE *fp;

int addContact();
int viewContact();
int editContact();
int deleteContact();
int searchContact();

int main() {
    addContact();
    return 0;
}

int addContact() {
    struct contact c;
    int MAXNAMESIZE = 25;
    fp = fopen("contact.txt", "a");
    {
        printf("Please insert the details of your contact\n");
        printf("First Name:");
        fgets(c.firstName, MAXNAMESIZE, stdin);
        c.firstName[strcspn(c.firstName,"\n")] = 0;

        printf("Last Name:");
        fgets(c.lastName, MAXNAMESIZE, stdin);
        c.lastName[strcspn(c.lastName, "\n")] = 0;

        printf("Phone Number:");
        fgets(c.phoneNumber, MAXNAMESIZE, stdin);
        c.phoneNumber[strcspn(c.phoneNumber, "\n")] = 0;

        printf("Address:");
        fgets(c.address, MAXNAMESIZE, stdin);
        c.address[strcspn(c.address, "\n")] = 0;

        printf("Email Address:");
        fgets(c.email, MAXNAMESIZE, stdin);
        c.email[strcspn(c.email, "\n")] = 0;

        fprintf(fp,"%s, %s, %s, %s, %s\n", c.firstName, c.lastName, c.phoneNumber, c.address, c.email);
        printf("Contact was succesfully added\n");
    }

    fclose(fp);
    return  0;
}
