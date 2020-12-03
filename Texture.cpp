#include "Texture.h"

Texture::Texture(std::string filePath)
	: _textureID(0), _texturePath(filePath), _width(0), 
	_height(0), _BPP(0), _LocalBuffer(nullptr)
{
	stbi_set_flip_vertically_on_load(1);

	glGenTextures(1, &_textureID);
	glBindTexture(GL_TEXTURE_2D, _textureID);

	_LocalBuffer = stbi_load("src/textures/floor.jpg", &_width, &_height, &_BPP, 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, _LocalBuffer);

	if(_LocalBuffer)
		stbi_image_free(_LocalBuffer);

}

Texture::~Texture()
{
	glDeleteTextures(1, &_textureID);
}

void Texture::bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, _textureID);
}

void Texture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
