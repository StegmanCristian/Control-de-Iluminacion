#include "../libs/MyLib.h"

int main()
{
	int sigue;
    intensidad config;
    estados estado = off;    //definimos el primer estado de la maquina
	config = f_setting();
	if(config.i_set==-1)
	{
		printf("\nHubo un error en la carga de los datos de configuracion\n");
		printf("\nPara continuar con los valores predeterminados (i_set=80 y delta_i=2) presione '1'\n\nDe lo contrario presione otro numero: ");
		fflush(stdin);
		scanf ("%d",&sigue);
		if (sigue==1)
		{
			config.i_set=80;
			config.delta_i=2;
		}
		else
		return 0;
	}//Si f_setting carga un -1 en i_set entonces hubo un error en la carga de la configuracion
	printf("\nSe cargo la configuracion de seteo:\t i_set: %d \t delta_i: %d\n",config.i_set,config.delta_i);
	printf("\nPrimer estado: Apagada");
	config.i= read_i();
	if (config.i<config.i_set-config.delta_i)
		estado = on;
		working(config.i,estado);
	while(1)
	{
      switch (estado)
	  {
        case off:
			estado = f_off(config);
            break;
        case on:
			estado = f_on(config);
            break;
      }
    }
  return 0;
}
