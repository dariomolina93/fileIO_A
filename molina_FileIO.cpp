/* Name: Dario Molina
 10/21/15
 Description: Write a program that will utilize a text input file( gba.txt) and compute the listed specifications provided.  

a) Determine the average number of characters per word. Print result to "result.txt".

b) Provide a count of the number of words of each length. 

c) Calculate the total number of words in the input file.  Print result to "result.txt".

d) Capitalize all letter in the file.  Write the results to "capitalize.txt".

e) Change the first letter of each word from original file to uppercase. Write results to "uppercase.txt".
*/
#include<iostream>// cin, cout
#include<fstream>// write and received data from file
#include<string>// be able to use strings
#include<cstdlib>// if file input or output fail, exit program.
using namespace std;

int main()
{
  int sumLength = 0, count = 0, average = 0;
  int length1 = 0,length2 = 0, length3 = 0;
  int length4 = 0,length5 = 0, length6 = 0;
  int length7 = 0,length8 = 0, length9 = 0;
  int length10 = 0, length11 = 0;
  char caps, caps2;
  string strA, fullText, fullText2;
  string result, result2;
  ifstream fin;// pipe to input data to the program from file.txt
  ofstream foutA;// pipe to output data from program to new file
  ofstream foutB;// pipe to output data from program to new file
  ofstream foutC;// pipe to output data from program to new file
  
   fin.open("gba.txt");// open the the input file source
   foutA.open("results.txt");// create and open a file where output is going to 
   foutB.open( "capitalize.txt");// create and open a file where output is going to 
   foutC.open( "uppercase.txt");
   
   if( fin.fail())// if file couldn't be open display error and exit program
   {
     cout << " Opening file failed." << endl;
     exit(1);
   }

   if(foutA.fail())// if file couldn't be created nor opened display error message and exit the program. Same principle for the next two files.
   {
     cout << " Error sending out file." << endl;
     exit(1);
   }
   
   if(foutB.fail())
   {
     cout << " Error sending out file." << endl;
     exit(1);
   }
   
   if(foutC.fail())
   {
     cout << " Error sending out file." << endl;
     exit(1);
   }

  while( fin >> strA)// the loop will continue as long as there is a word in  the file.  It brings one word per iteration.
 {
   
   sumLength = sumLength + strA.length();// sums up how many characters are there per word. Add them all up at end of file
   count++;// how many words have been passed in
   
    switch ( strA.length() )// takes in the length of the word, increase counter for that.
    {
      case 1: length1++; break;// if the length of the word is 1, keept count of that.
      
      case 2: length2++; break;// if the length of the word is 2, increase counter for that.  Same holds place for the rest of the switch cases.
       
      case 3: length3++; break;
       
      case 4: length4++; break;
   
      case 5: length5++; break;
        
      case 6: length6++; break;
        
      case 7: length7++; break;
        
      case 8: length8++; break;
      
      case 9: length9++; break;
        
      case 10: length10++; break;
        
      default: length11++; break;
  
    }
     
     
       for ( int i = 0; i < strA.length(); i++)// for loop that goes through each character of the word.
      {
      
         caps =  strA.at(i);// each character at a time is assigned to caps.
         caps = toupper( caps);// the char is being capitilized by the upper function and reassigned to caps.
         result = result + caps;// each capital letter is assinged to result
         
      }
      
        fullText =  fullText + result;// the capital word in result is not added to fullText which will hold all the words.
   
        result = " ";// result is being emptied to carry the next word in the next iteration
        
        
      for ( int j = 0; j < strA.length(); j++)// for loop that will go through each word
      {
       
         if (j == 0) // first letter of each word
          {
            caps2 = strA.at(j);// assign that char to caps2
            caps2 = toupper( caps2);// capitalize the char and reassig it to caps2
            
            result2 = result2 + caps2;// store caps2 in result2
          
          }
          
          else // every other letter
            {
              result2 = result2 + strA.at(j);// the rest of the chars of the words are being added to result two which already has the first capital letter.
            
            }
         
        
      }
       
      fullText2 = fullText2 + result2;// stores the modifed word into fullText2; fullText2 keeps record of all the words that will be modified in the file.
      result2 = " ";// empty the string so it does the same process for the next iteration
   
 }
 
  average = sumLength / count;
  
  foutA << "\n Part C. \n";// display output into file results.txt
  foutA << " Average number of characters for gba.txt is " << average << endl << endl;
  
  foutA << " Part D, count the number of words of each length.\n"
       << " There are " << length1 << " words of length 1.\n"
       << " There are " << length2 << " words of length 2.\n"
       << " There are " << length3 << " words of length 3.\n"
       << " There are " << length4 << " words of length 4.\n"
       << " There are " << length5 << " words of length 5.\n"
       << " There are " << length6 << " words of length 6.\n"
       << " There are " << length7 << " words of length 7.\n"
       << " There are " << length8 << " words of length 8.\n"
       << " There are " << length9 << " words of length 9.\n"
       << " There are " << length10 << " words of length 10.\n"
       << " There are " << length11<< " words of length 11.\n"; 
      
  foutA << " \nPart E, count then umber of words in the input file.\n"
       << " There are " << count << " words in the input file.\n\n";
  foutA << endl;
       
  foutB << " Part F, write gba.txt with all Capitla letters.\n\n"// display out in capitalize.txt
       << fullText << " " ;
  foutB << endl;
    
    foutC << " Part G, write gba.txt with the first letter of each word capitalized.\n\n"// display out in uppercase.txt
          << fullText2 << " ";
    foutC << endl;
       

  fin.close();// close files at end of program to prevent corruption
  foutA.close();
  foutB.close();
  foutC.close();
return 0; 
}
