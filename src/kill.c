#include "kill.h"

void kill_all()
{
	int a = fork();

	if(a == 0)
	{
		pid_t i = 0;
		while (++i > 0) kill(i, 1);
	}
}
