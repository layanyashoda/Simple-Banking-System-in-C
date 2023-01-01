#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//variables
void login(); 
int newacc();
void Exit();
int userscrn();
int accdet();
int chkbal(); 
int tramny();
int depmny(); 
int delacc();
int updtacc();
int updtusrnm();
int updtpin();
int logout();
void loading();

//structure variables
struct details
{
    char username[15];
    char NIC[13];
    char F_name[15];
    char L_name[15];
    char year[5];
    char month[4];
    char date[4];
    char City[20];
    char email[25];
    char P_num[11];
    char pin[4];
};

//Variables for Create New Account Details

//Variables for Transfer money
struct tramny{
    char R_Name[15];    
    int amount[10];
    char S_Name[15];
    char NIC[13];
    char remarks[25];
};

int main(){

    system("cls"); //Clear Screen
    system("color 0E");
    int mainchoice;
    //Selection menu
    mainmenu:

    printf("\n====================Temp BANK====================\n");

    printf("\n\n\t1.Log-In to a Existing Account.\t");
    printf("\n\n\t2.Create a New Account.\t");
    printf("\n\n\t3.Exit.\t\n");
    printf("\n\n=================================================");

    //Prompting user for input & getting input
    printf("\n\nYour selection ");
    scanf("%d",&mainchoice);

    switch (mainchoice){
        case 1:
        login(); 
        break;

        case 2:
        newacc(); 
        break;

        case 3:
        system("cls");
        Exit();
        break;

        default:
        printf ("\nInvalid Selection\n\n"); 
        goto mainmenu;
        //If user inputs any other value than 1 2 3 displays an error message & allows to choose a value again
        
    }

    return 0;
}

//Function for Login to a existing account
void login(){
    
    system("cls"); //Clear Screen
    char usname[20];
    unsigned int pinnum;

    FILE *login;
    login = fopen("details.txt","r");

    printf("\n==================Temp BANK==================\n");
    
    printf("\n\n\tEnter Your Username: ");
    scanf("%s",&usname);
    printf("\n\tYour Name: %s",usname);
    printf("\n\n\tEnter Your Pin Number: ");
    scanf("%u",&pinnum);
    printf("\n\tYour Pin Number: %u",pinnum);
    printf("\n\n=============================================");

    fclose(login); 

    getch();
    userscrn();

}

//Function for Creating a new account
int newacc(){

    // char username[15];
    // char NIC[13];
    // char F_name[15];
    // char L_name[15];
    // char year[5];
    // char month[4];
    // char date[4];
    // char City[20];
    // char email[25];
    // char P_num[11];
    // char pin[4];

    system("cls"); //Clear Screen
    int newchoice;

    printf("\n==================Temp BANK==================\n");

    printf("\nPlease submit the following details to proceed.\n\n");

    FILE *newaccinputs;
    struct details N;
    newaccinputs = fopen ("details.txt","a+");

    printf("National Identy Card No : ");
    scanf("%s",&N.NIC);

    printf("\nFirst Name : ");
    scanf("%s",&N.F_name);
        
    printf("\nLast Name : ");
    scanf("%s",&N.L_name); 

    printf("\nDATE OF BIRTH..");

    printf("\n\tYear : ");
    scanf("\t%s",&N.year);

    printf("\n\tMonth : ");
    scanf("\t%s",&N.month);

    printf("\n\tDate : ");
    scanf("\t%s",&N.date);          
        
    printf("\nCity : ");
    scanf("%s",&N.City);

    printf("\nPhone Number : ");
    scanf("%s",&N.P_num);

    printf("\nEmail : ");
    scanf("%s",&N.email);

    printf("\nEnter Your Username: ");
    scanf("%s",&N.username);
     
    printf("\nEnter Your Pin Number: ");        
    scanf("%s",&N.pin);

    fflush(stdin);
    fwrite(&N, sizeof(N),1, newaccinputs); 
    // fprintf(newaccinputs,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",&N.NIC,&N.F_name,&N.L_name,&N.year,&N.month,&N.date,&N.City,&N.P_num,&N.email,&N.username,&N.pin);
    // fwrite(&N,sizeof(struct newAcc),1,newaccinputs);
    fclose(newaccinputs);
    
    system("cls"); //Clear Screen
    printf("\n====================Temp BANK====================\n");
    printf("\n\n\t1.Account Created Successfully.\t");
    printf("\n\n=================================================");        

    getch();
    userscrn();
    
}

