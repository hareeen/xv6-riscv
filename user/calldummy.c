#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  int res = dummy();
  printf("dummy called; result: %d\n", res);

  exit(0);
}
