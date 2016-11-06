#include<stdio.h>
#include<stdlib.h>
#include<grass/gis.h>
#include<grass/glocale.h>
#include"/usr/local/grass-7.0.0/include/grass/gis.h"

int main(int argc, char **argv)
{
	printf("This is test module, Ke Wang\n");
	printf("argc: %d\n", argc);
	char **pa;
	for(pa=argv; *pa; ++pa)
	{
		printf("%s\n", *pa);
	}
	/* gis parser */
	G_gisinit(argv[0]);

	struct Option *opt;
	struct Flag *flag;

	opt = G_define_option();
	opt->key = "option";
	opt->description = _("Option test");
	opt->type = TYPE_STRING;
	opt->required = YES;

	flag = G_define_flag();
	flag->key = 't';
	flag->description = _("Flag test");
	
	if(G_parser(argc, argv)) exit(EXIT_FAILURE);

	fprintf(stdout, "<<<The Current General Information>>>\n");
	fprintf(stdout, "Current Location: %s\n", G_location());
	fprintf(stdout, "Current Mapset: %s\n", G_mapset());
	fprintf(stdout, "Current Myname: %s\n", G_myname());
	fprintf(stdout, "Current Gisbase: %s\n", G_gisbase());
	fprintf(stdout, "-----------------\n\n");

	fprintf(stdout, "<<< parameters >>>\n");
	fprintf(stdout, "Option name: %s, Answer: %s\n", opt->key, opt->answer);
	fprintf(stdout, "Flag name: -%c, Answer: %s\n", flag->key, flag->answer?"yes":"not");
	fprintf(stdout, "-----------------\n\n");

	wk_projection();
	return 0;
}

int wk_projection(void)
{
	double north = -23.129832;
	char northStr[50] = "48:34:26N";

	//G_scan_northing(northStr, &north, G_projection());
	//G_format_northing(north, northStr, G_projection());
	G_format_northing(north, northStr, PROJECTION_LL);

	fprintf(stdout, "<<< wk_projection >>>\n");
	fprintf(stdout, "Current Projection: %s\n", G_database_projection_name());
	fprintf(stdout, "north=%lf\n", north);
	fprintf(stdout, "northStr=%s\n", northStr);
	fprintf(stdout, "---------------------\n");
	return 0;
}
