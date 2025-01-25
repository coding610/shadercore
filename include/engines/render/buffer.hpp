/*
-- BufferModule of RenderEngine --

- creates and initializes the SSBO and UBOs during setup
- Updates GPU buffers during runtime

*/

#pragma once


struct BufferCrate { };

class BufferModule {
public:
    BufferModule(const BufferCrate& crate);
    ~BufferModule();

private:
};
