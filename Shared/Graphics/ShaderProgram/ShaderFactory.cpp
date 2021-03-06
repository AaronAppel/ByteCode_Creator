#include "Graphics\SetupGraphics.h"
#include <string>

const char* ShaderFactory::CreateVertexShader(eShaderTypes shaderType)
{
	std::string vertString;

	SetVertName(shaderType, vertString);
	SetVersion(vertString);

	switch (shaderType)
	{
	case eShader_Basic2D:
		vertString = Basic2DShaderVert(vertString);
		break;
	case eShader_Basic3D:
		vertString = Basic3DShaderVert(vertString);
		break;
	case eShader_LitMaterial:
		vertString = LitMaterialVert(vertString);
		break;
	}

	const char* returnString = DeepCopyString(vertString.c_str());

	return returnString;
}

const char* ShaderFactory::CreateFragmentShader(eShaderTypes shaderType)
{
	std::string fragString;

	SetFragName(shaderType, fragString);
	SetVersion(fragString);

	switch (shaderType)
	{
	case eShader_Basic2D:
		fragString = Basic2DShaderFrag(fragString);
		break;
	case eShader_Basic3D:
		fragString = Basic3DShaderFrag(fragString);
		break;
	case eShader_LitMaterial:
		fragString = LitMaterialFrag(fragString);
		break;
	}

	const char* returnString = DeepCopyString(fragString.c_str());
	return returnString;
}

void ShaderFactory::SetVertName(eShaderTypes shaderType, std::string &shaderString)
{
	switch (shaderType) // shader name comment for easier debugging
	{
	case eShader_Basic3D:
		shaderString.append("// Basic3D.vert");
		break;
	case eShader_LitMaterial:
		shaderString.append("// LitMaterial.vert");
		break;
	}
}

void ShaderFactory::SetFragName(eShaderTypes shaderType, std::string &shaderString)
{
	switch (shaderType) // shader name comment for easier debugging
	{
	case eShader_Basic3D:
		shaderString.append("// Basic3D.frag");
		break;
	case eShader_LitMaterial:
		shaderString.append("// LitMaterial.frag");
		break;
	}
}

void ShaderFactory::SetVersion(std::string &shaderString)
{
	// TODO:: Get and store the openGL version for reference
	int _OpenGLVersion = 330;
	std::string _OpenGLprofile = "core";
	shaderString.append("\n#version " + std::to_string(_OpenGLVersion) + " " + _OpenGLprofile);
}

void ShaderFactory::OpenMain(std::string &shaderString)
{
	shaderString.append("\nvoid main()\n{");
}

