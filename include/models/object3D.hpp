/*
-- Object3D of partial SceneEngine --

- Includes a base class, Object3D, only used for allowing types. Has no real value.
- Includes all other object types.

*/

#pragma once

#include <vmmlib/vector.hpp>
#include <models/material.hpp>


struct Object3D { };

struct Sphere : Object3D {
    vmml::vec3f position;
    float radius;

    Material material;
};
