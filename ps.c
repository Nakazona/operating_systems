#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "uproc.h"
int
main(void)
{
  struct uproc * table;
  int max = 30;
  int ret;
  table = malloc(sizeof(struct uproc)* max);
  ret = getprocs(max, table);
  printf(1, "\nPID\tName\t\tUID\tGID\tPPID\tElapsed\tCPU\tState\tSize\n");
  for(int i = 0; i < ret && i < 64; ++i)
  {
    
    int el_remainder = table[i].elapsed_ticks % 1000;
    int elapsed = table[i].elapsed_ticks / 1000;
    char *el_char;
    if(el_remainder < 10)
      el_char = "00";
    else if(el_remainder < 100)
      el_char = "0";
    else
      el_char = "";
    int cpu_remainder = table[i].CPU_total_ticks % 1000;
    int cpu_total = table[i].CPU_total_ticks / 1000;
    char *cpu_char;
    if(cpu_remainder == 0)
      cpu_char = "000";
    else if(cpu_remainder < 10)
      cpu_char = "00";
    else if(cpu_remainder < 100)
      cpu_char = "0";
    else
      cpu_char = "";

    printf(1, "%d\t%s\t\t%d\t%d\t%d\t%d.%s%d\t%d.%s%d\t%s\t%d\t\n", table[i].pid, table[i].name, table[i].uid, table[i].gid, table[i].ppid, elapsed, el_char, el_remainder, cpu_total, cpu_char, cpu_remainder, table[i].state, table[i].size);
  }
  free(table);
  exit();
}
#endif
