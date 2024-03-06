// libaray unit A
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <sys/utsname.h>
#include <libgen.h>



void TypingGame(){

system("clear");
// the word bank
const char* realWords[] = {
    "might", "govern", "take", "you", "need", "child", "we", "move", "time", "present",
    "at", "come", "day", "one", "become", "home", "way", "world", "look", "life",
    "know", "people", "work", "use", "find", "give", "tell", "ask", "try", "call",
    "own", "end", "should", "great", "place", "year", "government", "company", "part", "problem",
    "fact", "right", "power", "often", "long", "country", "friend", "school", "group", "father",
    "mother", "hand", "old", "place", "big", "small", "live", "thought", "few", "put",
    "understand", "point", "leave", "name", "world", "high", "seem", "important", "different", "next",
    "early", "young", "open", "until", "example", "beautiful", "agree", "money", "however", "body",
    "above", "bit", "book", "music", "game", "keep", "eye", "mind", "face", "side",
    "heart", "door", "idea", "head", "food", "foot", "city", "side", "state", "word",
};


int getNumRealWords(){
    return sizeof(realWords) / sizeof(realWords[0]);
}

const char* getRandomRealWord() {
    int index = rand() % getNumRealWords();
    return realWords[index];
}


    srand(time(NULL));

    
    int count = 0;
    while (count < 25){
        for (int i = 0; i < 10; ++i) {  
            const char* randomRealWord = getRandomRealWord();
            char RandomWordTypeThingIDK[1000];
            printf("Type: %s\n ~> ",randomRealWord);
            scanf("%s", RandomWordTypeThingIDK);
            system("clear");
            count++;
            if (count >= 25) {
                break;
            }
        }
        
    }

}












void BlackJackFunc(){

    system("clear");
    srand(time(0)); 
    int Pot = 0;
    int PlayerPotBet;
    do {

        printf("Enter the amount of money you want to put in the pot (over $100)\n~> $");
        scanf("%d", &PlayerPotBet);
    } while (PlayerPotBet < 100);

    char DealersPotBet[9999];
    int DealersBet = rand() % 10000 + 100;

    int FinalPot = PlayerPotBet + DealersBet;

    system("clear");
    printf("The dealer has bet $%d\n", DealersBet);
    printf("The Pot is at $%d (all bets are off)\n", FinalPot);

    int PlayerCard = rand() % 11 + 1;
    int DealerCard = rand() % 11 + 1;
    int twoPlayerCard = rand() % 11 + 1;

    usleep(2000000);
    system("clear");

    printf("Your First Card is a %d\n", PlayerCard);
    printf("your second card is %d\n", twoPlayerCard);

    int PlayerNonHitTotal = PlayerCard + twoPlayerCard;
    printf("rigt now your total is %d\n", PlayerNonHitTotal);

    printf("The dealer has a %d\n", DealerCard);

    int DealerNewcard = rand() % 11 + 1;
    int PlayerNewCard = rand() % 11 + 1;
    int PlayerTotalcards = PlayerCard + twoPlayerCard;
    int DealerTotalCards = DealerCard + DealerNewcard;

    do {
        char PlayerFirstChoice_H_or_S[9999];
        printf("Would you like to hit or stand?\n~>");
        scanf("%s", PlayerFirstChoice_H_or_S);



        if (strcmp(PlayerFirstChoice_H_or_S, "hit") == 0) 
        {
            printf("Your New card is a %d\n You Have %d in total\n", PlayerNewCard, PlayerNewCard + PlayerTotalcards);
            printf("The dealers new card is a %d\nThe dealer now has %d in total\n", DealerNewcard, DealerNewcard + DealerTotalCards);

        } else if (strcmp(PlayerFirstChoice_H_or_S, "stand") == 0) 
        {
            printf("Dealers turn: the dealers new card is %d\n the dealer has %d in total\n", DealerCard, DealerTotalCards);

        } else
        {
            printf("INVALID\n");
        }

        if (PlayerNonHitTotal > 21)
        {
            printf("You Lose!");
            exit(0);
        } else if (PlayerTotalcards > 21)
        {
            printf("You Lose!");
            exit(0);
        } else if (DealerTotalCards > 21)
        {
        printf("You Win!");
        exit(0);
        }

    } while ((PlayerNonHitTotal < 21 || PlayerTotalcards < 21 || DealerTotalCards < 21) && (PlayerTotalcards <= 21 && DealerTotalCards <= 21));


}


