void	parse_func_def(char *out, const char *value)
{
    if(!value)
    {
        *out = '\0';
        return ;
    }
    if (value[0] == '(' && value[1] == ')' && value[2] == ' ' && value[3] == '{')
    {
        value += 4;
        while (*value && *value != '}')
            *out++ = *value++;
    } else
    {
        while (*value)
            *out++ = *value++;
    }
    *out = '\0';
}
