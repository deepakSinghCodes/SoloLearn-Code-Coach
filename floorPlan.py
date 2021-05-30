#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
################################ Floor plan ################################
Copyright: Deepak Singh.
Date: May, 2021 

You are in charge of security at a casino, and there is a thief who is trying 
to steal the casino's money!  Look over the security diagrams to make sure 
that you always have a guard between the thief and the money!There is one 
money location, one thief, and any number of guards on each floor of the 
casino.

Task: Evaluate a given floor of the casino to determine if there is a guard 
between the money and the thief, if there is not, you will sound an alarm.

Input Format:A string of characters that includes $ (money), T (thief), and G 
(guard), that represents the layout of the casino floor.  Space on the casino 
floor that is not occupied by either money, the thief, or a guard is 
represented by the character x.

Output Format: A string that says 'ALARM' if the money is in danger or 'quiet' 
if the money is safe.

Sample Input: xxxxxGxx$xxxT
Sample Output: ALARM
"""
class ALARM(Exception):
    pass

def main(floorPlan):
# Input: 1. floorPlan - This is a string
#
# Output: The function either raises an alarm or stays silent
#
# Methodology: There are two possibility for alarm. Either the thief comes 
# first on the floorplan or if the jewel comes first. So, we keep the most 
# recent occurence index for T(Thief), G(Guard) and J (Jewel). On each 
# occurence of T and J, we will check if G is between them or not. If not, we
# will raise an alarm. Initialisation with -1 will help in keeping the two 
# cases separate.
#
#    
    try:
        lastT = -1
        lastG = -1
        lastJ = -1
        for i in range(len(floorPlan)):    
            if(ord(floorPlan[i]) == 36):
                lastJ = i
                if(lastT != -1):
                    if(lastG == -1):
                        raise ALARM
                    diff1 = lastG - lastT
                    diff2 = lastG - lastJ
                    if((diff1*diff2) > 0):
                        raise ALARM
            elif(ord(floorPlan[i]) == 84):
                lastT = i
                if(lastJ != -1):
                    if(lastG == -1):
                        raise ALARM
                    diff1 = lastG - lastT
                    diff2 = lastG - lastJ
                    if((diff1*diff2) > 0):
                        raise ALARM
            elif(ord(floorPlan[i]) == 71):
                lastG = i
        print("quiet")
    except ALARM:
        print("ALARM")
    except:
        print("Imperfect Floor plan")
        
        
        
if __name__ == "__main__":
    floorPlan = input()
    main(floorPlan)        
        
        
