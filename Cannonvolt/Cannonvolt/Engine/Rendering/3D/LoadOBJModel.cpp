#include "LoadOBJModel.h"

LoadOBJModel::LoadOBJModel() : currentMaterial(Material())
{
	vertices.reserve(200);
	normals.reserve(200);
	textureCoords.reserve(200);
	indices.reserve(200);
	normalIndices.reserve(200);
	textureIndices.reserve(200);
	subMeshes.reserve(10);
}


LoadOBJModel::~LoadOBJModel()
{
	OnDestroy();
}

void LoadOBJModel::LoadModel(const std::string & objFilePath_)
{
	std::ifstream in(objFilePath_.c_str(), std::ios::in);
	if (!in) {
		Debug::Error("Cannot open OBJ file: " + objFilePath_,
			"LoadOBJModel.cpp", __LINE__);
		return;
	}
	std::string line;
	box.minVert = glm::vec3(FLT_MAX);
	box.maxVert = glm::vec3(FLT_MIN);

	while (std::getline(in, line)) {
		//VERTEX DATA
		if (line.substr(0, 2) == "v ") {
			std::istringstream v(line.substr(2));
			float x, y, z;
			v >> x >> y >> z;
			vertices.push_back(glm::vec3(x, y, z));

			box.maxVert.x = x > box.maxVert.x ? static_cast<float>(x) : box.maxVert.x;
			box.minVert.x = x < box.minVert.x ? static_cast<float>(x) : box.minVert.x;

			box.maxVert.y = y > box.maxVert.y ? static_cast<float>(y) : box.maxVert.y;
			box.minVert.y = y < box.minVert.y ? static_cast<float>(y) : box.minVert.y;

			box.maxVert.z = z > box.maxVert.z ? static_cast<float>(z) : box.maxVert.z;
			box.minVert.z = z < box.minVert.z ? static_cast<float>(z) : box.minVert.z;
		}

		//NORMAL DATA
		else if (line.substr(0, 3) == "vn ") {
			std::istringstream v(line.substr(3));
			GLfloat x, y, z;
			v >> x >> y >> z;
			
			normals.push_back(glm::vec3(x, y, z));
		}

		//TEXTURE COORDINATE DATA
		else if (line.substr(0, 3) == "vt ") {
			std::istringstream v(line.substr(3));
			float x, y;
			v >> x >> y;
			textureCoords.push_back(glm::vec2(x, y));
		}

		//FACE DATA
		else if (line.substr(0, 2) == "f ") {
			std::istringstream v(line.substr(2));
			char slash;
			GLuint x, y, z, xT, yT, zT, xN, yN, zN;
			v >> x >> slash >> xT >> slash >> xN >>
				y >> slash >> yT >> slash >> yN >>
				z >> slash >> zT >> slash >> zN;

			x--; y--; z--;
			xT--; yT--; zT--;
			xN--; yN--; zN--;
			
			indices.push_back(x);
			indices.push_back(y);
			indices.push_back(z);

			normalIndices.push_back(xN);
			normalIndices.push_back(yN);
			normalIndices.push_back(zN);

			textureIndices.push_back(xT);
			textureIndices.push_back(yT);
			textureIndices.push_back(zT);

		}

		else if (line.substr(0, 7) == "usemtl ") {
			if (indices.size() > 0) {
				PostProcessing();
			}
			LoadMaterial(line.substr(7));
		}
	}
	PostProcessing();

}

void LoadOBJModel::LoadModel(const std::string & objFilePath_, const std::string & matFilePath_)
{
	LoadMaterialLibrary(matFilePath_);
	LoadModel(objFilePath_);
}

std::vector<Vertex> LoadOBJModel::GetVerts()
{
	return meshVertices;
}

std::vector<int> LoadOBJModel::GetIndices()
{
	return indices;
}

std::vector<SubMesh> LoadOBJModel::GetSubMeshes()
{
	return subMeshes;
}

BoundingBox LoadOBJModel::GetBoundingBox()
{
	return box;
}

void LoadOBJModel::OnDestroy()
{
	vertices.clear();
	normals.clear();
	textureCoords.clear();
	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVertices.clear();
	subMeshes.clear();
}

void LoadOBJModel::PostProcessing()
{
	for (int i = 0; i < indices.size(); i++) {
		Vertex vert;
		vert.position = vertices[indices[i]];
		vert.normal = normals[normalIndices[i]];
		vert.texCoord = textureCoords[textureIndices[i]];
		meshVertices.push_back(vert);
	}

	SubMesh subMesh;
	subMesh.vertexList = meshVertices;
	subMesh.meshIndices = indices;
	subMesh.material = currentMaterial;
	subMeshes.push_back(subMesh);

	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVertices.clear();
	currentMaterial = Material();

}

void LoadOBJModel::LoadMaterial(const std::string & fileName_)
{
	currentMaterial = MaterialHandler::GetInstance()->GetMaterial(fileName_);
}

void LoadOBJModel::LoadMaterialLibrary(const std::string & matFilePath_)
{
	MaterialLoader::LoadMaterial(matFilePath_);
}
