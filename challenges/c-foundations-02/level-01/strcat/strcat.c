char *strcat(char *dest, const char *src) {
    char *start = dest;
    
    while (*dest != '\0') {
        dest++;
    }
    
    while ((*dest++ = *src++) != '\0');
    
    return (start);
}   