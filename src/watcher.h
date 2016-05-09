/*
 * kollector - watcher.h
 * Copyright (c) 2016 Arkadiusz Bokowy
 *
 * This file is a part of a kollector.
 *
 * This project is licensed under the terms of the MIT license.
 *
 */

#ifndef KOLLECTOR_WATCHER_H_
#define KOLLECTOR_WATCHER_H_

#include <glib.h>

gboolean watcher_subscribe(gboolean (*callback)(void *), void *data);
void watcher_close(void);

#endif /* KOLLECTOR_WATCHER_H_ */
