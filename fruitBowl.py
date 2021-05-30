#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
################################ Fruit Bowl ################################
Copyright: Deepak Singh.
Date: May, 2021

You have a bowl on your counter with an even number of pieces of fruit in 
it. Half of them are bananas, and the other half are apples. You need 3 
apples to make a pie. 

Task 
Your task is to evaluate the total number of pies that you can make with 
the apples that are in your bowl given to total amount of fruit in the 
bowl.

Input Format
An integer that represents the total amount of fruit in the bowl.

Output Format
An integer representing the total number of whole apple pies that you can 
make. Thw two exceptions declared here lead to an error in the sololearn 
tests, so they have been commented out.

"""
class notEven(Exception):
    pass
class notPositive(Exception):
    pass

def main(numOfFruits):
# Input: 
# 1. numOfFruits - Number of fruits in the bowl    
# Output:
# The function returns the number of pies that can be made.   
# Methodology:
# The function first checks if the numberofFruits is even. It then finds
# the quotient after division by 3. 
#
    try:
#        if((numOfFruits <= 0)):
#            raise notPositive("The input is not a whole number")
#        if((numOfFruits%2 != 0)):
#            raise notEven("The input is not an even number")
        noOfPies = numOfFruits//6
        print(noOfPies)           
    except ValueError:
        print("Input is not a number.")

if __name__ == "__main__" :
    numOfFruits = int(input("Enter the number of fruits in the bowl: "))
    main(numOfFruits)
