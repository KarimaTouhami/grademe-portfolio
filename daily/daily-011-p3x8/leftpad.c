// Copy s into dst, padded on the left with fill up to width, then terminate.
// If s is already width characters or longer, copy it unchanged.
void	left_pad(char *dst, const char *s, int width, char fill)
{
    int len = 0;
    int pad_len = 0;
    int i = 0;
    int j = 0;

    while (s[len] != '\0')
        len++;

    if (width > len)
        pad_len = width - len;

    while (i < pad_len)
    {
        dst[i] = fill;
        i++;
    }

    while (s[j] != '\0')
    {
        dst[i] = s[j];
        i++;
        j++;
    }

    dst[i] = '\0';
}