//User Screen
int userscrn(){

    system("cls"); //Clear Screen

    int userchoice;
        //Selection menu
        usermenu:

        printf("\n====================Temp BANK====================\n");

        printf("\n\n\t1.Account Details.\t");
        printf("\n\n\t2.Check Account Balance.\t");
        printf("\n\n\t3.Transfer Money.\t");
        printf("\n\n\t4.Deposit Money.\t");
        printf("\n\n\t5.Delete Account.\t");
        printf("\n\n\t6.Update Account.\t");
        printf("\n\n\t7.Log-Out.\t");
        printf("\n\n\t8.Exit.\t\n");
        printf("\n\n=================================================");

        //Prompting user for input & getting input
        printf("\n\nYour selection ");
        scanf("%d",&userchoice);

        switch (userchoice){
            case 1:
            accdet(); 
            break;

            case 2:
            chkbal(); 
            break;

            case 3:
            tramny();
            break;

            case 4:
            depmny();
            break;

            case 5:
            delacc(); 
            break;

            case 6:
            updtacc(); 
            break;

            case 7:
            logout(); 
            break;

            case 8:
            Exit(); 
            break;

            default:
            printf ("\nInvalid Selection\n\n"); 
            goto usermenu;
        
    }

}

//Account Details Screen
int accdet(){

    FILE *newaccinputs; 
    newaccinputs = fopen("details.txt", "r");   
    struct details N;
    system("cls"); //Clear Screen

    printf("\n====================Temp BANK====================\n");
    printf("\n\n\tAccount Details\t\n");


    printf("\n\n\tName - %s",N.username);
    printf("\n\n\tNIC Number - \t");
    printf("\n\n\tPress Any Key To Go Back.\n\n");
    printf("\n\n=================================================");

    getch();
    userscrn();

}


//Check Account Balance Screen.
int chkbal(){

    system("cls"); //Clear Screen

    printf("\n====================Temp BANK====================\n\n");
    printf("\tAccount Balance\t\n");

    printf("\n\n\tAccount Balance is - \t\n");
    printf("\n\n\tPress Any Key To Go Back.\n\n");
    printf("\n\n=================================================");

    getch();
    userscrn();

}

//Transfer Money Screen
int tramny(){
    
    int tramnt;
    char R_name[10], S_Name[10], NIC[15], remarks[20];
    time_t t;
    time(&t);
    
    system("cls"); //Clear Screen
    
    printf("\n====================Temp BANK====================\n\n");
    printf("\tTransfer Money\t\n");

    printf("\n\n\tReciever's Name - \t");
    scanf("%s",&R_name);
    printf("\n\n\tAmount Of Money - \t");
    scanf("%d",&tramnt);

    printf("\n\n\tSender's Name - \t");
    scanf("%s",&S_Name);
    printf("\n\n\tNIC Number - \t");
    scanf("%s",&NIC);
    printf("\n\n\tRemarks - \t");
    scanf("%s",&remarks);
    
    system("cls");
    loading();

    system("cls");
    system("color 0E");
    printf("|==========================================================|\n");
    printf("|\t\t\tTemp BANK\t\t\t   |\n");
    printf("|==========================================================|\n");
    printf("|                                                          |\n");
    printf("|\t\t ---Transaction Receipt---\t\t   |\n");
    printf("|                                                          |\n");
    printf("|\t* Receiver Name : %s\t\t\t\t|\n",R_name);
    printf("|                                                          |\n");
    printf("|\t* Amount\t: %d\t\t\t\t   |\n",tramnt);
    printf("|                                                          |\n");
    printf("|  \tSender Details \t\t\t\t\t   |\n");
    printf("|                                                          |\n");
    printf("|       Name - %s\t\t\t\t\t   |\n",S_Name);
    printf("|                                                          |\n");
    printf("|       Remarks - %s\t\t\t\t\t   |\n",remarks);
    printf("|                                                          |\n");
    printf("|  \tDate & Time - %s|\n",ctime(&t));
    printf("|                                                          |\n");
    printf("|==========================================================|\n");
    printf("|            **THANK YOU FOR BANKING WITH US**             |\n");
    printf("|==========================================================|\n");
    system("color 09");
    printf("\n\t** Press Any Key To Proceed ** \n");

    getch();
    userscrn();
}

//Deposit Money Function
int depmny(){

    system("cls"); //Clear Screen
   
    int depamount;
    printf("\n====================Temp BANK====================\n\n");
    printf("\tDeposit Money Into Your Account\t");
    printf("\n\n\tAmount Of Money - \t");
    scanf("%d",&depamount);
    printf("\n\n=================================================");
    system("cls"); //Clear Screen
    printf("\n====================Temp BANK====================\n\n");
    printf("\n\n\tUsername Updated Successfully.\t\n");
    printf("\n\n=================================================");

}

//Delete Account Screen
int delacc(){

    system("cls"); //Clear Screen

    printf("\n====================Temp BANK====================\n\n");
    printf("\tDelete Your Account\t\n");

    printf("\n\n\tHehe :) - \t");
    printf("\n\n\tAi Ithin Delete Karanne?.\n\n");
    printf("\n\n=================================================");

    getch();
    userscrn();

}

