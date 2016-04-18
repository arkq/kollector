/*
 * kollector - strrcmp.h
 * Copyright (c) 2016 Arkadiusz Bokowy
 *
 * This file is a part of a kollector.
 *
 * This projected is licensed under the terms of the MIT license.
 *
 */

#ifndef KOLLECTOR_STRRCMP_H_
#define KOLLECTOR_STRRCMP_H_

#include <stddef.h>

int strrcmp(const char *s1, const char *s2);
int strrncmp(const char *s1, const char *s2, size_t n);

#endif /* KOLLECTOR_STRRCMP_H_ */
