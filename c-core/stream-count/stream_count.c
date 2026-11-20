#include <stdio.h>

void    stream_count(FILE *f, long *lines, long *words, long *bytes)
{
        long    byte_count;
        int     c;
        int     line_count;
        int     in_word;
        int     word_count;

        byte_count = 0;
        line_count = 0;
        in_word = 0;
        word_count = 0;
        while ((c = fgetc(f)) != EOF)
        {
                if (c == '\n')
                {
                        in_word = 0;
                        line_count++;
                }
                else if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
                        in_word = 0;
                else if (in_word == 0)
                {
                        word_count++;
                        in_word = 1;
                }
                byte_count++;
        }

        *lines = line_count;
        *bytes = byte_count;
        *words = word_count;
}