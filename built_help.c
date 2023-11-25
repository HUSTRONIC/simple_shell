#include "shell.h"

/**
 * f_help - This will display information.
 */
void f_help(void)
{
	f_put("\nShell Version 1.0.0\n\n");
	f_put("Usage: ./hsh\n\n");
	f_put("Shell built-in commands:\n\n");
	f_put("help\t\tDisplay this help information\n\n");
	f_put("cd [dir]\tChange the current working directory\n\n");
	f_put("env\t\tDisplay the environment variables\n\n");
	f_put("setenv\t\tSet an environment variable\n\n");
	f_put("unsetenv\tUnset an environment variable\n\n");
	f_put("exit\t\tExit the shell\n\n");
}
