#include <stdio.h>

#define MAX_LENGTH 100
#define true 1
#define false 0

char password[MAX_LENGTH];
char username[MAX_LENGTH];
char temp_pass[MAX_LENGTH];


// this is a code of a scenario where a user signs up, add a password (after following requirements).
// then when he signs in, he write his password.


// rules of password: 
//     1) minimum 8 slots and max 99 slots
//     2) minimum 1 number
//     3) minimum 1 character
//     4) minimum one special character
//     5) not the same as the username

// ------------------------------------------------------------------------------------------------

/// @brief copy array elements from a to b
void copyArray(char a[], char b[]){
    for (int i = 0; i < a[i] != '\0'; i++){
        b[i] = a[i];
    }
}


/// @brief store a username
void storeUsername(){
    printf("please enter a username: ");
    scanf("%s", username);
}


/// @brief check if entered passowrd length is minimum 8
/// @return 1 if true, 0 if false
int PasswordConditionOne(){
    int counter = 0;
    for (int i = 0; temp_pass[i] != '\0' ; i++)
            counter++;
    
    if (counter >= 7)
        return true;
    else{
        printf("ERROR: password length at least 8.\n enter new password: ");
        return false;
    }
}



/// @brief check if entered password has at least one number
/// @return 1 if true, 0 if false
int PasswordConditionTwo(){
    char numbers [] = "0123456789";

    for (int i = 0; temp_pass[i] != '\0'; i++)
    {
        for(int j = 0; temp_pass[j] != '\0'; j++)
        {
            if (temp_pass[i] == numbers[j])
            {
                return true;
            }
        }
    }
    // reutrn false in case none found;
    printf("ERROR: password didn't have a number.\n enter new password: ");
    return false;
}



/// @brief check if entered password has at least one character
/// @return 1 if true, 0 if false
int PasswordConditionThree(){
    char ABChars [] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

    for (int i = 0; temp_pass[i] != '\0'; i++)
    {
        for(int j = 0; ABChars[j] != '\0'; j++)
        {
            if (temp_pass[i] == ABChars[j])
            {
                return true;
            }
        }
    }
    // reutrn false in case none found;
    printf("ERROR: password didn't have at least one character.\n enter new password: ");
    return false;
}



/// @brief check if entered password has at least one special character
/// @return 1 if true, 0 if false
int PasswordConditionFour(){
    char uniqueChars [] = "!@#$%%^&*()-_=+[]{}|;:',.<>/?";

    for (int i = 0; temp_pass[i] != '\0'; i++)
    {
        for(int j = 0; uniqueChars[j] != '\0'; j++)
        {
            if (temp_pass[i] == uniqueChars[j])
            {
                return true;
            }
        }
    }
    // reutrn false in case none found;
    printf("ERROR: password didn't have unique character.\n enter new password: ");
    return false;
}


/// @brief check if entered password has at least one special character
/// @return 1 if true, 0 if false
int PasswordConditionFive(){
    for (int i = 0; temp_pass[i] != '\0'; i++)
    {
        for(int j = 0; username[j] != '\0'; j++)
        {
            if (temp_pass[i] == username[j])
            {
                printf("ERROR: Password cannot be the same as username.\n enter new password: ");
                return false;
            }
        }
    }
    return true;
}






/// @brief if matching requirements, it will store password
/// @param Password variable we want to store password to
void storePassword(){
    int allowed = true;


    printf("Please Enter a Password to store: ");
    while (allowed != false)
    {
        scanf("%s", temp_pass);
        int c1, c2, c3, c4;

        if (PasswordConditionOne() && 
            PasswordConditionTwo() && 
            PasswordConditionThree() && 
            PasswordConditionFour() && 
            PasswordConditionFive()) {
            copyArray(temp_pass, password);
            allowed = false;
        }
        
    }  
}



/// @brief start the process of sign up
/// @param Password variable to store user password at
/// @param username variable to store user username at
void signUp(){
    storeUsername();
    storePassword();

    printf("Sign Up Completed.\n");
}



/// @brief start the process of sign
/// @param Password saved password during sign up
/// @param username saved username during sign up
void signIn(){
    char PassInput [MAX_LENGTH];
    char UserNameInput [MAX_LENGTH];
    int flag = true;
    int attempts = 0;


    // username checking 
    printf("please enter your username: ");
    while (flag != false){
        scanf("%s", UserNameInput);
        for (int i = 0; i < MAX_LENGTH; i++){
            // if characters don't match, break 
            if (username[i] != UserNameInput[i]){
                printf("not such username.\n please enter your username: ");
                break;
            }
            // if letters reached end, without triggering unmatch, then they match
            else if (password[i] == '\0'){
                flag = false;
                break;              // to break the loop
            }
        }
    }


    // password checking
    flag = true;
    printf("please enter your password: ");

    while (flag != false){
        scanf("%s", PassInput);

        for (int i = 0; i < MAX_LENGTH; i++){
            if (attempts == 4){
                printf("your reached maximum attempts.");
                flag = false;
                break;
            }
            // if characters don't match, break 
            else if ((password[i] != PassInput[i]) || username[i] != UserNameInput[i]){
                printf("NOT MATCHING\nplease enter the password again(%d/5): ", attempts + 1);
                attempts++;
                break;
            }
            // if letters reached end, without triggering unmatch, then they match
            else if (password[i] == '\0'){
                printf("Signed In Successfully\n");
                flag = false;
                break;
            }
        }
    }
}


int main() {
    char input[MAX_LENGTH];
    int decision, flag = true;

    while (flag != false){
        // take input of a username
        printf("sign-up enter 1, sign-in enter 2 (0 for break): ");
        scanf("%d", &decision);
        if (decision == 1)
            signUp();
        else if (decision == 2)
            signIn();
        else
            flag = false;
    }

    return 0;
}
