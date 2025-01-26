#include <GL/glew.h>
#include <GL/gl.h>

#include <engines/render/bufferModule.hpp>


BufferModule::BufferModule() { }
BufferModule::~BufferModule() {
    for (const auto& [name, buffer] : buffers) { glDeleteBuffers(1, &buffer.id); }
    buffers.clear();
}
void BufferModule::init(const BufferCrate& crate) { }

void BufferModule::createBuffer(const char* name, GLenum type, size_t size, GLuint bindingPoint) {
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBufferBase(type, bindingPoint, buffer);
    glBufferData(type, size, nullptr, GL_DYNAMIC_DRAW);
    buffers[name] = { .id=buffer, .type=type, .bindingPoint=bindingPoint };
}

void BufferModule::updateBuffer(const char* name, const void* data, size_t size) {
    const Buffer& buffer = buffers[name];
    glBindBuffer(buffer.type, buffer.id);
    glBufferSubData(buffer.type, 0, size, data);
}

void BufferModule::bindBuffer(const char* name) {
    const Buffer& buffer = buffers[name];
    glBindBufferBase(buffer.type, buffer.bindingPoint, buffer.id);
}