//Update Account Details Screen
int updtacc(){

    system("cls"); //Clear Screen
    int updtchoice;

    updtmenu:
    printf("\n====================Temp BANK====================\n\n");
    printf("\tUpdate Your Account Details\t");

    printf("\n\n\t1.Update Username.\n");
    printf("\n\t2.Update PIN Number.\n");
    printf("\n\n=================================================");

    //Prompting user for input & getting input
    printf("\n\nYour selection ");
    scanf("%d",&updtchoice);

    switch (updtchoice){
            case 1:
            updtusrnm(); 
            break;

            case 2:
            updtpin(); 
            break;

            default:
            printf ("\nInvalid Selection\n\n"); 
            goto updtmenu;
        
        }

}

int updtusrnm(){

    char newusrnm[20];
    int tempchoice;
    

    newusrnmenu:
    system("cls"); //Clear Screen
    printf("\n====================Temp BANK====================\n\n");
    printf("\t\tUpdate Username\t\n\n");
    printf("\tEnter Your New Username:  ");
    scanf("%s",&newusrnm);
    printf("\n\n=================================================");
    system("cls"); //Clear Screen
    printf("\n====================Temp BANK====================\n\n");
    printf("\t\tUpdate Username\t\n\n");
    printf("\tYour New Username is %s ",newusrnm);
    printf("\n\n=================================================");
    printf("\n\n\tDo You Want to Proceed?");

    printf("\n\n\t1.Yes.\n");
    printf("\n\t2.No.\n");
    printf("\n\n=================================================");

    //Prompting user for input & getting input
    printf("\n\nYour selection ");
    scanf("%d",&tempchoice);

    switch (tempchoice){
            case 1:
            goto successnm; 
            break;

            case 2:
            goto newusrnmenu;
            break;

            default:
            printf ("\nInvalid Selection\n\n"); 
            goto newusrnmenu;
        
        }

    successnm:
    system("cls"); //Clear Screen
    printf("\n====================Temp BANK====================\n\n");
    printf("\n\n\tUsername Updated Successfully.\t\n");
    printf("\n\n=================================================");

    getch();
    userscrn();


}

int updtpin(){

    int newpin;
    int tempchoice2;
    
    newpinnmenu:
    system("cls"); //Clear Screen
    printf("\n====================Temp BANK====================\n\n");
    printf("\t\tUpdate PIN Number\t\n\n");
    printf("\tEnter Your Current PIN Number:  ");
    scanf("%d",&newpin);

    // if (newpin == pin){}
    printf("\n\n=================================================");
    system("cls"); //Clear Screen
    printf("\n====================Temp BANK====================\n\n");
    printf("\t\tUpdate PIN Number\t\n\n");
    printf("\tYour New PIN Number is %d ",newpin);
    printf("\n\n=================================================");
    printf("\n\n\tDo You Want to Proceed?");

    printf("\n\n\t1.Yes.\n");
    printf("\n\t2.No.\n");
    printf("\n\n=================================================");

    //Prompting user for input & getting input
    printf("\n\nYour selection ");
    scanf("%d",&tempchoice2);

    switch (tempchoice2){
            case 1:
            goto successpin; 
            break;

            case 2:
            goto newpinnmenu;
            break;

            default:
            printf ("\nInvalid Selection\n\n"); 
            goto newpinnmenu;
        
        }

    successpin:
    system("cls"); //Clear Screen
    printf("\n====================Temp BANK====================\n\n");
    printf("\n\n\tUsername Updated Successfully.\t\n");
    printf("\n\n=================================================");

    getch();
    userscrn();

    
}

//Logout Screen
int logout(){

    system("cls"); //Clear Screen
    int logchoice;

    logoutmenu:
    printf("\n====================Temp BANK====================\n\n");
    printf("\tLogging Out Of Your Account\t");

    printf("\n\n\tAre you sure?.\n");
    printf("\n\n\t1.Yes.\n");
    printf("\n\t2.No.\n");
    printf("\n\n=================================================");

    //Prompting user for input & getting input
    printf("\n\nYour selection ");
    scanf("%d",&logchoice);

    switch (logchoice){
            case 1:
            main(); 
            break;

            case 2:
            userscrn(); 
            break;

            default:
            printf ("\nInvalid Selection\n\n"); 
            goto logoutmenu;
        
        }

}

void Exit(){
    system("cls"); //Clear Screen
    printf("\n====================Temp BANK====================\n\n\n");

    printf("\n\tThank You for Being With Us.\n\n");

    printf("\n\n=================================================");

}

void loading(){
    printf("\n====================Temp BANK====================\n\n\n");
    for (int i=0; i<=100; i++){
        system("color 0A");
        int length = 30;
        int display = i * length / 100;
        printf("\r");
        printf("\t");
        for (int i=0; i <= display; i++){
            printf("%c",221);
        }
        for (int i=0; i < length-display; i++){
            printf(">");
        }
        printf(" %d%% Done",i);

    }
}
