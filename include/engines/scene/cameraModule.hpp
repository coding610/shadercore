/*
-- CameraModule of SceneEngine --

- Handles camera movement and projection matrixes.
- Is treated like a special object by SceneEngine.

*/

#pragma once


struct CameraCrate { };

class CameraModule {
public:
    CameraModule(const CameraCrate& crate);
    ~CameraModule();

private:
};
