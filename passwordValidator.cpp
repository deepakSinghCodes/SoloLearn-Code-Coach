/*
 * ############################# Password Validation #############################
 * Copyright: Deepak Singh.
 * Date: May, 2021 
 * 
 * You're interviewing to join a security team. They want to see you build a 
 * password evaluator for your technical interview to validate the input.
 * 
 * Task:
 * Write a program that takes in a string as input and evaluates it as a valid 
 * password. The password is valid if it has at a minimum 2 numbers, 2 of the 
 * following special characters ('!', '@', '#', '$', '%', '&', '*'), and a length 
 * of at least 7 characters.
 * If the password passes the check, output 'Strong', else output 'Weak'.
 * 
 * Input Format:
 * A string representing the password to evaluate.
 * 
 * Output Format:
 * A string that says 'Strong' if the input meets the requirements, or 'Weak', if not.
 * 
 * Sample Input:
 * Hello@$World19
 * 
 * Sample Output:
 * Strong
 */
 
#include<iostream>
#include<string> 

using namespace std;

struct Weak: public exception{
    const char * what () const throw ()
    {
    	return "Weak";
    }
};

int main(int argc, char* argv[]){
/* 
 * Input: 1. password - This is a string
 * 
 * Output: The function returns whther the password is strong or weak
 * 
 * Methodology: The function first checks for the size of the password. Then,
 * it checks if it has 2 numbers and special characters in it.
 * 
 */ 
    try{
        int numCharac = 0;
        int numNumbers = 0;
	string password = "";
	cin >> password;
        if(password.size() <  7){
            throw Weak();
        }
        for(int i = 0; i < password.size(); i++){
            int asciiVal = int(password[i]);
            if((asciiVal == 33) || (asciiVal == 64) || ((asciiVal > 34) && (asciiVal < 39)) || (asciiVal == 42) ){
                numCharac = numCharac + 1;
            }
            if( (asciiVal > 47) and (asciiVal < 58) ){
                numNumbers = numNumbers + 1;
            }
        }
        if((numCharac < 2) || (numNumbers < 2)){
            throw Weak();
        }
        cout << "Strong";            
        return 0;
    }
    catch(Weak msg){     
        cout << msg.what();
    }
    catch(exception){
        cout << "Imperfect password";
    }
}    

