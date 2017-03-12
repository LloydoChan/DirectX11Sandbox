#pragma once
//SimpleApp.h
#include "DefaultDiffuseShader.h"
#include "ObjParser.h"
#include <dinput.h>

class D3DClass;
class SimpleMesh;
class Camera;

const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 5000.0f;
const float SCREEN_NEAR = 0.1f;
const bool FULL_SCREEN = false;



class SimpleApp
{
	public:
		SimpleApp(): mD3D(nullptr),
					 mMesh(nullptr),
					 mShader(nullptr){};
		SimpleApp(const SimpleApp&) = delete;
		~SimpleApp() {};

		bool Init(int, int, HWND, HINSTANCE);
		void Shutdown();
		bool Frame(DIMOUSESTATE& state);

	private:
		bool Render();
		bool ReadInput(DIMOUSESTATE& state);

		D3DClass* mD3D;
		SimpleMesh* mMesh;
		DefaultDiffuseShader* mShader;
		ID3D11SamplerState* mSamplerState;

		materialInfo* mMaterialProperties;

		int mMouseRotateX, mMouseRotateY;
		int mMouseVertY;
		int mMouseHorizZ;

		int mScreenWidth, mScreenHeight;

		Camera* mCamera;

		XMMATRIX mWorld;

		unsigned int numMeshes = 0;
		unsigned int numMaterials = 0;
};
