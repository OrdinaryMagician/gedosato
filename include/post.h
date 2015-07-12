#pragma once

#include <dxgi.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dxerr.h>

#include "effect.h"
#include "timer.h"

class Post : public Effect {
public:
	Post(IDirect3DDevice9 *device, int width, int height, bool useSRGB = true);
    virtual ~Post();

	void go(IDirect3DTexture9 *frame, IDirect3DTexture9 *depth, IDirect3DSurface9 *dst);
	void reloadShader();

private:
	int width, height;
	bool useSRGB;
	Timer timer;

	ID3DXEffect *effect = NULL;
	IDirect3DTexture9* noiseTex;	// NoiseTex.png
	IDirect3DTexture9* depthTex;

	D3DXHANDLE thisframeTexHandle;
	D3DXHANDLE timerHandle;
	D3DXHANDLE noiseTexHandle;
	D3DXHANDLE depthTexHandle;
};