void CoinFlipFunc(){

    srand(time(NULL));

    char *CoinSides[2] = {"Heads", "Tails"};
    
    system("clear");
    // Generate a random index (0 or 1) to represent Heads or Tails
    int randomIndex = rand() % 2;

    // Use the random index to get the result
    char *CoinResult = CoinSides[randomIndex];
    printf("%s\n", CoinResult);



}




void timer(){

    system("clear");
    int timerchoice;

    printf("From where do you want to count down from?\n~>");
    scanf("%d", &timerchoice); // Corrected: added & before timerchoice

    int i;
    for (i = timerchoice; i > 0; i--) { // Corrected: changed loop condition
        printf("%d ", i);
        fflush(stdout);
        usleep(1000000); // Corrected: increased usleep value for better visibility
        system("clear");
    }

    printf("TIMES UP\n"); // Added: Display "TIMES UP" after countdown


}





void dice_roll(){
    
    
    int Rnumber;

    system("clear");
    int dicechoice;
    printf("how many dice do you wanna roll?\n~>");
    scanf("%d", &dicechoice);

    Rnumber = rand() % dicechoice + 1;

    
    printf("the dice rolled %d", Rnumber);


}





void Geuss_The_Number(){

    system("clear");
    int number, guess, nguesses=1;
    number = rand() % 25 + 1;


    do 
    {
        printf("guess the number (1 - 25)\n~>");
        scanf("%d", &guess);
        if (guess < number)
        {
            system("clear");
            printf("too low, try again\n");
        }
        else if (guess > number)
        {
            system("clear");
            printf("too high, try again\n");
        }
        else if (guess == number)
        {
            printf("you guessed it right! in %d attempts\n", nguesses);
            break;
        }
        nguesses++;

    } while (guess != number);


}





void Journal(){

system("clear");
const char* filename = "Journal.txt";
FILE* file = fopen(filename, "w");

if (file == NULL) {
    fprintf(stderr, "Unable to open file '%s'\n", filename);
    
}

printf("Enter a date\n~> ");
char date[50];


if (scanf(" %[^\n]", date) != 1) {
    fprintf(stderr, "Error reading date\n");
    fclose(file);
}


fprintf(file, "┏━━━━━━━━━━━━━━━┓\n   %s\n┗━━━━━━━━━━━━━━━┛\n\n ↳", date);

fclose(file);

printf("File '%s' created and written successfully.\n", filename);
}










void loading2(){

system("clear");
printf("Program exiting.\n");
sleep(1.5);
system("clear");
printf("Program exiting..\n");
sleep(1.5);
system("clear");
printf("Program exiting...\n");
sleep(1.5);
system("clear");
printf("Program exiting.\n");
sleep(1.5);
system("clear");
printf("Program exiting..\n");
sleep(1.5);
system("clear");
printf("Program exiting...\n");
sleep(1.5);
system("clear");
printf("Successfully Exited.");
exit(0);

}




void  RPS(){
  system("clear");
  int userChoice, computerChoice;
  
  srand(time(NULL));
  
  
  printf("Welcome to Rock, Paper, Scissors!\n");
  printf("1. Rock\n");
  printf("2. Paper\n");
  printf("3. Scissors\n");
  printf("Enter your choice (1-3)\n~>");
  
  
  scanf("%d", &userChoice);
  
  
  if (userChoice < 1 || userChoice > 3) {
      printf("Invalid choice. Please enter a number between 1 and 3.\n~>");
       
  }
  
  
  computerChoice = rand() % 3 + 1;
  
  
  printf("You chose: ");
  switch (userChoice) {
      case 1:
          printf("Rock\n");
          break;
      case 2:
          printf("Paper\n");
          break;
      case 3:
          printf("Scissors\n");
          break;
  }
  
  printf("Computer chose: ");
  switch (computerChoice) {
      case 1:
          printf("Rock\n");
          break;
      case 2:
          printf("Paper\n");
          break;
      case 3:
          printf("Scissors\n");
          break;
  }
  
  
  if (userChoice == computerChoice) {
      printf("It's a tie!\n");
  } else if ((userChoice == 1 && computerChoice == 3) ||
              (userChoice == 2 && computerChoice == 1) ||
              (userChoice == 3 && computerChoice == 2)) {
        system("clear");
	printf("You win!\n");
  } else {
        system("clear");
	printf("Computer wins!\n");
  }


}


