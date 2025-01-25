/*
-- ShaderModule of RenderEngine --

- Binds shaders during setup.
- Ensuring the appropriate layout during runtime.

*/

#pragma once


struct ShaderCrate { };

class ShaderModule {
public:
    ShaderModule(const ShaderCrate& crate);
    ~ShaderModule();

private:
};
