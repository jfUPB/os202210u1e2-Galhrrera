/**
 * Programa principal que utiliza la implementación del patrón
 * observer
 */

#include <stdio.h>
#include "modelos/canalYT.h"
#include "modelos/suscriptor.h"


int main(int argc, char const *argv[])
{

	CanalYT* unCanal = CanalYT_create("unCanal");
	Suscriptor* unSuscriptor = Suscriptor_create("unSuscriptor");

	unSuscriptor->seeChannel(unSuscriptor, unCanal);
    //Llama al método de cargar video, el cual internamente
    //llama al métodod e la notificación
	unCanal->uploadVideo(unCanal);

	unCanal->destroy(unCanal);
	unSuscriptor->destroy(unSuscriptor);

	return 0;
}