#define F (1 << 14)
#define INT_MAX ((1 << 31) - 1)
#define INT_MIN (-(1 << 31))

// Convierte un entero en un número equivalente en representación de punto fijo 17.14
// n es un entero

int int_to_fp(int n);
int fp_to_int_round(int x);
int fp_to_int(int x);
int add_fp(int x, int y);
int add_mixed(int x, int n);
int sub_fp(int x, int y);
int sub_mixed(int x, int n);
int mult_fp(int x, int y);
int mult_mixed(int x, int y);
int div_fp(int x, int y);
int div_mixed(int x, int n);

int int_to_fp(int n)
{
  return n * F;
}

/* Redondea un entero. */
int fp_to_int_round(int x)
{
  if (x >= 0)
    {
      return (x + F / 2) / F;
    }
  else
    {
      return (x - F / 2) / F;
    }
}

int fp_to_int(int x)
{
  return x / F;
}

// suma
int add_fp(int x, int y)
{
  return x + y;
}

//resta
int sub_fp(int x, int y)
{
  return x - y;
}

//Aux Suma
int add_mixed(int x, int n)
{
  return x + int_to_fp(n);
}

//Aux resta
int sub_mixed(int x, int n)
{
  return x - int_to_fp(n);
}

//Multiplicacion
int mult_fp(int x, int y)
{
  return ((int64_t) x) * y / F;
}

//Aux multiplicacion.
int mult_mixed(int x, int n)
{
  return x * n;
}

//Division
int div_fp(int x, int y)
{
  return ((int64_t) x) * F / y;
}

//Aux Division.
int div_mixed(int x, int n)
{
  return x / n;
}