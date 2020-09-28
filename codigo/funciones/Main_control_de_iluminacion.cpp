#include "../libs/MyLib.h"

int main()
{
    intensidad config;
    estados estado = off;    //definimos el primer estado de la maquina
	config = f_setting();
	if (config.i_set==-1)
		return 0;
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