int loginpasswd = 12345;

void Bank_Game(){

    system("clear");
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(" Welcome to the bank of dumb!\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    char option1[1500];
    printf("Would you like to set up a new account('new') or log in('login')?\n~>");
    scanf("%s", option1);

    if (strcmp(option1, "new") == 0 || strcmp(option1, "New") == 0) {
        char newusername[1500];
        printf("enter your name\n~>");
        scanf("%s", newusername);

        char newuserpasswd[1500];
        printf("enter your new account password\n~>");
        scanf("%s", newuserpasswd);

    } else if (strcmp(option1, "log in") == 0 || strcmp(option1, "login") == 0) {
        char loginusername[1500];
        printf("enter your log in name\n~>");
        scanf("%s", loginusername);

        int loginuserpasswd;
        printf("enter your log in account password\n~>");
        scanf("%d", &loginuserpasswd);

        if (loginuserpasswd != loginpasswd) {
            printf("INCORRECT!");
        } else {
            system("clear");
            printf("welcome back %s ", loginusername);
        }
    }

    char option2[1500];
    printf("would you like to deposit or withdrawl\n~>");
    scanf("%s", option2);

    if (strcmp(option2, "withdrawl") == 0 || strcmp(option2, "Withdrawl") == 0) {
        printf("YOUR BROKE IDIOT!");
        exit(0);
    } else if (strcmp(option2, "deposit") == 0) {
        int depositcount;
        printf("how much money do you want to deposit?\n~> $");
        scanf("%d", &depositcount);

        printf("you have deposited $%d into your account!", depositcount);
    }

}



void systeminfo(){
    system("clear");
    struct utsname system_info;

  if (uname(&system_info) != 0) {
      perror("Error getting system information");
      
  }

  printf("System Information:\n");
  printf("  - System Name: %s\n", system_info.sysname);
  printf("  - Node Name: %s\n", system_info.nodename);
  printf("  - Release: %s\n", system_info.release);
  printf("  - Version: %s\n", system_info.version);
  printf("  - Machine: %s\n", system_info.machine);



}


void Calculator(){

system("clear");
char choice;
do {
    printf(" ==============\n");
    printf("  ~CALCULATOR~\n");
    printf(" ==============\n");

    char choice2[1000];
    printf("What would you like to do? Type \nany other key for basic math,\n'circle',\n'sqrt',\n'round',\n'pow'\n~> ");
    scanf("%s", choice2);
    if (strcmp(choice2, "circle") == 0) {
        const double PI = 3.14159;
        double radius;
        double circumference;
        double area;

        printf("\nEnter the radius of the circle\n ~>");
        scanf("%lf", &radius);

        circumference = 2 * PI * radius;
        area = PI * radius * radius;

        printf("\nthe Circumference is: %lf", circumference);
        printf("\nthe area is: %lf\n", area);
    } else if (strcmp(choice2, "pow") == 0) {
        double pow1;
        double pow2;
        printf("enter first number\n~> ");
        scanf("%lf", &pow1);

        printf("enter the number you're gonna raise that number by\n~> ");
        scanf("%lf", &pow2);

        double powresult = pow(pow1, pow2);

        printf("Result is %.1lf\n", powresult);

    } else if (strcmp(choice2, "sqrt") == 0) {
            double sqrt1;
            printf("enter the number you want to find the sqaure root of\n~> ");
            scanf("%lf", &sqrt1);

            double sqrtR = sqrt(sqrt1); 

            printf("the square root of %.1lf is [%.1lf]\n", sqrt1, sqrtR);
    } else if (strcmp(choice2, "round") == 0) {
        double Rnum;
        printf("enter a number you would like to round to the nerest interger\n~> ");
        scanf("%lf", &Rnum);

        double RR = round(Rnum);
        printf("it is %.2lf\n", RR);
    
                
    
    } else {
        char OP;
        printf("What operator do you want to use ['+', '-', '*', '/']\n~> ");
        scanf(" %c", &OP);

        double one, two;
        printf("Enter the first number\n~> ");
        scanf("%lf", &one);

        printf("Enter the second number\n~> ");
        scanf("%lf", &two);

        double result;

        switch (OP) {
            case '+':
                result = one + two;
                printf("The result is ~> %.1lf\n", result);
                break;
            case '-':
                result = one - two;
                printf("The result is ~> %.1lf\n", result);
                break;
            case '*':
                result = one * two;
                printf("The result is ~> %.1lf\n", result);
                break;
            case '/':
                if (two != 0) {
                    result = one / two;
                    printf("The result is ~> %.1lf\n", result);
                } else {
                    printf("Error: Cannot divide by zero.\n");
                }
                break;
            default:
                printf("Error: Invalid operator.\n");
                break;
        }
    }

    printf("Do you want to run the program again? (y/n)\n~> ");
    scanf(" %c", &choice);
    while (getchar() != '\n');

} while (choice == 'y' || choice == 'Y');

printf("Program exiting.\n");



}


void encrypt(char *message);
void decrypt(char *message);

#define MAX_LENGTH 1000

void ciphercrypt(){
   system("clear");
   char message[MAX_LENGTH];
    int choice;

    printf("Choose operation:\n");
    printf("~> --- 1. Encrypt --- <~\n");
    printf("~> --- 2. Decrypt --- <~\n");
    printf("Enter 1 or 2: \n~> ");
    scanf("%d", &choice);

    printf("Enter the message (Limit = %d) \n~> ", MAX_LENGTH - 1);
    scanf(" %[^\n]", message);

    switch (choice) {
        case 1:
            encrypt(message);
            system("clear");
            printf("Encrypted message ~> %s\n", message);
            break;
        case 2:
            decrypt(message);
            system("clear");
            printf("Decrypted message ~> %s\n", message);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    
}

void encrypt(char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                message[i] = (message[i] - 1 - 'a' + 26) % 26 + 'a';
            } else {
                message[i] = (message[i] - 1 - 'A' + 26) % 26 + 'A';
            }
        }
    }
}

