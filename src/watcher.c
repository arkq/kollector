/*
 * kollector - watcher.c
 * Copyright (c) 2016 Arkadiusz Bokowy
 *
 * This file is a part of a kollector.
 *
 * This project is licensed under the terms of the MIT license.
 *
 */

#include "watcher.h"

#include <openlipc.h>


static LIPC *lipc = NULL;

struct watcher_data {
	gboolean (*callback)(void *);
	void *data;
};


/* Callback function wrapper. */
static LIPCcode watcher_callback(LIPC *lipc, const char *name,
		LIPCevent *event, void *_data) {
	(void)lipc;
	(void)name;
	(void)event;

	struct watcher_data *data = (struct watcher_data *)_data;

	data->callback(data->data);
	return LIPC_OK;
}

/* Subscribe for the "updated" event emitted by the Kindle content manager. It
 * is worth noting, that this event is emitted every time the book index has
 * been modified (it appears so). Hence, the caller should perform its own
 * check to determine whatever new book has been added or not. This function
 * returns TRUE on success. */
gboolean watcher_subscribe(gboolean (*callback)(void *), void *data) {

	/* initialize LIPC library if not initialized */
	if (lipc == NULL && (lipc = LipcOpenNoName()) == NULL)
		return FALSE;

	struct watcher_data *p;

	p = g_malloc(sizeof(*p));
	p->callback = callback;
	p->data = data;

	if (LipcSubscribeExt(lipc, "com.lab126.ccat", "updated", watcher_callback, p) != LIPC_OK)
		return FALSE;

	return TRUE;
}

/* Release resources acquired by the watcher_subscribe() function. */
void watcher_close(void) {
	if (lipc != NULL) {
		LipcClose(lipc);
		lipc = NULL;
	}
}
