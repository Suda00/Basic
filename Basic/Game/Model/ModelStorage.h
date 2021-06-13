#pragma once
#include <Model.h> 
#include <SimpleMath.h>
#include <unordered_map>

class ModelStorage
{
private:
	using ModelPtr = std::unique_ptr<DirectX::Model>;
	using GameStateFactoryList = std::unordered_map<std::string, ModelPtr>;


private:
	static ModelStorage* myInstance;


private:
	std::unordered_map<std::string, std::unique_ptr<DirectX::Model>> m_pModel;



private:
	ModelStorage();
public:
	~ModelStorage();



public:
	static ModelStorage* GetInstance();
	static void ReleaseInstance();



	void AddModel(std::string name, const wchar_t fileName);
	
	void DrawModel(
		const std::string name,
		DirectX::SimpleMath::Matrix  world,
		DirectX::SimpleMath::Matrix view,
		DirectX::SimpleMath::Matrix projection);
};