void decrypt(char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                message[i] = (message[i] + 1 - 'a' + 26) % 26 + 'a';
            } else {
                message[i] = (message[i] + 1 - 'A' + 26) % 26 + 'A';
            }
        }
    }

}



void Vendinggame(){

  float pepsi = 3.00;
  float coca = 3.00;
  float fanta = 3.00;
  float sprite = 3.00;
  float water = 1.50;
  float lemonade = 2.00;
  float lays = 1.50;
  float doritos = 1.50;
  float ruffles = 1.50;
  float cheetos = 1.50;
  float takis = 1.50;
  float snickers = 1.00;
  float kitkat = 1.00;
  float hersheys = 1.00;
  float MnMs = 1.00;
  float mints = 0.50;
  float gum = 1.50;
  char orb[] = "???";
  char sel[2];
  float money;
  float moneyN;
  float change;
  char name[10];
  char yn;
  char t[10]; 

  system("clear");
  printf("\n\n\n    a1    a2    a3    a4    a5\n");
  printf("   pepsi cola fanta sprite water\n");
  printf("   $3.00 $3.00 $3.00 $3.00 $1.50\n\n");
  printf("   a6     a7    a8      a9      b1\n");
  printf("lemonade lays doritos ruffles cheetos\n");
  printf(" $2.00  $1.50  $1.50   $1.50   $1.50\n\n");
  printf("  b2      b3      b4     b5      b6\n");
  printf("takis  snickers kitkat hersheys MnMs\n");
  printf("$1.50    $1.00   $1.00   $1.00 $1.00\n\n");
  printf("            b7     b8    z0\n");
  printf("           mints   gum   orb\n");
  printf("           $0.50  $1.50  $???\n\n");

  printf("enter code:");
  scanf("%s", sel);

  if (strcmp(sel, "a1") == 0) {
    strcpy(name, "pepsi");
    moneyN = 3.00;
  } else if (strcmp(sel, "a2") == 0) {
    strcpy(name, "cola");
    moneyN = 3.00;
  } else if (strcmp(sel, "a3") == 0) {
    strcpy(name, "fanta");
    moneyN = 3.00;
  } else if (strcmp(sel, "a4") == 0) {
    strcpy(name, "sprite");
    moneyN = 3.00;
  } else if (strcmp(sel, "a5") == 0) {
    strcpy(name, "water");
    moneyN = 1.50;
  } else if (strcmp(sel, "a6") == 0) {
    strcpy(name, "lemonade");
    moneyN = 2.00;
  } else if (strcmp(sel, "a7") == 0) {
    strcpy(name, "lays");
    moneyN = 1.50;
  } else if (strcmp(sel, "a8") == 0) {
    strcpy(name, "doritos");
    moneyN = 1.50;
  } else if (strcmp(sel, "a9") == 0) {
    strcpy(name, "ruffles");
    moneyN = 1.50;
  } else if (strcmp(sel, "b1") == 0) {
    strcpy(name, "cheetos");
    moneyN = 1.50;
  } else if (strcmp(sel, "b2") == 0) {
    strcpy(name, "takis");
    moneyN = 1.50;
  } else if (strcmp(sel, "b3") == 0) {
    strcpy(name, "snickers");
    moneyN = 1.00;
  } else if (strcmp(sel, "b4") == 0) {
    strcpy(name, "kitkat");
    moneyN = 1.00;
  } else if (strcmp(sel, "b5") == 0) {
    strcpy(name, "hersheys");
    moneyN = 1.00;
  } else if (strcmp(sel, "b6") == 0) {
    strcpy(name, "MnMs");
    moneyN = 1.00;
  } else if (strcmp(sel, "b7") == 0) {
    strcpy(name, "mints");
    moneyN = 0.50;
  } else if (strcmp(sel, "b8") == 0) {
    strcpy(name, "gum");
    moneyN = 1.50;
  } else if (strcmp(sel, "z0") == 0) {
    printf("Error:HUT54IHT54ITH");
    printf("enter to continue\n");
    while (getchar() != '\n')
      ;
    getchar();
    Vendinggame();
  } else {
    printf("invalad code");
    printf("press enter to continue\n");
    while (getchar() != '\n')
      ;
    getchar();
    Vendinggame();
  }

  printf("you are getting %s\n", name);
  printf("y/n ");
  scanf(" %c", &yn);

  if (yn == 'n') {
    Vendinggame();
  }

  printf("insert money:");
  scanf("%f", &money);
  change = money - moneyN;
  if (change < 0) {
    printf("not enough money");
    printf("\npress enter to continue\n");
    while (getchar() != '\n');
    getchar();
    Vendinggame();
  }
  printf("your change is %.2f\n", change);
  

  char again;

  printf("\nget another item? (y/n)  ");
  scanf(" %c", &again);

  if (again == 'y') {

      system("cls");
      Vendinggame();

  } else if (again == 'n') {

      system("exit");

  } else {

      printf("invalad input");
  
  }
    
    

}







