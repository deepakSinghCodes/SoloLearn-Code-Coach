/*
 * ############################## Driving License ##############################
 * Copyright: Deepak Singh.
 * Date: May, 2021 
 * 
 * You have to get a new driver's license and you show up at the office at the 
 * same time as 4 other people. The office says that they will see everyone in 
 * alphabetical order and it takes 20 minutes for them to process each new 
 * license. All of the agents are available now, and they can each see one 
 * customer at a time. How long will it take for you to walk out of the office 
 * with your new license?
 * 
 * Task
 * Given everyone's name that showed up at the same time, determine how long it 
 * will take to get your new license.
 * 
 * Input Format
 * Your input will be a string of your name, then an integer of the number of 
 * available agents, and lastly a string of the other four names separated by 
 * spaces.
 * 
 * Output Format
 * You will output an integer of the number of minutes that it will take to get 
 * your license.
 * 
 * Sample Input
 * 'Eric'
 * 2
 * 'Adam Caroline Rebecca Frank'
 * 
 * Sample Output
 * 40
 */
 
#include<iostream>
#include<string> 

using namespace std;

int main(int argc, char* argv[]){
/* 
 * Input: 
 * 1. myName - This is a string. It is the users name
 * 2. noOfAgents - This is an integer. It is the no. of agents at the time.
 * 3. Others - This is a string. It is a list of four names separated by 
 *              spaces.
 * 
 * Output: The function returns an integer specifying the waiting time.
 * 
 * Methodology: The function will first look for the first letter of names in 
 * Others by looking for the alphabet after space. The position of users name
 * is determined based on the ASCII value.
 * 
 */   
    try{
        int myPos = 0, noOfAgents = 0, myAscii = 0, space = 32, countingSpaces = 0, i = 0;
	string myName = "", Others = "", number = "";
	string first = "", second = "", third = "", fourth = "";
	cin >> myName;
	cin >> number;
	cin >> first;
	cin >> second;
	cin >> third;
	cin >> fourth;
	Others = first + " " + second + " " + third + " " + fourth;
//	getline(cin, Others);
	noOfAgents = stoi(number);
	//Clear starting and ending whitespaces
	if(int(myName[0]) == 32){
	    myName = myName.substr(1, myName.size()-1);	
	}
	if(int(myName[myName.size()-1]) == 32){
	    myName = myName.substr(0, myName.size()-1);;	
	}

	if(int(Others[0]) == 32){
	    Others = Others.substr(1, Others.size()-1);	
	}
	if(int(Others[Others.size()-1]) == 32){
	    Others = Others.substr(0, Others.size()-1);;	
	}

        myAscii = int(myName[0]);
        if(myAscii > 90){
            myAscii = (myAscii - 97) + 65;
        }

        while(countingSpaces < 3){
            int asciiVal = int(Others[i]);
            if(asciiVal > 90){
                asciiVal = (asciiVal - 97) + 65;
            }
            if( (i == 0) && (asciiVal < myAscii) ){
                myPos = myPos + 1;
            }

            if(int(Others[i]) == 32){
                asciiVal = int(Others[i+1]);
                if(asciiVal > 90){
                    asciiVal = (asciiVal - 97) + 65;
                }
                countingSpaces = countingSpaces + 1;

                if(asciiVal < myAscii){
                    myPos = myPos + 1;
                }
            }        
            i = i + 1;
        }
        int waitingTime = int((20 * int(myPos/noOfAgents)) + 20);
        cout << waitingTime;
        return 0; 
    }    
    catch(exception){
        cout << "Wrong format of Input. It is string, integer and string";
    }
}        
        
        
  
        
        
