#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
############################## Driving License ##############################
Copyright: Deepak Singh.
Date: May, 2021 


You have to get a new driver's license and you show up at the office at the 
same time as 4 other people. The office says that they will see everyone in 
alphabetical order and it takes 20 minutes for them to process each new 
license. All of the agents are available now, and they can each see one 
customer at a time. How long will it take for you to walk out of the office 
with your new license?

Task
Given everyone's name that showed up at the same time, determine how long it 
will take to get your new license.

Input Format
Your input will be a string of your name, then an integer of the number of 
available agents, and lastly a string of the other four names separated by 
spaces.

Output Format
You will output an integer of the number of minutes that it will take to get 
your license.

Sample Input
'Eric'
2
'Adam Caroline Rebecca Frank'

Sample Output
40
"""
import math

def main(myName, noOfAgents, Others):
# Input: 
#    1. myName - This is a string. It is the users name
#    2. noOfAgents - This is an integer. It is the no. of agents at the time.
#    3. Others - This is a string. It is a list of four names separated by 
#               spaces.
#
# Output: The function returns an integer specifying the waiting time.
#
# Methodology: The function will first look for the first letter of names in 
# Others by looking for the alphabet after space. The position of users name
# is determined based on the ASCII value.
#
    try:
        myPos = 0
        myName = myName.strip()
        myAscii = ord(myName[0])
        if(myAscii > 90):
            myAscii = (myAscii - 97) + 65
        space = 32
        Others = Others.strip()
        countingSpaces = 0
        i = 0
        while(countingSpaces < 3):
            asciiVal = ord(Others[i])
            if(asciiVal > 90):
                asciiVal = (asciiVal - 97) + 65
            if( (i == 0) and (asciiVal < myAscii) ):
                myPos = myPos + 1
            if(ord(Others[i]) == 32):
                asciiVal = ord(Others[i+1])
                if(asciiVal > 90):
                    asciiVal = (asciiVal - 97) + 65
                countingSpaces = countingSpaces + 1
                if(asciiVal < myAscii):
                    myPos = myPos + 1
            i = i + 1
        waitingTime = int((20 * math.floor(myPos/noOfAgents)) + 20)
        print(waitingTime) 
    except:
        print("Wrong format of Input. It is string, integer and string")

if __name__ == "__main__":
    myName = input()
    noOfAgents = int(input())
    Others = input()
    main(myName, noOfAgents, Others)