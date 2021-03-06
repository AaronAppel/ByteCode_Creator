#ifndef __MESH_H__
#define __MESH_H__

struct VertexData;
class ShaderProgram;
class Mesh;

typedef void (Mesh::*MeshFunction)(); // Draw function

class Mesh
{
public:
	Mesh();
	~Mesh();

	/* Setup */
	void BufferMeshData(int numVerts, VertexData* verts, int numIndices, unsigned int* indices);
	void SetupShaderAttributes(ShaderProgram* shader);

	/* Draw */
	void Draw() { (this->*m_DrawFunc)(); }; // Call appropriate Draw() function

	/* Getters + Setters */
	// Getters
	std::string GetName() { return m_Name; };

	// Setters
	void SetName(std::string name) { m_Name = name; }
	void SetPrimitiveType(GLenum type) { m_PrimitiveType = type; };

	/* Cleanup */
	void DestroyMesh(); // Used for assigning new data to an already initialize mesh

private:
	/* Handles */
	GLuint m_VBO = 0;
	GLuint m_EBO = 0;
	GLuint m_VAO = 0;

	/* Variables */
	GLuint m_VertCount = 0; // TODO: Is storing this necessary?
	GLuint m_IndexCount = 0;
	GLenum m_PrimitiveType = GL_TRIANGLES;
	std::string m_Name = "Unitialized";

	/* Draw functionality */
	MeshFunction m_DrawFunc = &Mesh::NullDraw;

	void DrawElements(); // Use IBO
	void DrawArrays(); // Draw raw vertex data
	void NullDraw() {}; // TODO: Create event... { OutputMessage("\nMesh: Draw() function* never set properly.\n"); }// NULL
};

#endif //__MESH_H__