void todo_list(){

    int listnum;
    printf("How many to-do things do you want to add: ");
    scanf("%d", &listnum);

    getchar();

    char listname[1000];

    int fileNumber = 1;
    char filename[100]; 

    while (1) {
        snprintf(filename, sizeof(filename), "To-DoList%d.txt", fileNumber);
        FILE *file = fopen(filename, "r");
        
        if (file == NULL) {
            break;
        }
        
        fileNumber++;
        fclose(file);  
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");

    }

    for (int i = 0; i < listnum; i++) {
        printf("Enter the name of the to-do thing %d: ", i + 1);
        fgets(listname, sizeof(listname), stdin);

        fprintf(file, "[%c] %s", ' ', listname);
    }

    fclose(file);

    printf("To-do list has been saved to %s\n", filename);
}

void URLopener(){

char URL[1000];
system("clear");
printf("enter the URL you want to open \n~>");
scanf("%s", URL);

char command[1100];
sprintf(command, "open %s", URL);

system(command);
}





void quack() {
    printf("quack\n");
}

void quackfunc(){

    system("clear");
    char usrInput[2000]; 
    printf("\nEnter the issue you are dealing with \n~>");
    
    while (1) { 

        fgets(usrInput, sizeof(usrInput), stdin);
        
        if (usrInput[0] != '\n' && strcmp(usrInput, "\r\n") != 0 && strcmp(usrInput, "\n") != 0) {
            quack();
        }
    }

}




