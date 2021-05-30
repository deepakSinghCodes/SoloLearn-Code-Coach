#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
############################# Password Validation #############################
Copyright: Deepak Singh.
Date: May, 2021 

You're interviewing to join a security team. They want to see you build a 
password evaluator for your technical interview to validate the input.

Task:
Write a program that takes in a string as input and evaluates it as a valid 
password. The password is valid if it has at a minimum 2 numbers, 2 of the 
following special characters ('!', '@', '#', '$', '%', '&', '*'), and a length 
of at least 7 characters.
If the password passes the check, output 'Strong', else output 'Weak'.

Input Format:
A string representing the password to evaluate.

Output Format:
A string that says 'Strong' if the input meets the requirements, or 'Weak', if not.

Sample Input:
Hello@$World19

Sample Output:
Strong

"""
class Weak(Exception):
    pass

def main(password):
# Input: 1. password - This is a string
#
# Output: The function returns whther the password is strong or weak
#
# Methodology: The function first checks for the size of the password. Then,
# it checks if it has 2 numbers and special characters in it.
#

    try:
        numCharac = 0
        numNumbers = 0
        if(len(password) <  7):
            raise Weak
        for i in range(len(password)):
            if((ord(password[i]) == 33) or (ord(password[i]) == 64) or ((ord(password[i]) > 34) and (ord(password[i]) < 39)) or (ord(password[i]) == 42) ):
                numCharac = numCharac + 1
            if( (ord(password[i]) > 47) and (ord(password[i]) < 58) ):
                numNumbers = numNumbers + 1
        if((numCharac < 2) or (numNumbers < 2)):
            raise Weak
        print("Strong")            
    except Weak:     
        print("Weak")
    except:
        print("Not a string.")
    
    
if __name__ == "__main__":
    password = input()    
    main(password)
