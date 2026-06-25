#include <stdarg.h>
#include <unistd.h>

int mini_printf(const char *format, ...)
{
    va_list ap;
    int count = 0;
    char buf[32];

    if (!format)
        return (0);

    va_start(ap, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            
            if (*format == 'c')
            {
                char c = (char)va_arg(ap, int);
                count += write(1, &c, 1);
            }
            else if (*format == 's')
            {
                char *s = va_arg(ap, char *);
                if (!s) 
                    s = "(null)";
                while (*s)
                    count += write(1, s++, 1);
            }
            else if (*format == 'd' || *format == 'x')
            {
                long long n;
                int base;

                if (*format == 'd')
                {
                    n = (long long)va_arg(ap, int);
                    base = 10;
                    if (n < 0)
                    {
                        count += write(1, "-", 1);
                        n = -n;
                    }
                }
                else
                {
                    n = (long long)va_arg(ap, unsigned int);
                    base = 16;
                }

                int i = 0;
                if (n == 0)
                    buf[i++] = '0';
                while (n > 0)
                {
                    buf[i++] = "0123456789abcdef"[n % base];
                    n /= base;
                }
                while (i > 0)
                    count += write(1, &buf[--i], 1);
            }
            else if (*format == '%')
            {
                count += write(1, "%", 1);
            }
            else
            {
                count += write(1, "%", 1);
                count += write(1, format, 1);
            }
        }
        else
        {
            count += write(1, format, 1);
        }
        format++;
    }
    va_end(ap);
    return (count);
}