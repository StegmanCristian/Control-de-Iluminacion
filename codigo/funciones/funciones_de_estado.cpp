#include "../libs/MyLib.h"

intensidad f_setting(void)
{
	intensidad config;
	config= f_config("config.conf");
	return config;
}

estados f_off(intensidad config)
{
	estados estado =off;
	config.i = read_i();
	working(config.i,estado);
	return (config.i>config.i_set-config.delta_i) ? off : on;
}

estados f_on(intensidad config)
{
	estados estado=on;
	config.i = read_i();
	working(config.i,estado);
	return (config.i<config.i_set+config.delta_i) ? on : off;	
}
