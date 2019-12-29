#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char* argv[])
{
  if (argc < 2) {
    fprintf(stdout, "%s Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR);
    fprintf(stdout, "Usage: %s number\n", argv[0]);
    return 1;
  }
  double inputValue = atof(argv[1]);
  double outputValue = 0;
  if (inputValue >= 0) {
    #ifdef USE_MYMATH
      outputValue = mysqrt(inputValue);
      printf("USE MYMATH LIB\r\n");
    #else
      outputValue = sqrt(inputValue);
      printf("NO USE MYMATH LIB\r\n");
    #endif
  }
  fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
  return 0;
}

int main_02 (int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout,"%s Version %d.%d\n",
                argv[0],
                Tutorial_VERSION_MAJOR,
                Tutorial_VERSION_MINOR);
        fprintf(stdout,"Usage: %s number\n",argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    fprintf(stdout,"The square root of %g is %g\n",
        inputValue, outputValue);
    return 0;
}



int main_01 (int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout,"Usage: %s number\n",argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    fprintf(stdout,"The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}