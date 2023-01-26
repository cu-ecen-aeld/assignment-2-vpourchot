#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

//Setup syslog logging for your
//utility using the LOG_USER facility

int append_str(char *writefile,char *writestr);

int main(int augc,char *argv[]) {
	openlog(NULL,0,LOG_USER);
	append_str(argv[1],argv[2]);
	return 0;
}

int append_str(char *writefile,char *writestr) {
	// Create file named $writestr
	// Append 'Writing $writestr to file'
	// to newly created file
	// Write with LOG_DEBUG level
		
	int fp = creat(writefile,0666);
	if (fp == -1) {
                syslog(LOG_ERR,"Directory does not exist: %s",writefile);
		return 1;
	}

	ssize_t nr = write(fp,writestr,strlen(writestr));
	if (nr == -1) {
              syslog(LOG_ERR,"Invalid Number of arguments: No String Provided %s",writestr);
		return 1;
	}
	int fsync (int fp);
	
	int close (int fp);
	
	syslog(LOG_DEBUG,"Writing %s to %s",writestr,writefile);
	return 0;

}

