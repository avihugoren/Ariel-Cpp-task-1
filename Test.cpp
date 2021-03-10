/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Avihu Goren>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
#include <random>
#include <math.h> 
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

int NumLength(int num)//return the digit length of num
{
    int counter = 0 ;
     while(num != 0)
        {
            counter ++;
            num = num/10;
        }
    return counter;
}
int GiveMeNumLen(int length,bool good)//if good = true return good number with length of 8 and digits betwen 1-4 else if good == false return same number but negative
{
    int sum = 0;
    int digit = 0;
    for (int i = 0 ; i < length; i++)
    {
        digit = rand() % 4 + 1;//good digit is 1-4 
        sum += digit * pow(10,i);
    }
    if (good)
        return sum;
    return sum * -1;
}
int GiveMeBadNum(int digit_place)//give number with length of 8 and one digit is not between 1-4 this digit place is 7 - digit_place
{
    int my_rand = 0 ; 
    int num = 0 ;
    for (int j = 0 ; j < 8 ; j++)
        {
            num = 0;
            if (j != digit_place)
                my_rand = rand() % 4 + 1;
            else 
                my_rand = rand() % 5 + 5;
            my_rand = my_rand *pow(10,j);
            num += my_rand;         
        }
    return num;
}


TEST_CASE("Good snowman code 33232124") {
    CHECK((snowman(33232124)) == ("   -   \n  /_\\  \n\\(o_O)\n (] [)> \n (   )"));
    /* Add more checks here */
}
TEST_CASE("Good snowman code 23232124") {
    CHECK((snowman(23232124)) == ("  ---  \n ..... \n\\(o_O) \n (] [)>\n (   )"));
}
TEST_CASE("Good snowman code 11111111") {
    CHECK((snowman(11111111)) == ("       \n  _===_ \n (.,.) \n<( : )>\n ( : ) \n"));
} 
TEST_CASE("Good snowman code 22222222") {
    CHECK((snowman(22222222)) == ("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \")\n"));
}
TEST_CASE("Good snowman code 33333333") {
    CHECK((snowman(33333333)) == ("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___) \n"));
}
TEST_CASE("Good snowman code 44444444") {
    CHECK((snowman(44444444)) == ("  ___  \n (_*_) \n (- -) \n (   )   \n (   ) \n"));

}
TEST_CASE("Good snowman code : hat") 
{
    CHECK((snowman(14444444)) == ("       \n _===_ \n (- -) \n (   )   \n (   ) \n"));
    CHECK((snowman(24444444)) == ("  ___  \n ..... \n (- -) \n (   )   \n (   ) \n"));
    CHECK((snowman(34444444)) == ("   _   \n  /_\\  \n (- -) \n (   )  \n (   ) \n"));
}
TEST_CASE("Good snowman code nose") 
{
    CHECK((snowman(41444444)) == ("  ___  \n (_*_) \n (-,-) \n (   )   \n (   ) \n"));
    CHECK((snowman(42444444)) == ("  ___  \n (_*_) \n (-.-) \n (   )   \n (   ) \n"));
    CHECK((snowman(43444444)) == ("  ___  \n (_*_) \n (-_-) \n (   )   \n (   ) \n"));
}
TEST_CASE("Good snowman code right eye") 
{
    CHECK((snowman(44144444)) == ("  ___  \n (_*_) \n (. -) \n (   )   \n (   ) \n"));
    CHECK((snowman(44244444)) == ("  ___  \n (_*_) \n (o -) \n (   )   \n (   ) \n"));
    CHECK((snowman(44344444)) == ("  ___  \n (_*_) \n (0 -) \n (   )   \n (   ) \n"));
}
TEST_CASE("Good snowman code left eye") 
{
    CHECK((snowman(44414444)) == ("  ___  \n (_*_) \n (- .) \n (   )   \n (   ) \n"));
    CHECK((snowman(44424444)) == ("  ___  \n (_*_) \n (- o) \n (   )   \n (   ) \n"));
    CHECK((snowman(44434444)) == ("  ___  \n (_*_) \n (- 0) \n (   )   \n (   ) \n"));
}
TEST_CASE("Good snowman code right hand") 
{
    CHECK((snowman(44441444)) == ("  ___  \n (_*_) \n (- -) \n<(   )   \n (   ) \n"));
    CHECK((snowman(44442444)) == ("  ___  \n (_*_) \n\\(- -) \n (   )   \n (   ) \n"));
    CHECK((snowman(44443444)) == ("  ___  \n (_*_) \n (- -) \n/(   )   \n (   ) \n"));
}
TEST_CASE("Good snowman code right hand") 
{
    CHECK((snowman(44444144)) == ("  ___  \n (_*_) \n (- -) \n (   )>  \n (   ) \n"));
    CHECK((snowman(44444244)) == ("  ___  \n (_*_) \n (- -)/ \n (   )   \n (   ) \n"));
    CHECK((snowman(44444344)) == ("  ___  \n (_*_) \n (- -) \n (   )\\\n (   ) \n"));
}
TEST_CASE("Good snowman code torso") 
{
    CHECK((snowman(44444414)) == ("  ___  \n (_*_) \n (- -) \n ( : ) \n (   ) \n"));
    CHECK((snowman(44444424)) == ("  ___  \n (_*_) \n (- -) \n (] [) \n (   ) \n"));
    CHECK((snowman(44444434)) == ("  ___  \n (_*_) \n (- -) \n (> <) \n (   ) \n"));
}
TEST_CASE("Good snowman code base") 
{
    CHECK((snowman(44444441)) == ("  ___  \n (_*_) \n (- -) \n (   ) \n ( : ) \n"));
    CHECK((snowman(44444442)) == ("  ___  \n (_*_) \n (- -) \n (   ) \n (\" \") \n"));
    CHECK((snowman(44444443)) == ("  ___  \n (_*_) \n (- -) \n (   ) \n (___) \n"));
}




  
TEST_CASE("Bad snowman code : neagtive input") {
    for (int i = 0 ; i < 100 ; i++)
    CHECK_THROWS(snowman(GiveMeNumLen(8,false)));//function that give negative int with length of 8
}
TEST_CASE("Bad snowman code one digit is not between 1-4") {
    int num = 0;
    int options [8]={0};
    int digit = 0;
    for (int i = 0 ; i < 100 ; i++)
    {
        digit = rand() % 8; //random number between 0-7
        num = GiveMeBadNum(digit);
        options[digit] += 1; //update that the digit in place digit have been checked 
        CHECK_THROWS(snowman(num));   
    }
    //checks that each digit got cheaked at leat once if not check it 10 times
    for (int i = 0 ; i < 8 ; i++)
        if(options[i] == 0)
            for (int j = 0 ; j < 10 ; j++)
                CHECK_THROWS(snowman(GiveMeBadNum(i)));
}
TEST_CASE("Bad snowman code number is not 8 digit long") 
{
  const int under_eight_options = 7;
  const int over_eight_option = 2;
  int options_under [under_eight_options]={0};//to keep track that all the option gets check at least once 
  int options_over [over_eight_option]={0};
  for (int i = 0 ; i < 100 ; i++)
  {
    //smaller length then 8
    int digits_length_under = rand() % 7 + 1;
    int small_num = GiveMeNumLen(digits_length_under,true);//give me random int with  0<length <8 and each digit is between 1-4
    options_under[NumLength(small_num)-1] += 1;//mark that number with that length has been checked
    CHECK_THROWS(snowman(small_num));
    //bigger  length then 8
    int digits_length_over = rand() % 2 + 9;
    int big_num = GiveMeNumLen(digits_length_over,true);//give me random int with  8<length <11 and each digit is between 1-4
    options_under[NumLength(big_num)-9] += 1;
    CHECK_THROWS(snowman(big_num));
  }
  //checks that all the options of under 8 been checked at least one if not so check it we 10 random numbers 
  for (int i = 0 ; i < under_eight_options ;i++)
      if(options_under[i] == 0)
        for(int j=0 ; j < 10 ; j++)
         CHECK_THROWS(snowman(GiveMeNumLen(i+1,true)));
  //checks that all the options of over 8 been checked at least one if not so check it we 10 random numbers 
  for (int i = 0 ; i < over_eight_option ;i++)
      if(options_over[i] == 0)
        for(int j=0 ; j < 10 ; j++)
         CHECK_THROWS(snowman(GiveMeNumLen(i+9,true)));
}

