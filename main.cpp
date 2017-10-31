#include <iostream>
using namespace std;

//exceptions for any kind of error
void exceptions(string source, string destination){
 
int counter;
int sourceNum;
int desNum;

//loops through all the numbers in the IP
for(int i =0; i < source.length(); i++)
    {
        //checks to see if either of the IPs are not at a digit
        if((!isdigit(source[i])) || (!isdigit(destination[i])))
        {
            //checks to see which one is a period
            if(!isdigit(source[i]))
            {
                //checks the accumulating number
                if(sourceNum >= 0 && sourceNum <= 255){
                    //sets the accumulating number to 0
                    sourceNum = 0;
                }
                else
                {
                    //throws error based off the accumulating number
                    throw string("Make Sure Your IP NUmbers Are Between 0 and 255");
                } 
            }
            else
            {
                if(desNum >= 0 && desNum <= 255){
                    desNum = 0;
                }
                else
                {
                    throw string("Make Sure Your IP NUmbers Are Between 0 and 255");
                }
            }
            
            //if its a period it adds to the counter to make sure we have the right amount of periods
            if((source[i] == '.') || (destination[i] == '.'))
            {
                counter = counter + 1;
                if(counter > 6){
                    throw string("Too Many Periods");
                }
            }
            else
            {
                //error for anything thats not a period or a number
                throw string("Make Sure You Have Only Numbers and Periods In Your IPs");
                
            }
        } 
        else
        {
            //adds number to an accumulating number
            sourceNum = sourceNum + source[i];
            desNum = desNum + destination[i];
        }
    }
}


int main(void) {

string sourceIpAdd = "";
string destinationIpAdd = "";
 
//gets both IPs
cin >> sourceIpAdd;
cin >> destinationIpAdd;

//tries to run for exceptions
try
{
    exceptions(sourceIpAdd, destinationIpAdd);
    cout << "Valid IP Header" << endl;
}
catch(string &exc){
cout << "Invalid IP Header - " << exc << endl;
}

}

