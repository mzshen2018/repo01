/***********************************************************************
  Mingzuo Shen (mshen); Sat Dec 30 22:49:45 1995; rpisun1.mdacc.tmc.edu

  mktime()
  when certain member of struct tm is not set, mktime() makes guesses
  prttime() does not print timezone name
  possible solution: look at the TZ environment variable
***********************************************************************/

#include <stdio.h>
#include <time.h>

void prttime(struct tm vtm);


int
main(void)
{
  time_t vtime;
  struct tm vtm;
  struct tm vtm0;
  struct tm vtm1;
  struct tm vtm2;
  struct tm vtm3;
  struct tm vtm4;
  struct tm vtm5;


  vtime = time((long int *)0);
  vtm = *localtime(&vtime);
  fprintf(stdout, "Current local time    : ");
  prttime(vtm);

  fprintf(stdout, "mktime guesses seconds: ");
  /* vtm1.tm_sec = vtm.tm_sec; */
  vtm1.tm_min = vtm.tm_min;
  vtm1.tm_hour = vtm.tm_hour;
  vtm1.tm_mday = vtm.tm_mday;
  vtm1.tm_mon = vtm.tm_mon;
  vtm1.tm_year = vtm.tm_year;
  /* vtm1.tm_wday = vtm.tm_wday; */
  /* vtm1.tm_yday = vtm.tm_yday; */
  vtm1.tm_isdst = vtm.tm_isdst;
  vtime = mktime(&vtm1);
  vtm0 = *localtime(&vtime);
  prttime(vtm0);

  fprintf(stdout, "mktime guesses minutes: ");
  vtm2.tm_sec = vtm.tm_sec;
  /* vtm2.tm_min = vtm.tm_min; */
  vtm2.tm_hour = vtm.tm_hour;
  vtm2.tm_mday = vtm.tm_mday;
  vtm2.tm_mon = vtm.tm_mon;
  vtm2.tm_year = vtm.tm_year;
  /* vtm2.tm_wday = vtm.tm_wday; */
  /* vtm2.tm_yday = vtm.tm_yday; */
  vtm2.tm_isdst = vtm.tm_isdst;
  vtime = mktime(&vtm2);
  vtm0 = *localtime(&vtime);
  prttime(vtm0);

  fprintf(stdout, "mktime guesses hour   : ");
  vtm3.tm_sec = vtm.tm_sec;
  vtm3.tm_min = vtm.tm_min;
  /* vtm3.tm_hour = vtm.tm_hour; */
  vtm3.tm_mday = vtm.tm_mday;
  vtm3.tm_mon = vtm.tm_mon;
  vtm3.tm_year = vtm.tm_year;
  /* vtm3.tm_wday = vtm.tm_wday; */
  /* vtm3.tm_yday = vtm.tm_yday; */
  vtm3.tm_isdst = vtm.tm_isdst;
  vtime = mktime(&vtm3);
  vtm0 = *localtime(&vtime);
  prttime(vtm0);

  fprintf(stdout, "mktime guesses day    : ");
  vtm4.tm_sec = vtm.tm_sec;
  vtm4.tm_min = vtm.tm_min;
  vtm4.tm_hour = vtm.tm_hour;
  /* vtm4.tm_mday = vtm.tm_mday; */
  vtm4.tm_mon = vtm.tm_mon;
  vtm4.tm_year = vtm.tm_year;
  /* vtm4.tm_wday = vtm.tm_wday; */
  /* vtm4.tm_yday = vtm.tm_yday; */
  vtm4.tm_isdst = vtm.tm_isdst;
  vtime = mktime(&vtm4);
  vtm0 = *localtime(&vtime);
  prttime(vtm0);

  fprintf(stdout, "mktime guesses month  : ");
  vtm5.tm_sec = vtm.tm_sec;
  vtm5.tm_min = vtm.tm_min;
  vtm5.tm_hour = vtm.tm_hour;
  vtm5.tm_mday = vtm.tm_mday;
  /* vtm5.tm_mon = vtm.tm_mon; */
  vtm5.tm_year = vtm.tm_year;
  /* vtm5.tm_wday = vtm.tm_wday; */
  /* vtm5.tm_yday = vtm.tm_yday; */
  vtm5.tm_isdst = vtm.tm_isdst;
  vtime = mktime(&vtm5);
  vtm0 = *localtime(&vtime);
  prttime(vtm0);

  return(0); 
}

char monnames[12][4] =
{
  "Jan",
  "Feb",
  "Mar",
  "Apr",
  "May",
  "Jun",
  "Jul",
  "Aug",
  "Sep",
  "Oct",
  "Nov",
  "Dec"
};

char wdaynames[7][4] =
{
  "Sun",
  "Mon",
  "Tue",
  "Wed",
  "Thu",
  "Fri",
  "Sat",
};

void
prttime(struct tm vtm)
{
  /* fprintf(stdout, "second:         %d\n", vtm.tm_sec); */
  /* fprintf(stdout, "minute:         %d\n", vtm.tm_min); */
  /* fprintf(stdout, "hour:           %d\n", vtm.tm_hour); */
  /* fprintf(stdout, "day of month:   %d\n", vtm.tm_mday); */
  /* fprintf(stdout, "month:          %d\n", vtm.tm_mon); */
  /* fprintf(stdout, "year:           %d\n", vtm.tm_year); */
  /* fprintf(stdout, "day of week:    %d\n", vtm.tm_wday); */
  /* fprintf(stdout, "day of year:    %d\n", vtm.tm_yday); */
  /* fprintf(stdout, "daytime saving: %d\n", vtm.tm_isdst); */
  fprintf(stdout, "%s ", wdaynames[vtm.tm_wday]);
  fprintf(stdout, "%s ", monnames[vtm.tm_mon]);
  fprintf(stdout, "%02d ", vtm.tm_mday);
  fprintf(stdout, "%02d:%02d:%02d ", vtm.tm_hour, vtm.tm_min, vtm.tm_sec);
  fprintf(stdout, "TZN %4d ", 1900 + vtm.tm_year);
  fprintf(stdout, "(yday %3d; dst %d)\n", vtm.tm_yday, vtm.tm_isdst);
}
