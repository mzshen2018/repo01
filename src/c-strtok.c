/***********************************************************************
  Mr. Mingzuo Shen (mshen); Thu Jun  9 14:45:09 1994; hobbes

  on IBM RS6000, this program may cause "memory fault"
  because strtok() will write into the original string;
  use the -qnoro flag to xlc to avoid this.
***********************************************************************/

#include <stdio.h>
#include <string.h>

int
main()
{
  char *p;
  char *buffer = "Find words, all of them. basis=120";
  char *delims = " .,=";

  fprintf(stdout,"%s\n", buffer);

  p = strtok(buffer, delims);
  while (p != NULL)
    {
      fprintf(stdout,"found word: %s\n", p);
      p = strtok(NULL, delims);
    }

  fprintf(stdout,"%s\n", buffer);
  return 0;
}



/***********************************************************************
 Mingzuo Shen (mshen); Tue Jan 04 00:27:29 2005; chaminade.it.bcm.tmc.edu
 if a string has '@' in it, break it at the '@'
 this was used in Courier webmail/auth.c
***********************************************************************/
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    char *p = "mshen@odin.corp.bcm.tmc.edu";
    char *pos;
    pos = strchr(p, '@');
    if (pos) *pos = '\0'; /**** segmentation fault ****. cannot change hard-wired string/
    if (pos) printf("pos=%s\n", pos);
    printf("p=%s\n", p);

    const char *p=getenv("AUTHADDR");
    char *pos;
    if (!p) p = "";
    pos = strchr(p, '@');
    if (pos) pos[0] = '\0'; /**** ok ****/
    if (pos) *pos   = '\0'; /**** ok ****/
    if (pos) printf("pos=%s\n", pos);
    printf("p=%s\n", p);



Mingzuo Shen (mshen); Thu Dec 22 16:09:33 2005; chaminade.it.bcm.tmc.edu
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
 char filt[1024];
 char sbase[1024];
 char stmp[1024];
 char *p = "uid=mshen,ou=people,dc=bcm,dc=edu";
 char *pos;
 strncpy(stmp, p, sizeof(stmp));
 pos = strchr(stmp, ',');
 if (pos)
 {
 strncpy(sbase, pos+1, sizeof(sbase));
 *pos = '\0';
 strncpy(filt, stmp, sizeof(filt));
 printf("search base: %s\n", sbase);
 printf("filter: %s\n", filt);
 }
 else
 {
  strcpy(filt, "uid=dummy");
  strcpy(sbase, "ou=people,dc=bcm,dc=edu");
 }
 return 0;
}
