# -*- coding: utf-8 -*-
"""
You have two friends who are speaking Pig Latin to each other! Pig Latin is 
the same words in the same order except that you take the first letter of 
each word and put it on the end, then you add 'ay' to the end of that. 
("road" = "oadray") 

Task
Your task is to take a sentence in English and turn it into the same 
sentence in Pig Latin! 

Input Format 
A string of the sentence in English that you need to translate into Pig 
Latin. (no punctuation or capitalization)

Output Format 
A string of the same sentence in Pig Latin.

E.g.
"nevermind youve got them"
to
"evermindnay ouveyay otgay hemtay"
"""


def main(origString):
# Input: 
# 1. origString - takes a string as input    
# Output:
# The function returns a string in pig latin   
# Methodology:
# A single word intput is treated differently, but for others based on the 
# space we will store the first letter and make changes to the current word
#
    try:
        origString = origString.strip()
        if(len(origString) == 1):
            outputString = "ay" + origString
        else:
            outputString = ""
            firstLetter = origString[0]
            for i in range(1,len(origString)):
                if(origString[i-1] == " "):
                    firstLetter = origString[i]
                elif(origString[i] != " "):
                    outputString = outputString + origString[i]
                else:
                    outputString = outputString + firstLetter + "ay "
                
            outputString = outputString + firstLetter + "ay"
        print(outputString)           
    except ValueError:
        print("Input is not string.")

if __name__ == "__main__" :
    origString = input("Enter the sentence: ")
    main(origString)
