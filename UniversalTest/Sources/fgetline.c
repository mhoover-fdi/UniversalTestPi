#include <ansi_c.h>
/******************************************************************************************************************************************
    Function takes into account Mac "AND" Unix line endings and returns
	only one line from the file stream at a time until EOF
	
	Mac		fgets returns with 	-> \r
	Unix	fgets returns with	-> \n
	wiNdoZe	fgets returns with	-> \r\n
	
	Use this as a replacement for standard ANSII C
	fgets function when supporting all the different
	types of file line endings on all platforms
	 
******************************************************************************************************************************************/
char *fgetline( char *line, size_t size, FILE *stream )
{
	char	*s = line;
	char	*end = line + size - 1;
	int		c = '\0';
	int		c2;

	if ( !s )
		return NULL;

	while ( s < end && ( c = getc( stream ) ) != EOF )
	{
		if (c == '\n')
		{	*s++ = c;
			break;
		}
		else if (c == '\r')
		{
			*s++ = '\n';

			if ( (  c2 = getc( stream ) ) == '\n' )
				break;

			ungetc( c2, stream );
			break;
		}
		else
			*s++ = c;
	}

	if ( s < end && c == EOF )
	{
		if ( ferror( stream ) )
			return NULL;

		if ( s == line && feof( stream ) )
			return NULL;
	}

	*s = '\0';

	return line;
}
