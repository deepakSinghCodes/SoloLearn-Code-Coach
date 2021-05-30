#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
########################### Average Word Length ###########################
Copyright: Deepak Singh.
Date: May, 2021

You are in a college level English class, your professor wants you to 
write an essay, but you need to find out the average length of all the 
words you use. It is up to you to figure out how long each word is and to 
average it out.

Task: 
Takes in a string, figure out the average length of all the words and 
return a number representing the average length. Remove all punctuation. 
Round up to the nearest whole number.

Input Format: 
A string containing multiple words.

Output Format: 
A number representing the average length of each word, rounded up to the 
nearest whole number.

Sample Input: 
this phrase has multiple words

Sample Output: 
6


"""

import math

def main(origString):
# Input: 
# 1. origString - takes a string as input    
# Output:
# The function returns the average length rounded upto a whole length   
# Methodology:
# First the number of words are calculated by removing starting and ending
# spaces. The spaces from the paragraph are then removed. The average  
# length is then rounded up. Only alphabets are counted in length.
#
    try:
        origString = origString.strip()
        numOfWords = 1
        i = 0
        length = 0
        while(i < len(origString)):
            asciiVal = ord(origString[i])
            if( ((asciiVal >= 65) and (asciiVal <= 90)) or ((asciiVal >= 97) and (asciiVal <= 122)) ):
                length = length + 1
            if(asciiVal == 32):    
                numOfWords = numOfWords + 1
            i = i + 1    
        avgLength = math.ceil(length/numOfWords)
        print(avgLength)           
    except ValueError:
        print("Input is not string.")

if __name__ == "__main__" :
    origString = input("Enter the sentence: ")
    main(origString)
