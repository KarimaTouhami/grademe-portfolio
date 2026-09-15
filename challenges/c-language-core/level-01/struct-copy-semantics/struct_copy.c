typedef struct record
{
	int		id;
	int		score;
	char	*name;
}	record;

record	record_with_id(record src, int id)
{
	src.id = id;
	return (src);
}
