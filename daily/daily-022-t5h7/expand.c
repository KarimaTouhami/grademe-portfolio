static int	my_strcmp(const char *s1, const char *s2, int len)
{
    int i = 0;
    while (i < len && s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (i == len && s2[i] == '\0')
        return (0);
    return (1);
}

static void     my_strcpy(char *dest, const char *src, int *d_idx)
{
    int i = 0;
    while (src[i])
    {
        dest[*d_idx] = src[i];
        (*d_idx)++;
        i++;
    }
}

void expand(char *out, const char *tmpl)
{
    int close_idx;
    int var_len;
    int i = 0;
    int o = 0;

    while (tmpl[i])
    {
        if(tmpl[i] == '$' && tmpl[i + 1] == '{')
        {
            close_idx = i + 2;
            while (tmpl[close_idx] != '\0' && tmpl[close_idx] != '}')
                close_idx++;
            if (tmpl[close_idx] == '}')
            {
                var_len = close_idx - (i + 2);
                if (my_strcmp(&tmpl[i + 2], "user", var_len) == 0)
                {
                    my_strcpy(out, "neo", &o);
                    i = close_idx + 1;
                    continue ;
                }
                else if (my_strcmp(&tmpl[i + 2], "env", var_len) == 0)
                {
                    my_strcpy(out, "prod", &o);
                    i = close_idx + 1;
                    continue ;
                }
            }
        }
        out[o++] = tmpl[i++];
    }
    out[o] = '\0';
}