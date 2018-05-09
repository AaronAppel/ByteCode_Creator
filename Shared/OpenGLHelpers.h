#ifndef __OpenGLHelpers_H_
#define __OpenGLHelpers_H_

void CheckforGLErrors();
void CheckforGLErrors(char* file, int line);
void CheckforGLErrors(const char* file, int line);

GLuint Load2DTexture(const char* filename, bool flipVertically);

char* blue_GetAttributePrefix();
char* blue_GetUniformPrefix();
char* blue_GetTransferPrefix();

#endif // __OpenGLHelpers_H_