#include <stdio.h>
struct A
{
  int x;

  A (A const & a) :
      x (a.x)
  {
    printf ("copy ctor A %d\n", x);
  }
  A (int i) :
      x (i)
  {
    printf ("ctor A %d\n", x);
  }

  ~A ()
  {
    printf ("dtor A %d\n", x);
  }
};

void
foo (int x)
{
  A a (42);
  try
    {
      A ax (x);
      if (x == 1)
	throw x;
      if (x == 3)
	throw ax;
    }
  catch (int y)
    {
      printf ("foo catch %d\n", y);
    }
}

int
main ()
{
  try
    {
      for (int i = 0; i < 4; ++i)
	{
	  printf ("call foo(%d)\n", i);
	  foo (i);
	}
    }
  catch (A const & a)
    {
      printf ("main catch A %d\n", a.x);
    }
  printf (" back in main\n");
  return 0;
}
