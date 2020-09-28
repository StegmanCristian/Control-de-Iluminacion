#include "../libs/MyLib.h"

intensidad f_setting(void)
{
	int sigue;
	intensidad config;
	config= f_config("config.conf");
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
		return config;
	}//Si f_setting carga un -1 en i_set entonces hubo un error en la carga de la configuracion
	printf("\nSe cargo la configuracion de seteo:\t i_set: %d \t delta_i: %d\n",config.i_set,config.delta_i);
	return config;
}

estados f_off(intensidad config)
{
	estados estado =off;
	printf("\nEstado actual: Apagado");
	config.i = read_i();
	if (config.i<=config.i_set-config.delta_i)
	{
		estado=on;
		working(config.i,estado);
	}
	else
		working(config.i,estado);
	return (config.i>config.i_set-config.delta_i) ? off : on;
}

estados f_on(intensidad config)
{
	estados estado=on;
	printf("\nEstado actual: Encendido");
	config.i = read_i();
		if (config.i>=config.i_set+config.delta_i)
	{
		estado=off;
		working(config.i,estado);
	}
	else
		working(config.i,estado);
	return (config.i<config.i_set+config.delta_i) ? on : off;	
}
