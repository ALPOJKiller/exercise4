#include <stdio.h>
#define bool char
#define true 1
#define false 0
bool is_leap_year(unsigned year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    else
        return false;
}
unsigned month_to_day(unsigned month, bool is_leap) {
    unsigned ret = 0;
    int day_in_month[] = {0, 31, is_leap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (unsigned i = 0; i < month; ++i) {
        ret += day_in_month[i];
    }
    return ret;
}
int main() {
  unsigned year,month,day;
  unsigned case_count = 0;
  while(scanf("%u %u %u",&year,&month,&day) != EOF) {
    printf("Case %d: ",++case_count);
    printf("%02u/%02u/%04u, %u\n",month,day,year,month_to_day(month,is_leap_year(year)) + day);
  }
  return 0;
}
