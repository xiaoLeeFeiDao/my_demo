#include "main.h"

int main()
{
#if (CPP_LEARN == TRUE)
  CppLearn();
#endif

#if (DEMO == TRUE)
  Demo();
#endif

  return 0;
}
