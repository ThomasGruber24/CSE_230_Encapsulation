/***********************************************************************
 * Source File:
 *    MAIN
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Launches the unit tests - that is all!
 ************************************************************************/

#include "test.h"
#include "position.h"

double Position::metersFromPixels = 40.0;

 /************************************
  * MAIN
  * There can be only one!
  ************************************/
int main()
{
   // run the test code.
   testRunner();

   // return success
   return 0;
}