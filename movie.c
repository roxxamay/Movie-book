/**  MOVIE TICKET BOOKING
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<cstdio>

struct book{
    char code[20] ;
    char name[20] ;
    char date[20] ;
    int cost ;
}b;

int seat = 60 ;

void insertDetails() ; // for inserting movie details

void viewAll() ;    // for viewing all data

void find() ;   //  for finding data

void bookTicket() ; // for booking tickets

void oldRecord() ;      //for viewing old records of user , booked tickets


int main(){

    int ch ;
    do{ // ascii art for ui
        printf(R"EOF(

            ██████████████████████████████████████████████████████████████████████████████████████████
            █▌ __    __       __    ___                                    __    _____  ____  __    ▐█
            █▌/ / /\ \ \___  / /   / __\___   /\/\   ___    /\/\  _ __    /__\  /___\ \/ /\ \/ /\_/\▐█
            █▌\ \/  \/ / _ \/ /   / /  / _ \ /    \ / _ \  /    \| '__|  / \// //  //\  /  \  /\_ _/▐█
            █▌ \  /\  /  __/ /___/ /__| (_) / /\/\ \  __/ / /\/\ \ |    / _  \/ \_// /  \  /  \ / \ ▐█
            █▌  \/  \/ \___\____/\____/\___/\/    \/\___| \/    \/_|    \/ \_/\___/ /_/\_\/_/\_\\_/ ▐█
            ██████████████████████████████████████████████████████████████████████████████████████████
        

            ╔════════════════════════════════════════════════════════╗
            ║███╗   ███╗ ██████╗ ██╗   ██╗██╗███████╗                ║
            ║████╗ ████║██╔═══██╗██║   ██║██║██╔════╝                ║
            ║██╔████╔██║██║   ██║██║   ██║██║█████╗                  ║
            ║██║╚██╔╝██║██║   ██║╚██╗ ██╔╝██║██╔══╝                  ║
            ║██║ ╚═╝ ██║╚██████╔╝ ╚████╔╝ ██║███████╗                ║
            ║╚═╝     ╚═╝ ╚═════╝   ╚═══╝  ╚═╝╚══════╝                ║
            ║                                                        ║
            ║████████╗██╗ ██████╗██╗  ██╗███████╗████████╗           ║
            ║╚══██╔══╝██║██╔════╝██║ ██╔╝██╔════╝╚══██╔══╝           ║
            ║   ██║   ██║██║     █████╔╝ █████╗     ██║              ║
            ║   ██║   ██║██║     ██╔═██╗ ██╔══╝     ██║              ║
            ║   ██║   ██║╚██████╗██║  ██╗███████╗   ██║              ║
            ║   ╚═╝   ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝   ╚═╝              ║
            ║                                                        ║
            ║██████╗  ██████╗  ██████╗ ██╗  ██╗██╗███╗   ██╗ ██████╗ ║
            ║██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝██║████╗  ██║██╔════╝ ║
            ║██████╔╝██║   ██║██║   ██║█████╔╝ ██║██╔██╗ ██║██║  ███╗║
            ║██╔══██╗██║   ██║██║   ██║██╔═██╗ ██║██║╚██╗██║██║   ██║║
            ║██████╔╝╚██████╔╝╚██████╔╝██║  ██╗██║██║ ╚████║╚██████╔╝║
            ║╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝ ╚═════╝ ║
            ╚════════════════════════════════════════════════════════╝
        )EOF");

        printf("\nPRESS [ 1 ]  INSERT MOVIE\n");
        printf("PRESS [ 2 ]  VIEW ALL MOVIE\n");
        printf("PRESS [ 3 ]  FIND MOVIE\n");
        printf("PRESS [ 4 ]  BOOK TICKETS\n");
        printf("PRESS [ 5 ]  VIEW ALL TRANSACTIONS\n");
        printf("PRESS [ 0 ]  EXIT\n");

        printf("ENTER YOUR CHOICES : ");
        scanf("%d" ,&ch);
       
        switch ( ch ){
            case 1 : insertDetails() ;
                        break;

            case 2 : viewAll();
                        break;

            case 3 : find();
                        break;

            case 4 : bookTicket();
                        break;

            case 5 : viewAll();
                        break;
            case 0 :  exit(0);
                        break;

            default : printf("Wrong Choice");
                        break;
        }               
            
        }
        while(ch!=0);
}


void insertDetails(){
    FILE *fp ;//starting file handeling
    struct book b ;
    printf("\nEnter Movie code : ") ;
    scanf("%s" , &b.code) ;
    printf("\nEnter Name : ");
    scanf("%s" , &b.name) ;
    printf("\nEnter Release Date : ") ;
    scanf("%s" , &b.date ) ;
    printf("Enter Ticket Price : ");
    scanf("%d" ,&b.cost) ;

    //file handeling 

    fp = fopen("data.txt" , "a");

    if(fp == NULL){     //checking file is presnt or not
        printf("404... NOT FOUND");
    }
    else
    {
        fprintf(fp , "%s %s %s %d \n" , b.code , b.name , b.date , b.cost);

        printf("Record Insert Successfully");
    }
    printf("\n");
    fclose(fp);
}

/**
 * This code defines a function `insertDetails` that allows users to input details about a movie and stores this information into a file named "data.txt". Let's break down the code:

1. `FILE *fp;` declares a file pointer for file handling.
2. `struct book b;` declares a structure variable `b` of type `book` which presumably holds details about a movie (code, name, release date, and ticket price).
3. The `printf` statements prompt the user to input details such as movie code, name, release date, and ticket price using `scanf`.
4. `fp = fopen("data.txt", "a");` attempts to open the file named "data.txt" in append mode (`"a"`). If the file does not exist, it will be created. If there's an issue opening the file, it displays "404... NOT FOUND".
5. Inside the `else` block, if the file is successfully opened, `fprintf` writes the movie details entered by the user into the file in a formatted manner.
6. After writing the details or if there was an issue with file opening, it prints appropriate messages.
7. `fclose(fp);` closes the file after the operation.

However, there are some considerations and potential improvements:
- The code assumes that the user input will not exceed the allocated space for `b.code`, `b.name`, and `b.date`. There's a risk of buffer overflow if the user enters more characters than the allocated space.
- Error handling for invalid user inputs (e.g., non-numeric input for `b.cost` or entering more characters than allowed) is not present.
- It's important to validate and sanitize user input to prevent potential issues like buffer overflow or unexpected behavior due to invalid input.
- Consider adding validation checks to ensure that the entered data is within the expected format and range.

Improvements can be made by adding input validation and handling possible errors for a more robust and user-friendly program.
*/