void ShaderFactory::CloseMain(std::string &shaderString)
{
	shaderString.append("\n}");
}
/* Getters + Setters */
// Getters
// Setters
void ShaderFactory::SetPrefixes(const char* attr, const char* unif, const char* trans)
{
	m_AttributePrefix = DeepCopyString(attr);
	m_UniformPrefix = DeepCopyString(unif);
	m_TransferPrefix = DeepCopyString(trans);
}
/* Utility */
// structs
void ShaderFactory::AddMaterialStruct(std::string &string)
{
	const char* material_struct =
		"\nstruct Material {"
		"\nvec3 ambient;"
		"\nvec3 diffuse;"
		"\nvec3 specular;"
		"\nfloat shininess;"
		"\n};\n";
	string.append(material_struct);
}
// TODO: Would a light struct help?
void ShaderFactory::AddLightStruct(std::string &string)
{
	const char* light_struct =
		"\nstruct Light {"
		"\nvec3 colour;"
		"\n};\n";
	string.append(light_struct);
}
// attributes
void ShaderFactory::AddAttributeInt(const char* name, std::string &string)
{
	const char* line = "\nin int ";
	string.append(line);
	string.append(m_AttributePrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddAttributeFloat(const char* name, std::string &string)
{
	const char* line = "\nin float ";
	string.append(line);
	string.append(m_AttributePrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddAttributeVec2(const char* name, std::string &string)
{
	const char* line = "\nin vec2 ";
	string.append(line);
	string.append(m_AttributePrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddAttributeVec3(const char* name, std::string &string)
{
	const char* line = "\nin vec3 ";
	string.append(line);
	string.append(m_AttributePrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddAttributeVec4(const char* name, std::string &string)
{
	const char* line = "\nin vec4 ";
	string.append(line);
	string.append(m_AttributePrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddAttributeMat2(const char* name, std::string &string)
{
	const char* line = "\nin mat2 ";
	string.append(line);
	string.append(m_AttributePrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddAttributeMat3(const char* name, std::string &string)
{
	const char* line = "\nin mat3 ";
	string.append(line);
	string.append(m_AttributePrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddAttributeMat4(const char* name, std::string &string)
{
	const char* line = "\nin mat4 ";
	string.append(line);
	string.append(m_AttributePrefix);
	string.append(name);
	string.append(";");
}
// uniforms
void ShaderFactory::AddUniformMaterialStruct(const char* name, std::string &string)
{
	const char* line = "\nuniform Material ";
	string.append(line);
	string.append(m_UniformPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddUniformInt(const char* name, std::string &string)
{
	const char* line = "\nuniform int ";
	string.append(line);
	string.append(m_UniformPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddUniformFloat(const char* name, std::string &string)
{
	const char* line = "\nuniform float ";
	string.append(line);
	string.append(m_UniformPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddUniformVec2(const char* name, std::string &string)
{
	const char* line = "\nuniform vec2 ";
	string.append(line);
	string.append(m_UniformPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddUniformVec3(const char* name, std::string &string)
{
	const char* line = "\nuniform vec3 ";
	string.append(line);
	string.append(m_UniformPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddUniformVec4(const char* name, std::string &string)
{
	const char* line = "\nuniform vec4 ";
	string.append(line);
	string.append(m_UniformPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddUniformMat2(const char* name, std::string &string)
{
	const char* line = "\nuniform mat2 ";
	string.append(line);
	string.append(m_UniformPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddUniformMat3(const char* name, std::string &string)
{
	const char* line = "\nuniform mat3 ";
	string.append(line);
	string.append(m_UniformPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddUniformMat4(const char* name, std::string &string)
{
	const char* line = "\nuniform mat4 ";
	string.append(line);
	string.append(m_UniformPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddUniformSampler2D(const char* name, std::string string)
{
	const char* line = "\nuniform sampler2D ";
	string.append(line);
	string.append(m_UniformPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddUniformTexture(int* count, std::string string)
{
	const char* line = "\nuniform sampler2D ";
	string.append(line);
	string.append(m_UniformPrefix);
	string.append("Texture");
	string.append(std::to_string(*count));
	*count++; // increment
	string.append(";");
}
// input
void ShaderFactory::AddInputInt(const char* name, std::string &string)
{
	const char* line = "\nin int ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddInputFloat(const char* name, std::string &string)
{
	const char* line = "\nin float ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddInputVec2(const char* name, std::string &string)
{
	const char* line = "\nin vec2 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddInputVec3(const char* name, std::string &string)
{
	const char* line = "\nin vec3 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddInputVec4(const char* name, std::string &string)
{
	const char* line = "\nin vec4 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddInputMat2(const char* name, std::string &string)
{
	const char* line = "\nin mat2 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddInputMat3(const char* name, std::string &string)
{
	const char* line = "\nin mat3 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddInputMat4(const char* name, std::string &string)
{
	const char* line = "\nin mat4 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}
// output
void ShaderFactory::AddOutputInt(const char* name, std::string &string)
{
	const char* line = "\nout int ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddOutputFloat(const char* name, std::string &string)
{
	const char* line = "\nout float ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddOutputVec2(const char* name, std::string &string)
{
	const char* line = "\nout vec2 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddOutputVec3(const char* name, std::string &string)
{
	const char* line = "\nout vec3 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddOutputVec4(const char* name, std::string &string)
{
	const char* line = "\nout vec4 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddOutputMat2(const char* name, std::string &string)
{
	const char* line = "\nout mat2 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddOutputMat3(const char* name, std::string &string)
{
	const char* line = "\nout mat3 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}

void ShaderFactory::AddOutputMat4(const char* name, std::string &string)
{
	const char* line = "\nout mat4 ";
	string.append(line);
	string.append(m_TransferPrefix);
	string.append(name);
	string.append(";");
}