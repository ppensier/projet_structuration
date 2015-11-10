#include "help.h"
#include <math.h>
#include <proj_api.h>

void help::convertCoord(double &x, double &y){

    char *srid4326 = "+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs";
    char *srid27572 = "+proj=lcc +lat_1=46.8 +lat_0=46.8 +lon_0=0 +k_0=0.99987742 +x_0=600000 +y_0=2200000 +a=6378249.2 +b=6356515 +towgs84=-168,-60,320,0,0,0,0 +pm=paris +units=m +no_defs +towgs84=-168,-60,320,0,0,0,0,";

    projPJ source = pj_init_plus(srid4326);
    projPJ target = pj_init_plus(srid27572);

    x *= DEG_TO_RAD;
    y *= DEG_TO_RAD;

    pj_transform(source, target, 1, 1, &x, &y, NULL );
}
