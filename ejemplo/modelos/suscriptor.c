/**
 * Cuando el CanalYT sube un video, los suscriptores se enteran
 */

#include "suscriptor.h"

static void _destroy(Suscriptor* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}


static void _seeChannel(Suscriptor * this, CanalYT* canal)
{
	canal->registerObserver(canal, this->observer);
	printf("%s Mira el canal %s\n", this->name, canal->name);
}

/*
static void _handleCanalYTEvent(Suscriptor* this, CanalYT* canal)
{
	printf("%s\n Escucha el canal %s", this->name, canal->name);
}
*/

/**
 * Método del observador llamado a la recepción de un evento entrante
 * @param type
 * @param subject
 */
static void _notify(Suscriptor* this, int numero, void* subject) {
	//_handleCatEvent(this, (CanalYT*) subject);
	_seeChannel(this, (CanalYT*) subject);
}

Suscriptor* Suscriptor_create(char* NombreSuscriptor)
{
	Suscriptor* this = (Suscriptor*) malloc(sizeof(*this));

	this->name = NombreSuscriptor;
	this->seeChannel = _seeChannel;
	this->destroy = _destroy;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);

	return this;
}