void signal_headler(int signo, void (*handler)int)
{
	struct sigaction act;

	memset(&act, '\0', sizeof(act));
	act.sa_headler = headler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);

	sigaction(signo, &act, NULL);
}
