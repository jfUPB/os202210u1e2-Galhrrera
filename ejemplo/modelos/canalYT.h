/**
 * @file canalYT.h
 * @author Galhrrera
 * @brief 
 * @version 0.1
 * @date 2022-03-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * SUJETO U OBSERVABLE - PUBLICADOR
 */

#ifndef CANALYT_H
  #define CANALYT_H
  #include <stdio.h>
  #include <stdlib.h>
  //Se implementan las "interfaces" del patrón
  #include "../../observer/observer.h"
  #include "../../observer/subject.h"

    typedef enum __canalYT_event
    {
        UPLOADVIDEO
    }CanalYTEvent;

    typedef struct __canalYT
    {
        char* name;
        void (*destroy)(struct __canalYT*);

        CanalYTEvent event;
        CanalYTEvent (*getEvent)(struct __canalYT*);

        void (*uploadVideo)(struct __canalYT*);

        Subject * subject;
        int (*registerObserver)(struct __canalYT*, Observer*);
        int (*unregisterObserver)(struct __canalYT *, Observer*);
    }CanalYT;

    /**
     * Crear un canal de YT
     */

    CanalYT * CanalYT_create(char *);

#endif