#ifndef LOADOBJMODEL_H
#define LOADOBJMODEL_H

#include "../../Core/Debug.h"
#include <sstream>
#include "../../Math/BoundingBox.h"
#include <vector>

class LoadOBJSprite
{
public:
	LoadOBJSprite();
	~LoadOBJSprite();

	void LoadSprite(const std::string& objFilePath_);

	std::vector<Vertex> GetVerts();
	std::vector<int> GetIndices();
	std::vector<SubMesh> GetSubMeshes();
	BoundingBox GetBoundingBox();

	void OnDestroy();

private: 

	void PostProcessing();
	void LoadMaterial(const std::string& fileName_);
	void LoadMaterialLibrary(const std::string& matFilePath_);

	BoundingBox box;
	Material currentMaterial;
};
#endif // !LOADOBJMODEL_H