void randmpasswdfunc1();
   
   void generatePassword(char *password, int length) {
    const char characters[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    srand((unsigned int)time(NULL));

    for (int i = 0; i < length; ++i) {
        int index = rand() % (sizeof(characters) - 1);

        password[i] = characters[index];
    }

    password[length] = '\0';
}


void Randmpasswdfunc2(){

    int passwordLength = 12;

char password[passwordLength + 1];

generatePassword(password, passwordLength);
system("clear");
printf("Generated Password: %s\n", password);
}









    



void loading(){

    // loading statments
    system("clear");
    printf(" [ DONE ] Finding Libaries ...\n");
    usleep(200000);
    printf(" [ DONE ] Loading Commands ...\n");
    usleep(200000);
    printf(" [ DOING ] Building User Interface ...\n");
    usleep(200000);
    printf( " [ DONE ] Fetching Statements ...\n");
    usleep(200000);
    printf(" [ DONE ] Fetching Old Users ...\n");
    usleep(200000);
    printf(" [ DOING ] Resolving Dependencies ...\n");
    usleep(200000);
    printf(" [ DOING ] Loading Configuration ...\n");
    usleep(200000);
    printf(" [ DONE ] Initializing Modules ...\n");
    usleep(200000);
    printf(" [ DONE ] Validating Input ...\n");
    usleep(200000);
    system("clear");

    int i;
    for (i = 1; i <= 100; i++) {
        printf("%d ", i);
        fflush(stdout); 
        usleep(5005); 
        system("clear");
    }
}

int main(int argc, char *argv[]) {

    loading();

    int passwd = 4511;

    printf("Enter your user name \n~> ");
	char userName[1500]; 
    scanf("%s", userName);


    int passwd2;
    printf("Enter the password \n~>");
    scanf("%d", &passwd2);

    if (passwd2 == passwd) {
        system("clear");
        printf("You're in.\n");
        printf("Welcome %s\n", userName);
        sleep(1);
        system("clear"); 
    } 
  else if (passwd2 != passwd){
        system("clear");
		printf("INCORRECT!\n"); 
        exit(0);
	}


    char path[5000];  
    realpath(__FILE__, path);
    
    
    char *dir = dirname(path);
    
    while (1) {
        char HelpCommand[1500];
        printf("\n%s/Idk%s\n~>", userName, dir);
        scanf("%s", HelpCommand);
    
        // giant if, else if tower
        if (strcmp(HelpCommand, "random_passwd") == 0)
        {
            Randmpasswdfunc2();

        } else if (strcmp(HelpCommand, "quack_debugger") == 0)
        {
            quackfunc();
            
        } else if (strcmp(HelpCommand, "url_opener") == 0)
        {
            URLopener();

        } else if (strcmp(HelpCommand, "todo_list") == 0)
        {
            todo_list();

        } else if (strcmp(HelpCommand, "vending_game") == 0)
        {
            Vendinggame();
        } else if (strcmp(HelpCommand, "cipher") == 0)
        {
            ciphercrypt();

        } else if (strcmp(HelpCommand, "calculator") == 0)
        {
            Calculator();

        } else if (strcmp(HelpCommand, "system_info") ==0)
        {
            systeminfo();
        
        } else if (strcmp(HelpCommand, "bank_game") == 0)
        {
            Bank_Game();

        } else if (strcmp(HelpCommand, "rock_paper_scissors") == 0)
        {
            RPS();

        } else if (strcmp(HelpCommand, "journal") == 0)
        {
            Journal();

        } else if (strcmp(HelpCommand, "guess_number_game") == 0)
        {
            Geuss_The_Number();

        } else if (strcmp(HelpCommand, "dice_roll") == 0)
        {
            dice_roll();

        } else if (strcmp(HelpCommand, "timer") == 0)
        {
            timer();

        } else if (strcmp(HelpCommand, "coin_flip") == 0)
        {
            CoinFlipFunc();
        
        } else if (strcmp(HelpCommand, "blackjack") == 0)
        {
            BlackJackFunc();
        
        } else if (strcmp(HelpCommand, "typing_game") == 0)
        {
            TypingGame();
        
        } else if (strcmp(HelpCommand, "clear") == 0)
        {
            system("clear");
        
        } else if (strcmp(HelpCommand, "whoami") == 0)
        {   
            printf("\n%s", userName);
        
        } else if (strcmp(HelpCommand, "ls") == 0)
        {
            system("ls");
        
        } else if (strcmp(HelpCommand, "shutdown") == 0)
        {
            loading2();

        } else if (strcmp(HelpCommand, "user") == 0)
        {
            system("clear");
            printf("UserName: %s\n", userName);
            printf("UserPassword: %d\n", passwd);

        } else if (strcmp(HelpCommand, "make_love") == 0)
        {
            printf("Not War.\n");

        } else if (strcmp(HelpCommand,"help") == 0)
        {
            system("clear");
            char HelpCommand[1500];
            printf("Enter the command you will like to run:\n┏━━━━━━━━━⊚━━━━━━━━━┓\n 'random_passwd'\n 'quack_debugger'\n 'url_opener'\n 'todo_list'\n 'vending_game'\n 'cipher'\n 'calculator'\n 'system_info'\n 'bank_game'\n 'rock_paper_scissors'\n 'journal'\n 'guess_number_game'\n 'dice_roll'\n 'timer'\n 'coin_flip'\n 'blackjack'\n 'typing_game'\n 'whoami'\n 'ls'\n 'shutdown'\n┗━━━━━━━━━⊚━━━━━━━━━┛\n~>");
            scanf("%s", HelpCommand);

            // another tower
            if (strcmp(HelpCommand, "random_passwd") == 0)
            {
                Randmpasswdfunc2();

            } else if (strcmp(HelpCommand, "quack_debugger") == 0)
            {
                quackfunc();
                
            } else if (strcmp(HelpCommand, "url_opener") == 0)
            {
                URLopener();

            } else if (strcmp(HelpCommand, "todo_list") == 0)
            {
                todo_list();

            } else if (strcmp(HelpCommand, "vending_game") == 0)
            {
                Vendinggame();
            } else if (strcmp(HelpCommand, "cipher") == 0)
            {
                ciphercrypt();

            } else if (strcmp(HelpCommand, "calculator") == 0)
            {
                Calculator();

            } else if (strcmp(HelpCommand, "system_info") ==0)
            {
                systeminfo();
            
            } else if (strcmp(HelpCommand, "bank_game") == 0)
            {
                Bank_Game();

            } else if (strcmp(HelpCommand, "rock_paper_scissors") == 0)
            {
                RPS();

            } else if (strcmp(HelpCommand, "journal") == 0)
            {
                Journal();

            } else if (strcmp(HelpCommand, "guess_number_game") == 0)
            {
                Geuss_The_Number();

            } else if (strcmp(HelpCommand, "dice_roll") == 0)
            {
                dice_roll();

            } else if (strcmp(HelpCommand, "timer") == 0)
            {
                timer();

            } else if (strcmp(HelpCommand, "coin_flip") == 0)
            {
                CoinFlipFunc();

            } else if (strcmp(HelpCommand, "blackjack") == 0)
            {
                BlackJackFunc();
        
            } else if (strcmp(HelpCommand, "typing_game") == 0)
            {
                TypingGame();
        
            } else if (strcmp(HelpCommand, "clear") == 0)
            {
                system("clear");
        
            } else if (strcmp(HelpCommand, "whoami") == 0)
            {
                printf("\n%s", userName);
            
            } else if (strcmp(HelpCommand, "ls") == 0)
            {
                system("ls");
        
            } else if (strcmp(HelpCommand, "shutdown") == 0)
            {
                loading2();
            } else if (strcmp(HelpCommand, "make_love") == 0)
            {
                printf("Not War.");

            } else if (strcmp(HelpCommand, "user") == 0)
            {
                system("clear");
                printf("UserName: %s\n", userName);
                printf("UserPassword: %d\n", passwd);    

            } else
            {
                printf("\nINVALID SYNTAX\n");
            }


        } else
        {
            printf("\nINVALID SYNTAX");
        }
        
        
        
        
        
        //re-run
    } 

        

    loading2();


    


    return 0;
}



