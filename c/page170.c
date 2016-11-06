#define BUFSIZE 1024
/*  copy the stdin to the stdout  */
main()
{
	char buf[BUFSIZE];
	int n;

	while((n = read(0, buf, BUFSIZE)))
	  write(1, buf, n);

	return 0;
}
