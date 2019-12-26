
#include "ft_printf.h"

static double    expo(int d, int exp)
{
    double result;

    result = 1;
    while (exp > 1)
    {
        result *= d;
        exp--;
    }
    return (result);
}

static int     first_char(long double nb)
{
    int result;

    result = 0;
    while (nb >= 10)
    {
        nb /= 10;
        result = nb;
    }
    return (result);
}

static long    nb_fdigit(long double nb)
{
    long result;

    result = 0;
    if (nb < 10 && nb > -10)
        return (1);
    while (nb >= 1)
    {
        nb /= 10;
        result++;
    }
    return (result);
}

void    disp_Lfloat(t_pf* tpf)
{
    long double val;
    long double dup;
    int argsize;
    int cmp;

    cmp = 0;
    argsize = 0;
	val = va_arg(*(tpf->ap), long double);
    if (val < 0)
    {
        ft_putchar_fd('-', 1);
        val *= -1;
    }
    dup = val;
    //obtenir argsize
    argsize = nb_fdigit(dup);
    //obtenir nb_whitespace
    (!tpf->fprecision) ? tpf->vprecision = 6 : 0;
        tpf->width > argsize + tpf->vprecision ? tpf->whitespace = tpf->width - (argsize + tpf->vprecision + 1) : 0;
    ft_putcharec_fd(' ', tpf->whitespace, 1);
    ft_putnbr_fd((int)val, 1);
    //afficher les chiffres apres la virgulefg
    (tpf->vprecision == 0) ? 0 :ft_putchar_fd('.', 1);
    dup = val;

    int nb;
    int x = 0;
    //printf("a%f", dup);
    dup += 0.5 / expo(10, tpf->vprecision + 1);
    //printf("\nb%f", dup);
    while (cmp < tpf->vprecision)
    {
        dup *= 10;
        ft_putnbr_fd(((int)dup) % 10, 1);
        cmp++;
        nb = nb_fdigit(dup);
        x = first_char(dup);
        if (nb)
            dup -= (expo(10, nb) * x);    
    }
    tpf->length += tpf->whitespace;
    tpf->length += argsize;
    tpf->length += tpf->vprecision;
    (val >= 0) ? tpf->length++ : (tpf->length += 2);
}