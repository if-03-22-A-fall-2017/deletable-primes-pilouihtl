/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
 #include "deletable_primes.h"
  #include <math.h>
  unsigned long remove_digit(int index, unsigned long n)
  {
    int divisor = pow(10, index + 1);
    int a = pow(10, index);
    double result = n / divisor;
    result *= a;
    result += n % a;
    return result;
 }

 int get_ways(unsigned long p)
 {
   int ways =  0;
   int count = 0;
   int length = get_length(p);
   long number = 0;
   if(length < 2){
     if(check_prime(p)){
       return 1;
     }
     else {
       return 0;
     }
   }
   while(count < length){
     number = remove_digit(count, p);
     if(check_prime(number)){
       ways  += get_ways(number);
     }
     count++;
   }
   return ways;
 }
 int get_length(unsigned long n){
   int number = 1;
   int count = 0;
   while(number != 0){
      count++;
      number = n / pow(10, count);
   }
   return count;
 }
 bool check_prime(unsigned long n){
    long divison = 2;
    long number = n;

    while(number % divison != 0 && number != 1)
    {
        divison++;
    }
    if (number == divison)
    {
        return true;
    }
    return false;
 }
