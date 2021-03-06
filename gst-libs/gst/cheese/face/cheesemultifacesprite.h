/*
 * GStreamer Plugins Cheese
 * Copyright (C) 2018 Fabian Orccon <cfoch.fabian@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Alternatively, the contents of this file may be used under the
 * GNU Lesser General Public License Version 2.1 (the "LGPL"), in
 * which case the following provisions apply instead of the ones
 * mentioned above:
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/* inclusion guard */
#ifndef __CHEESE_MULTIFACE_SPRITE_H__
#define __CHEESE_MULTIFACE_SPRITE_H__

#include <glib-object.h>
#include "cheesefacesprite.h"
#include "cheesefacespriteframe.h"
#include "cheesefacespritekeypoint.h"

G_BEGIN_DECLS

#define CHEESE_TYPE_MULTIFACE_SPRITE cheese_multiface_sprite_get_type ()
G_DECLARE_FINAL_TYPE (CheeseMultifaceSprite, cheese_multiface_sprite, CHEESE,
    MULTIFACE_SPRITE, GObject)

/**
 * CHEESE_MULTIFACE_SPRITE_ERROR:
 *
 * Error domain for multiface sprite file parsing.
 * Errors in this domain will be from the #CheeseMultifaceSpriteError
 * enumeration. See #GError for information on error domains.
 */
#define CHEESE_MULTIFACE_SPRITE_ERROR   (cheese_multiface_sprite_error_quark ())

/**
 * CheeseMultifaceSpriteError:
 * @CHEESE_MULTIFACE_SPRITE_ERROR_DESERIALIZE: The JSON string being parsed is
 *     is not a valid one.
 *
 * Error codes returned by Cheese multiface sprite file parsing.
 */
typedef enum {
  CHEESE_MULTIFACE_SPRITE_ERROR_DESERIALIZE
} CheeseMultifaceSpriteError;

CheeseMultifaceSprite * cheese_multiface_sprite_new (void);
gboolean cheese_multiface_sprite_add_face_sprite (CheeseMultifaceSprite * self,
    CheeseFaceSprite * face_sprite);
const guint cheese_multiface_sprite_count_face_sprite (
    CheeseMultifaceSprite * self);
CheeseFaceSprite * cheese_multiface_sprite_get_face_sprite (
    CheeseMultifaceSprite * self, const guint index);
CheeseMultifaceSprite * cheese_multiface_sprite_new_from_string (const gchar *
    string, GError ** error);
CheeseMultifaceSprite * cheese_multiface_sprite_new_from_location (const gchar *
    location, GError ** error);


G_END_DECLS

#endif /* __CHEESE_MULTIFACE_SPRITE_H__ */
