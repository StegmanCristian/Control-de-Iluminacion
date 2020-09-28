#include "../libs/MyLib.h"

char *getkey(char *key)
{
	char i=0;
	while (*(key+i)!=' ')
	{
		i++;
	}
	*(key+i)=0;
	return key+i+1;
}

intensidad f_config(char *filename)
{
	FILE *conf;
	char cadena[40], *key, *val;
	char variables[2][20] = {"i_set", "delta_i"};
	intensidad config;
	char i, flagi=0,flagd=0;
	enum set
	{
		i_set=0,
		delta_i=1
	} ;
	if ((conf=fopen(filename, "rt")) == NULL)
	{
		printf("\n***Error: Archivo de configuracion no encontrado***\n");
		config.i_set = -1;
		config.delta_i = -1;
		return config;
	}
	fgets(cadena,40,conf);
	do
	{
		key=cadena;
		if ((*key)!='#'&& strlen(key)>=0)
		{
			val=getkey(key);
			for(i=0;i<2;i++)
			{
				if(!strcmp(key,variables[i]))
				{
					switch(i)
					{
						case i_set:
							config.i_set = atoi(val);
							flagi = 1;
							break;
						case delta_i:
							config.delta_i = atoi(val);
							flagd =1;
							break;
					}
				}
			}
		}
		fgets(cadena,40,conf);
	} while (!feof(conf));
	if(flagi && flagd)
	{
		return config;
	}
	else
	{
		printf("\n***Error: No se cargaron adecuadamente los valores de configuracion***\n");
		config.i_set = -1;
		config.delta_i = -1;
		return config;
	}
}


char read_i(void)
{
	int intens;
	printf("\n\nLectura de la intensidad ambiente:");
	fflush(stdin);
	scanf("%d",&intens);
	return intens;
}

void working(int sensor,estados est_act)
{
	int dimmer;
	if(est_act==off)
		printf("\nDimmer Inactivo");
	else
	{
		printf("\nDimmer Activo");
		dimmer=100-sensor;
		printf("\nIntencidad de la iluminacion: %d %%",dimmer);
	}
}
