#include <stdlib.h>
#include "dog.h"

static int _strlen(char *s)
{
        int n = 0;
        if (!s) return 0;
        while (s[n]) n++;
        return n;
}

static char *_strdup2(char *src)
{
        int n = _strlen(src), i;
        char *p = src ? malloc((n + 1) * sizeof(char)) : NULL;
        if (!p) return NULL;
        for (i = 0; i < n; i++) p[i] = src[i];
        p[n] = '\0';
        return p;
}

/**
 * new_dog - creates a new dog (deep copies name and owner)
 * @name: dog's name
 * @age: dog's age
 * @owner: owner's name
 * Return: pointer to new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
        dog_t *d = malloc(sizeof(*d));
        char *ncopy, *ocopy;

        if (!d) return NULL;

        ncopy = _strdup2(name);
        if (!ncopy) { free(d); return NULL; }

        ocopy = _strdup2(owner);
        if (!ocopy) { free(ncopy); free(d); return NULL; }

        d->name = ncopy;
        d->age = age;
        d->owner = ocopy;
        return d;
}
