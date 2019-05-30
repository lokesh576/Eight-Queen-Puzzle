#include<stdio.h>
#include<conio.h>
void retry ();
void start_puzzle ();
void print_box (char *, int, int);
int win_status (char *, int);
int main ()
{
  start_puzzle ();
  return 0;
}

void start_puzzle ()
{
  system ("clear");
  printf ("HELLO MATE! HERE ARE THE INSTRUCTIONS\n");
  printf ("HERE YOU NEED TO SELECT ANY OF THE THREE OPTIONS WHICH INDICATE THE DIMENSIONS OF THE CHESS BOARD\n");
  printf ("YOU NEED TO PLACE n QUEENS IN AN nxn SQUARE BOX, SUCH THAT ANY OF THE QUEEN SHOULD NOT BE ATTACKING ANOTHER QUEEN\n");
  printf ("1. 4X4 2. 6X6 3.8X8\nENTER A NUMBER TO CHOOSE THAT OPTION\n");
  char box[8][8], *bs;
  int i, j, dim;
  scanf ("%d", &dim);
  bs = &box[0][0];
  dim = dim * 2 + 2;
  for (i = 0; i < dim; i++)
    {
      for (j = 0; j < dim; j++)
	{
	  box[i][j] = '  ';
	}
    }
  print_box (bs, dim, i);
  for (i = 0; i < dim; i++)
    {
      system ("clear");
      print_box (bs, dim, i);
    }
  if (win_status (bs, dim) == 1)
    {
      printf ("!!!!! :) YAY CONGRATULATIONS YOU WON :) !!!!!\n");
      retry ();
    }
  else
    {
      printf ("!!! :(SORRY TRY AGAIN :( !!!\n");
      retry ();
    }
}

void retry ()
{
  int yn;
  printf ("ENTER '1' TO TRY AGAIN\n");
  printf ("ENTER '0' TO EXIT\n");
  scanf ("%d", &yn);
  if (yn == 1)
    {
      start_puzzle ();
    }
}

void print_box (char *bs, int dim, int count)
{
  int i, j, k, qpr, qpc;
  for (i = 0; i < dim; i++)
    {
      for (j = 0; j < dim * 3 - 1; j++)
	{
	  printf ("---");
	}
      printf ("\n");
      for (j = 0; j < 3; j++)
	{
	  for (k = 0; k < dim; k++)
	    {
	      printf ("|   ");
	      if (j == 1)
		{
		  printf ("%c", *(bs + i * 8 + k));
		}
	      else
		{
		  printf (" ");
		}
	      printf ("   ");
	    }
	  printf ("|\n");
	}
    }
  for (j = 0; j < dim * 3 - 1; j++)
    {
      printf ("---");
    }
  printf ("\n");
  if (count != dim - 1)
    {
      printf ("ENTER THE ROW NUMBER: ");
      scanf ("%d", &qpr);
      printf ("ENTER THE COLUMN NUMBER: ");
      scanf ("%d", &qpc);
      *(bs + (qpr - 1) * 8 + qpc - 1) = 'Q';
    }
}

int win_status (char *bs, int dim)
{
  int cond, r, i, sp, k;
  for (r = 0; r < dim; r++)
    {
      cond = 0;
      for (i = 0; i < dim; i++)
	{
	  if (*(bs + r * 8 + i) == 'Q')
	    {
	      if (cond == 0)
		{
		  cond = 1;
		  sp = i;
		}
	      else
		return 0;
	    }
	}
      if (cond == 0)
	return 0;
      k = r + 1;
      for (i = 0; i + k < dim; i++)
	{
	  if (*(bs + (i + k) * 8 + sp) == 'Q')
	    return 0;
	}
      for (i = 1; i < dim; i++)
	{
	  if (r + i < dim)
	    {
	      if (i + sp < dim)
		{
		  if (*(bs + (r + i) * 8 + sp + i) == 'Q')
		    {
		      return 0;
		    }
		  if (sp - i > 0)
		    {
		      if (*(bs + (r + i) * 8 + sp + i) == 'Q')
			{
			  return 0;
			}
		    }
		}
	    }
	}
    }
  return 1;
}