void find(){
    struct book b ;
    FILE *fp ;

    char ch[20] ;
    printf("Enter Movie Name Code ") ;
    scanf("%s" , &ch ) ;

    fp = fopen("data.txt" , "r") ;
    if(fp == NULL){
        printf("file does not found ! ") ;
        exit(1) ;
    }
    else{
        while(getc(fp) != EOF)      //eof means end of files this value is true until end of file which is -1
        //  reference link : https://www.geeksforgeeks.org/eof-and-feof-in-c/

        {
            fscanf(fp, "%s %s %s %d", b.code, b.name, b.date, b.cost);
            if (strcmp(b.code, ch) == 0)
            {
                //             In C language, (strcmp(b.code, ch) == 0) is a logical expression that compares two strings for equality. It uses the strcmp() function, which is used to compare two strings lexicographically.

                // Here's how the expression is evaluated:

                // b.code and ch are assumed to be string variables or character arrays.
                // The strcmp() function takes these two strings as arguments and compares them.
                // If the two strings are equal, strcmp() returns 0.
                // The == operator then compares the returned value (0) with 0.
                // If the result of the comparison is true (0 is equal to 0), the overall expression evaluates to true.
                // So, (strcmp(b.code, ch) == 0) can be read as "if the string b.code is equal to the string ch, do something."
                // referance link : https://www.geeksforgeeks.org/strcmp-in-c/

                printf("RECORD FOUND \n");
                printf("\n\t\tCode : %s", b.code);
                printf("\n\t\tMovie Name : ", b.name);
                printf("\n\t\tMovie Date : ", b.date);
                printf("\n\t\tPrice Of Ticket : ", b.cost);
            }
        }
    }
    fclose(fp); //closing the file handeling
}


//for viewing all

