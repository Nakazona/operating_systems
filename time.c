#ifdef CS333_P2
#include "types.h"
#include "user.h"
int
main(int argc, char *argv[])
{
  --argc;
  if(argc >= 1)
  {
    int to_combine = argc;
    char * a;
    char * b;
    b  = malloc(sizeof(argv[to_combine]));
    int size = strlen(argv[to_combine]);
    int i = 0;
    while(i < size)
    {
      b[i] = argv[to_combine][i];
      ++i;
    }
    --to_combine;

    while(to_combine != 1)
    {
      a = malloc(sizeof(b)+sizeof(argv[to_combine])+sizeof(char));
      size = strlen(b);
      i = 0;
      while(i < size)
      {
        a[i] = b[i];
        ++i;
      }
      int v_size = strlen(argv[to_combine]);
      a[i] = ' ';
      ++i;
      while((i-size)-1 < v_size)
      {
        a[i] = argv[to_combine][i];
        ++i;
      }
      free(b);
      b = malloc(sizeof(a));
      strcpy(b, a);
      free(a);
      --to_combine;
    }

    uint start_ticks = uptime();
    exec(argv[1], &b);
    uint end_ticks = uptime();
    uint total_ticks = end_ticks - start_ticks;
    int remainder = total_ticks % 1000;
    int elapsed = total_ticks / 1000;
    char *el_char;
    if(remainder < 10)
      el_char = "0";
    else
      el_char = "";
    printf(1, "%s ran in %d.%s%d seconds\n", argv[1], elapsed, el_char, remainder);
  }
  else
  {
    char ** args = malloc(sizeof(char**));
    uint start_ticks = uptime();
    exec(argv[1], args);
    uint end_ticks = uptime();
    uint total_ticks = end_ticks - start_ticks;
    int remainder = total_ticks % 1000;
    int elapsed = total_ticks / 1000;
    char *el_char;
    if(remainder < 10)
      el_char = "0";
    else
      el_char = "";
    printf(1, "%s ran in %d.%s%d seconds\n", argv[0], elapsed, el_char, remainder);
  }
  
  exit();
}

#endif
