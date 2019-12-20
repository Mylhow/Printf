//TODO mettre header

#include "ft_printf.h"

void    disp_float(t_pf* tpf)
{
    float val;
    float dup;
    int argsize;
    int cmp;

    cmp = 0;
    argsize = 0;
	val = va_arg(*(tpf->ap), double);
    dup = val;
    //obtenir argsize
    while ((dup >= 1 || dup <= -1) && cmp < 10)
    {
        dup /= 10;
        argsize++;
        cmp++;
    }
    //obtenir nb_whitespace
    tpf->width > argsize + tpf->vprecision ? tpf->whitespace = tpf->width - (argsize + tpf->vprecision) : 0;
    ft_putcharec_fd(' ', tpf->whitespace, 1);
    ft_putnbr_fd((int)val, 1);
    //afficher les chiffres apres la virgule
    ft_putchar_fd('.', 1);
    (!tpf->fprecision) ? tpf->vprecision = 6 : 0;
    while (cmp < tpf->vprecision)
    {
        val *= 10;
        ft_putnbr_fd((int)val % 10, 1);
        cmp++;
    }
    tpf->length += argsize;
    tpf->length += tpf->vprecision;
    tpf->length++;
}