void viewAll(){
  char ch ;
  FILE *fp ;

  fp = fopen("data.txt" , "r");

  if(fp == NULL){
    printf("404....  file doesnot found ");
    exit(1);
  }
  else {
    //system("clear");
    while((ch == fgetc(fp) ) != EOF){
      printf("%c", ch);
    }
    
    fclose(fp);
  } 
}

/**
 * This code defines a function named `find` that aims to search for movie details in a file named "data.txt" based on a user-entered movie code. Here's a breakdown of the code:

1. `struct book b;` declares a structure variable `b` of type `book`, presumably holding details about a movie (code, name, release date, and ticket price).
2. `FILE *fp;` declares a file pointer for file handling.
3. `char ch[20];` declares a character array to store the user input for the movie code.
4. `printf("Enter Movie Name Code ");` prompts the user to enter a movie code.
5. `scanf("%s" , &ch );` reads the user input into the `ch` array.
6. `fp = fopen("data.txt" , "r");` attempts to open the file named "data.txt" in read mode (`"r"`). If the file does not exist or there's an issue opening it, it displays "file does not found !" and exits the program.
7. Inside the `else` block, if the file is successfully opened, the code enters a `while` loop that reads the file character by character until it reaches the end of the file (`EOF`).
8. Within the loop, `fscanf(fp, "%s %s %s %d", b.code, b.name, b.date, b.cost);` reads data from the file into the `b` structure.
9. It checks if the `b.code` matches the user-inputted `ch` using `strcmp(b.code, ch) == 0`. If there's a match, it prints the details of the movie found.
10. After the loop finishes reading the file or finds a matching record, it closes the file using `fclose(fp)`.

Potential improvements:
- Error handling: The code doesn't handle cases where the user input is longer than the allotted space in `ch`.
- Efficiency: The code reads the entire file even after finding a matching record, which might not be necessary. It could exit the loop once the record is found to improve efficiency, especially with large files.

Overall, the code tries to find and display movie details based on a user-provided movie code by scanning the "data.txt" file. However, it would benefit from additional error handling and efficiency improvements.
*/

//For tickets booking 

void bookTicket(){
  struct book b ;
  FILE *fp;

  FILE *ufp ;
  int totalSeat , mobile , totalAmount ;
  char name[20] ;

  char ch ;   //used in display all
  char movieCode[20];       //for searching
  
  //display all movies by default for movie code
  fp = fopen("data.txt", "r");
  if(fp == NULL){
    printf("File doesnot found....!");
    exit(1);
  }
  else{
    system("clear");
    while( (ch = fgetc(fp) ) !=EOF );
    printf("%c",ch);
  }
  fclose(fp);

  // display ends
  printf("\nFor booking ticket choose movie ");
  printf("\n Enter Movie Code : ") ;
  scanf("%s",movieCode);

  fp = fopen("data.txt", "r");
  if(fp == NULL){
    printf("File doesnt found !");
    exit(1);
  }
  else{
    while(getc(fp) != EOF){
        fscanf(fp,"%s %s %s %d",b.code , b.name , b.date , &b.cost);
        if(strcmp(b.code , movieCode) == 0){
            printf("\n RECORD FOUND");
            printf("\ncode : %s" ,b.code);
            printf("\nMovie Name : %s", b.name);
            printf("\nDate Name : %s", b.date);
            printf("\nPrice of Tickets : %d",b.cost);
        }
    }
  }

  printf("\n===== FILE DETAILS====");
  printf("\nYour name :");
  scanf("%s", &name);
  printf("\nMobile number : ");
  scanf("%d",&mobile);
  printf("\n Total Number Of tickets : ") ;
  scanf("%d",&totalSeat);

  totalAmount = b.cost * totalSeat ;

  printf("\n ENJOY MOVIE");                 //showing booked info
  printf("\nName : %s ",name);
  printf("\nMobile Number : %d ", mobile);
  printf("\nmovie Name: %s ", b.name);
  printf("\nTotal Seat: %d ", totalSeat);
  printf("\nCoast per tickets : %d ", b.cost);
  printf("\nTotal Amount : %d ", totalAmount);

  ufp = fopen("oldTransaction.txt","a");        //opening transaction file
  if(ufp ==NULL){
    printf("ERROR 404 NOT FOUND");
  }
  else{
    fprintf(ufp , "%s %d %d %d %s %d ",name , mobile , totalSeat , b.name , b.cost) ;
    printf("==RECORD INSERT SUCCESSFULLY TO THE OLD RECORD FILE");
  }
  printf("\n");
  fclose(ufp);

  fclose(fp);
}

