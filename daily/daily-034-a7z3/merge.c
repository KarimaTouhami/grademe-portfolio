void	merge_alarms(int *out, const int *a, int na, const int *b, int nb)
{
    int i, j, k;

    i = j = k = 0;
    while (i <na && j < nb)
    {
        if (a[i] <= b[j])
            out[k++] = a[i++];
        else
            out[k++] = b[j++];
    }
    while (i < na)
        out[k++] = a[i++];
    while (j < nb)
        out[k++] = b[j++];
}
