#include "MyLib.h"

int main()
{
    intensidad config;
    estados estado = off;    //definimos el primer estado de la maquina
	config = f_setting();
	if(config.i_set==-1)
	{
		print("Hubo un error en la carga de los datos de configuracion");
		return 0;
	}//Si f_setting carga un -1 en i_set entonces hubo un error en la carga de la configuracion
	printf("Se cargo la configuracion de seteo:\n i_set: %d \n delta_i: %d\n",config.i_set,config.delta_i);
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
