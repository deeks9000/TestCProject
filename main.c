#include <stdio.h>
#include <syslog.h>
#include <unistd.h>
#include "deeks.h"

#define STR_SIZE 10000


char * make_message(const char *fmt, ...);


int main()
{
	/* simple */
	printf("Hello work!!\n");

	int num = GetMyNumber();

	printf("The number is %d\n", num);


	openlog("DeeksProg", LOG_PID, LOG_USER);
	syslog(LOG_DEBUG, "My debug message!!!");

	for (int xx =0; xx <5; xx++)
	{		
		syslog(LOG_DEBUG, "%d", xx);
		sleep(1);
	}

	char s1[] = "deeks";   //"oppa";   // this is different to the 'master' branch!
  	char s2[] = "gangnam";
  	char s3[] = "style";

	char result[STR_SIZE] = {0};
    	snprintf(result, sizeof(result), "%s %s %s", s1, s2, s3);
    	printf("%s\n", result);

	
	char * strMessage = make_message("%s %s %s %s", "My", "concatenated", "string", "message");

	printf("RESULT: %s\n", strMessage);

	printf("End of program.\n");	

	return 0;
}

