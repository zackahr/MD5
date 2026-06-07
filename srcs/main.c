#include "ft_ssl.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (usage());
	return (dispatch(argc, argv));
}