/**
 * This code defines a function named `bookTicket` to facilitate the booking of movie tickets. Here's a breakdown of the code:

1. **Variable Declarations:**
   - Declares variables and file pointers required for handling file operations, storing user inputs (name, mobile, totalSeat), and reading movie details.

2. **Displaying Available Movies:**
   - Opens "data.txt" to display all available movies and their details to the user. The code reads the file character by character and prints its contents until it reaches the end of the file (EOF). However, there seems to be an issue here. The while loop for displaying movies only reads the file but does not print the characters during the loop execution. It displays the last character outside the loop, which might not be the intended behavior.

3. **Booking Process:**
   - Asks the user to enter the movie code they want to book tickets for.
   - Opens "data.txt" again to search for the movie with the entered code. If found, it displays the movie details.
   - Requests user information such as name, mobile number, and the total number of tickets they want to book.
   - Calculates the total amount based on the cost of a single ticket (`b.cost`) multiplied by the total number of seats (`totalSeat`).
   - Displays the booking details to the user.

4. **Recording Transaction:**
   - Opens a file named "oldTransaction.txt" in append mode to store the transaction details.
   - Writes the user's name, mobile number, total number of tickets, movie name, and ticket cost into the "oldTransaction.txt" file.

5. **File Closure:**
   - Closes the opened files.

Potential issues/improvements:
- There's an issue with displaying movies from "data.txt" due to the logic used for reading and printing characters.
- Error handling for invalid inputs (e.g., non-numeric input for mobile or totalSeat) is missing.
- Buffer overflow risk exists for the `name` variable when using `scanf("%s", &name);` as it doesn't limit the number of characters entered by the user.
- The storage format in "oldTransaction.txt" might need to be revisited to ensure proper separation of data for easier retrieval and interpretation.

Overall, the code aims to facilitate booking movie tickets by displaying available movies, allowing the user to select a movie by its code, gathering booking information, displaying booking details, and recording the transaction into a separate file. However, it requires refinements in user input handling, file reading/printing logic, and transaction recording for improved functionality and reliability.
*/

void oldRecord(){
    char ch ;
    FILE *fp ;

    fp = fopen("oldTransaction.txt" , "r");
    if(fp ==NULL){
        printf("\nFile does Not found ! ") ;
        exit(1) ;
    }
    else{
        while((ch = fgetc(fp))!= EOF){
            printf("%c",ch);
        }
    }
    fclose(fp);
}

/**
 * Certainly! This code defines a function named `oldRecord` to display the contents of the file "oldTransaction.txt," which presumably contains old transaction records. Let's break down the code:

1. **Variable Declarations:**
   - Declares a character variable `ch` for reading characters from the file.
   - Declares a file pointer `fp` for handling file operations.

2. **Opening the File:**
   - Attempts to open the file "oldTransaction.txt" in read mode (`"r"`).
   - If the file opening fails (`fp == NULL`), it displays a message "File does Not found ! " and exits the program with an exit code of 1.

3. **Displaying File Contents:**
   - Inside the `else` block (if the file was successfully opened), a `while` loop reads the file character by character until it reaches the end of the file (`EOF`).
   - Within the loop, `fgetc(fp)` reads a character from the file and stores it in the variable `ch`.
   - The code then prints the character read from the file using `printf("%c", ch)`.

4. **File Closure:**
   - Closes the opened file after reading and displaying its contents.

Potential improvements or considerations:
- The code reads and prints characters from the file one by one. It assumes that the content of "oldTransaction.txt" is plain text or contains data that can be interpreted as characters. If the file contains structured data or multiple types of information, parsing and displaying it appropriately would require additional logic.
- Displaying raw file contents might not be user-friendly if the data is in a structured format. Parsing and formatting the data for better readability could be beneficial.
- Error handling beyond checking if the file exists could be added, such as handling situations where the file is empty or when there are errors while reading the file contents.

In summary, this function `oldRecord` opens and reads the contents of the "oldTransaction.txt" file character by character, displaying its raw content to the user. However, if the file contains structured data or specific types of records, additional parsing and formatting might be necessary for better interpretation and usability.
*/