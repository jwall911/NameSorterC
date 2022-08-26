/*
 * Josh Wallace 11/18/2018
 */
#include <stdio.h>   //header file for input/output
#include <string.h>
#define SIZE 15     
#define LIM 30        /* maximum number of lines to be read */
#define HALT ""        /* null string to stop input          */

int menu(void);   //prototype definition
void hello(void);
void sort_str(void);
void stsrt(char *strings[], int num);
char * s_gets(char * st, int n);
void ToUpper(char * str);

int main(void)
{
    int selection = menu();  //variable declaration and initialization via call to menu()
    //The line above also serves as the 'priming' read for the following while loop
    
    
    while(selection != 99) {
    
        // The switch statement is similar to a chained if-else except conditions fall through in C!
        switch(selection) {

        case 1:
           hello();  
           break;  
           
        case 2:
            sort_str();
           break;
         
        case 3: 
        
           break;

        case 4:
        
           break;  
           
         default: /* Optional - but a good idea expecially if you have no other error catching! */
            printf("Please enter a valid selection.\n");
        }
        
    selection = menu();    // get the next menu selection, otherwise, you have an eternal loop!
    }
    
   return 0;
}
 
int menu(void) {
    int choice;
    printf("***************************\n");
    printf(" 1. Hello \n");
    printf(" 2. Name Sorter\n");
    printf(" 3. \n");
    printf(" 4. \n");
    printf("99. Exit\n");
    printf("Please select number and press enter:\n");
    printf("***************************\n");
    scanf("%d", &choice);
    return choice;   
}

void hello(void) {
    printf("Hello, World!!!\n");
}


void sort_str(void)
{
    getchar();
    char firstNames[LIM][SIZE];     /* array to store input       */
    char *fnptr[LIM];          /* array of pointer variables */
    char lastNames[LIM][SIZE];
    char *lnptr[LIM];
    char names[LIM][50];
    char *ptnames[LIM];
    
    int ct = 0;  /* input count                */
    int ct2 = 0; /* input count 2              */
    int k;                     /* output count               */
    
    printf("Please enter the students' first name\n",LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while (ct < LIM && s_gets(firstNames[ct], SIZE) != NULL
           && firstNames[ct][0] != '\0')
    {
        ToUpper(firstNames[ct]);
        fnptr[ct] = firstNames[ct];  /* set ptrs to strings        */
        ct++;
    }
    printf("Please enter the students' last name\n",LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while (ct2 < LIM && s_gets(lastNames[ct2], SIZE) != NULL
           && lastNames[ct2][0] != '\0')
    {
        ToUpper(lastNames[ct2]);
        lnptr[ct2] = lastNames[ct2];
        ptnames[ct2] = names[ct2];
        sprintf(ptnames[ct2], "%s, %s", lnptr[ct2], fnptr[ct2]);
        ct2++;
    }
    stsrt(ptnames, ct2);
    
    puts("\nHere's the first and last names alphabetized:");
    for (k = 0; k < ct2; k++)
        puts(ptnames[k]);       /* sorted pointers            */
}

/* string-pointer-sorting function */
void stsrt(char *strings[], int num)
{
    char *temp;
    int top, seek;
    
    for (top = 0; top < num-1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top],strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}