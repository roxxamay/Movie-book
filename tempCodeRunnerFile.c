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