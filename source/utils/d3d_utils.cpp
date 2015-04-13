#include "utils/d3d9_utils.h"

#include <cstdio>
#include <sstream>

#include "settings.h"
#include "utils/string_utils.h"

IDirect3DTexture9* D3DGetSurfTexture(IDirect3DSurface9* pSurface) {
	IDirect3DTexture9 *ret = NULL;
	IUnknown *pContainer = NULL;
	HRESULT hr = pSurface->GetContainer(IID_IDirect3DTexture9, (void**)&pContainer);
	if(D3D_OK == hr) ret = (IDirect3DTexture9*)pContainer;
	SAFERELEASE(pContainer);
	return ret;
}

// most of the enum-related functions in here are auto-generated

TCHAR* D3DFormatToString(D3DFORMAT format, bool bWithPrefix) {
    TCHAR* pstr = NULL;
    switch(format) {
		case D3DFMT_UNKNOWN: pstr = TEXT("D3DFMT_UNKNOWN"); break;
		case D3DFMT_R8G8B8: pstr = TEXT("D3DFMT_R8G8B8"); break;
		case D3DFMT_A8R8G8B8: pstr = TEXT("D3DFMT_A8R8G8B8"); break;
		case D3DFMT_X8R8G8B8: pstr = TEXT("D3DFMT_X8R8G8B8"); break;
		case D3DFMT_R5G6B5: pstr = TEXT("D3DFMT_R5G6B5"); break;
		case D3DFMT_X1R5G5B5: pstr = TEXT("D3DFMT_X1R5G5B5"); break;
		case D3DFMT_A1R5G5B5: pstr = TEXT("D3DFMT_A1R5G5B5"); break;
		case D3DFMT_A4R4G4B4: pstr = TEXT("D3DFMT_A4R4G4B4"); break;
		case D3DFMT_R3G3B2: pstr = TEXT("D3DFMT_R3G3B2"); break;
		case D3DFMT_A8: pstr = TEXT("D3DFMT_A8"); break;
		case D3DFMT_A8R3G3B2: pstr = TEXT("D3DFMT_A8R3G3B2"); break;
		case D3DFMT_X4R4G4B4: pstr = TEXT("D3DFMT_X4R4G4B4"); break;
		case D3DFMT_A2B10G10R10: pstr = TEXT("D3DFMT_A2B10G10R10"); break;
		case D3DFMT_A8B8G8R8: pstr = TEXT("D3DFMT_A8B8G8R8"); break;
		case D3DFMT_X8B8G8R8: pstr = TEXT("D3DFMT_X8B8G8R8"); break;
		case D3DFMT_G16R16: pstr = TEXT("D3DFMT_G16R16"); break;
		case D3DFMT_A2R10G10B10: pstr = TEXT("D3DFMT_A2R10G10B10"); break;
		case D3DFMT_A16B16G16R16: pstr = TEXT("D3DFMT_A16B16G16R16"); break;
		case D3DFMT_A8P8: pstr = TEXT("D3DFMT_A8P8"); break;
		case D3DFMT_P8: pstr = TEXT("D3DFMT_P8"); break;
		case D3DFMT_L8: pstr = TEXT("D3DFMT_L8"); break;
		case D3DFMT_A8L8: pstr = TEXT("D3DFMT_A8L8"); break;
		case D3DFMT_A4L4: pstr = TEXT("D3DFMT_A4L4"); break;
		case D3DFMT_V8U8: pstr = TEXT("D3DFMT_V8U8"); break;
		case D3DFMT_L6V5U5: pstr = TEXT("D3DFMT_L6V5U5"); break;
		case D3DFMT_X8L8V8U8: pstr = TEXT("D3DFMT_X8L8V8U8"); break;
		case D3DFMT_Q8W8V8U8: pstr = TEXT("D3DFMT_Q8W8V8U8"); break;
		case D3DFMT_V16U16: pstr = TEXT("D3DFMT_V16U16"); break;
		case D3DFMT_A2W10V10U10: pstr = TEXT("D3DFMT_A2W10V10U10"); break;
		case D3DFMT_UYVY: pstr = TEXT("D3DFMT_UYVY"); break;
		case D3DFMT_R8G8_B8G8: pstr = TEXT("D3DFMT_R8G8_B8G8"); break;
		case D3DFMT_YUY2: pstr = TEXT("D3DFMT_YUY2"); break;
		case D3DFMT_G8R8_G8B8: pstr = TEXT("D3DFMT_G8R8_G8B8"); break;
		case D3DFMT_DXT1: pstr = TEXT("D3DFMT_DXT1"); break;
		case D3DFMT_DXT2: pstr = TEXT("D3DFMT_DXT2"); break;
		case D3DFMT_DXT3: pstr = TEXT("D3DFMT_DXT3"); break;
		case D3DFMT_DXT4: pstr = TEXT("D3DFMT_DXT4"); break;
		case D3DFMT_DXT5: pstr = TEXT("D3DFMT_DXT5"); break;
		case D3DFMT_D16_LOCKABLE: pstr = TEXT("D3DFMT_D16_LOCKABLE"); break;
		case D3DFMT_D32: pstr = TEXT("D3DFMT_D32"); break;
		case D3DFMT_D15S1: pstr = TEXT("D3DFMT_D15S1"); break;
		case D3DFMT_D24S8: pstr = TEXT("D3DFMT_D24S8"); break;
		case D3DFMT_D24X8: pstr = TEXT("D3DFMT_D24X8"); break;
		case D3DFMT_D24X4S4: pstr = TEXT("D3DFMT_D24X4S4"); break;
		case D3DFMT_D16: pstr = TEXT("D3DFMT_D16"); break;
		case D3DFMT_D32F_LOCKABLE: pstr = TEXT("D3DFMT_D32F_LOCKABLE"); break;
		case D3DFMT_D24FS8: pstr = TEXT("D3DFMT_D24FS8"); break;
		case D3DFMT_D32_LOCKABLE: pstr = TEXT("D3DFMT_D32_LOCKABLE"); break;
		case D3DFMT_S8_LOCKABLE: pstr = TEXT("D3DFMT_S8_LOCKABLE"); break;
		case D3DFMT_L16: pstr = TEXT("D3DFMT_L16"); break;
		case D3DFMT_VERTEXDATA: pstr = TEXT("D3DFMT_VERTEXDATA"); break;
		case D3DFMT_INDEX16: pstr = TEXT("D3DFMT_INDEX16"); break;
		case D3DFMT_INDEX32: pstr = TEXT("D3DFMT_INDEX32"); break;
		case D3DFMT_Q16W16V16U16: pstr = TEXT("D3DFMT_Q16W16V16U16"); break;
		case D3DFMT_MULTI2_ARGB8: pstr = TEXT("D3DFMT_MULTI2_ARGB8"); break;
		case D3DFMT_R16F: pstr = TEXT("D3DFMT_R16F"); break;
		case D3DFMT_G16R16F: pstr = TEXT("D3DFMT_G16R16F"); break;
		case D3DFMT_A16B16G16R16F: pstr = TEXT("D3DFMT_A16B16G16R16F"); break;
		case D3DFMT_R32F: pstr = TEXT("D3DFMT_R32F"); break;
		case D3DFMT_G32R32F: pstr = TEXT("D3DFMT_G32R32F"); break;
		case D3DFMT_A32B32G32R32F: pstr = TEXT("D3DFMT_A32B32G32R32F"); break;
		case D3DFMT_CxV8U8: pstr = TEXT("D3DFMT_CxV8U8"); break;
		case D3DFMT_A1: pstr = TEXT("D3DFMT_A1"); break;
		case D3DFMT_A2B10G10R10_XR_BIAS: pstr = TEXT("D3DFMT_A2B10G10R10_XR_BIAS"); break;
		case D3DFMT_BINARYBUFFER: pstr = TEXT("D3DFMT_BINARYBUFFER"); break;
		default:                     pstr = TEXT("       Unknown format"); break;
    }
    if( bWithPrefix )
        return pstr;
    else
        return pstr + lstrlen( TEXT("D3DFMT_") );
}

TCHAR* D3DSamplerStateTypeToString(D3DSAMPLERSTATETYPE state) {
    switch(state) {
		case D3DSAMP_ADDRESSU: return "D3DSAMP_ADDRESSU";
		case D3DSAMP_ADDRESSV: return "D3DSAMP_ADDRESSV";
		case D3DSAMP_ADDRESSW: return "D3DSAMP_ADDRESSW";
		case D3DSAMP_BORDERCOLOR: return "D3DSAMP_BORDERCOLOR";
		case D3DSAMP_MAGFILTER: return "D3DSAMP_MAGFILTER";
		case D3DSAMP_MINFILTER: return "D3DSAMP_MINFILTER";
		case D3DSAMP_MIPFILTER: return "D3DSAMP_MIPFILTER";
		case D3DSAMP_MIPMAPLODBIAS: return "D3DSAMP_MIPMAPLODBIAS";
		case D3DSAMP_MAXMIPLEVEL: return "D3DSAMP_MAXMIPLEVEL";
		case D3DSAMP_MAXANISOTROPY: return "D3DSAMP_MAXANISOTROPY";
		case D3DSAMP_SRGBTEXTURE: return "D3DSAMP_SRGBTEXTURE";
		case D3DSAMP_ELEMENTINDEX: return "D3DSAMP_ELEMENTINDEX";
		case D3DSAMP_DMAPOFFSET: return "D3DSAMP_DMAPOFFSET";
		case D3DSAMP_FORCE_DWORD: return "D3DSAMP_FORCE_DWORD";
	}
	return "Unknown Sampler State Type";
}

TCHAR* D3DDeclTypeToString(D3DDECLTYPE type) {
	switch(type) {
		case D3DDECLTYPE_FLOAT1: return "D3DDECLTYPE_FLOAT1";
		case D3DDECLTYPE_FLOAT2: return "D3DDECLTYPE_FLOAT2";
		case D3DDECLTYPE_FLOAT3: return "D3DDECLTYPE_FLOAT3";
		case D3DDECLTYPE_FLOAT4: return "D3DDECLTYPE_FLOAT4";
		case D3DDECLTYPE_D3DCOLOR: return "D3DDECLTYPE_D3DCOLOR";
		case D3DDECLTYPE_UBYTE4: return "D3DDECLTYPE_UBYTE4";
		case D3DDECLTYPE_SHORT2: return "D3DDECLTYPE_SHORT2";
		case D3DDECLTYPE_SHORT4: return "D3DDECLTYPE_SHORT4";
		case D3DDECLTYPE_UBYTE4N: return "D3DDECLTYPE_UBYTE4N";
		case D3DDECLTYPE_SHORT2N: return "D3DDECLTYPE_SHORT2N";
		case D3DDECLTYPE_SHORT4N: return "D3DDECLTYPE_SHORT4N";
		case D3DDECLTYPE_USHORT2N: return "D3DDECLTYPE_USHORT2N";
		case D3DDECLTYPE_USHORT4N: return "D3DDECLTYPE_USHORT4N";
		case D3DDECLTYPE_UDEC3: return "D3DDECLTYPE_UDEC3";
		case D3DDECLTYPE_DEC3N: return "D3DDECLTYPE_DEC3N";
		case D3DDECLTYPE_FLOAT16_2: return "D3DDECLTYPE_FLOAT16_2";
		case D3DDECLTYPE_FLOAT16_4: return "D3DDECLTYPE_FLOAT16_4";
		case D3DDECLTYPE_UNUSED: return "D3DDECLTYPE_UNUSED";
	}
	return "Unknown D3D decl type";
}

TCHAR* D3DDeclUsageToString(D3DDECLUSAGE type) {
	switch(type) {
		case D3DDECLUSAGE_POSITION: return "D3DDECLUSAGE_POSITION";
		case D3DDECLUSAGE_BLENDWEIGHT: return "D3DDECLUSAGE_BLENDWEIGHT";
		case D3DDECLUSAGE_BLENDINDICES: return "D3DDECLUSAGE_BLENDINDICES";
		case D3DDECLUSAGE_NORMAL: return "D3DDECLUSAGE_NORMAL";
		case D3DDECLUSAGE_PSIZE: return "D3DDECLUSAGE_PSIZE";
		case D3DDECLUSAGE_TEXCOORD: return "D3DDECLUSAGE_TEXCOORD";
		case D3DDECLUSAGE_TANGENT: return "D3DDECLUSAGE_TANGENT";
		case D3DDECLUSAGE_BINORMAL: return "D3DDECLUSAGE_BINORMAL";
		case D3DDECLUSAGE_TESSFACTOR: return "D3DDECLUSAGE_TESSFACTOR";
		case D3DDECLUSAGE_POSITIONT: return "D3DDECLUSAGE_POSITIONT";
		case D3DDECLUSAGE_COLOR: return "D3DDECLUSAGE_COLOR";
		case D3DDECLUSAGE_FOG: return "D3DDECLUSAGE_FOG";
		case D3DDECLUSAGE_DEPTH: return "D3DDECLUSAGE_DEPTH";
		case D3DDECLUSAGE_SAMPLE: return "D3DDECLUSAGE_SAMPLE";
	}
	return "Unknown D3D decl usage";
}

TCHAR* D3DDevTypeToString(D3DDEVTYPE type) {
	switch(type) {
		case D3DDEVTYPE_HAL: return "D3DDEVTYPE_HAL";
		case D3DDEVTYPE_REF: return "D3DDEVTYPE_REF";
		case D3DDEVTYPE_SW: return "D3DDEVTYPE_SW";
	}
	return "Unknown D3D dev type";
}

TCHAR* D3DResourceTypeToString(D3DRESOURCETYPE type) {
	switch(type) {
		case D3DRTYPE_SURFACE: return "D3DRTYPE_SURFACE";
		case D3DRTYPE_VOLUME: return "D3DRTYPE_VOLUME";
		case D3DRTYPE_TEXTURE: return "D3DRTYPE_TEXTURE";
		case D3DRTYPE_VOLUMETEXTURE: return "D3DRTYPE_VOLUMETEXTURE";
		case D3DRTYPE_CUBETEXTURE: return "D3DRTYPE_CUBETEXTURE";
		case D3DRTYPE_VERTEXBUFFER: return "D3DRTYPE_VERTEXBUFFER";
		case D3DRTYPE_INDEXBUFFER: return "D3DRTYPE_INDEXBUFFER";
	}
	return "Unknown D3D resource type";
}

TCHAR* D3DMultisampleTypeToString(D3DMULTISAMPLE_TYPE type) {
	switch(type) {
	case D3DMULTISAMPLE_NONE: return "D3DMULTISAMPLE_NONE";
    case D3DMULTISAMPLE_NONMASKABLE: return "D3DMULTISAMPLE_NONMASKABLE";
    case D3DMULTISAMPLE_2_SAMPLES: return "D3DMULTISAMPLE_2_SAMPLES";
    case D3DMULTISAMPLE_3_SAMPLES: return "D3DMULTISAMPLE_3_SAMPLES";
    case D3DMULTISAMPLE_4_SAMPLES: return "D3DMULTISAMPLE_4_SAMPLES";
    case D3DMULTISAMPLE_5_SAMPLES: return "D3DMULTISAMPLE_5_SAMPLES";
    case D3DMULTISAMPLE_6_SAMPLES: return "D3DMULTISAMPLE_6_SAMPLES";
    case D3DMULTISAMPLE_7_SAMPLES: return "D3DMULTISAMPLE_7_SAMPLES";
    case D3DMULTISAMPLE_8_SAMPLES: return "D3DMULTISAMPLE_8_SAMPLES";
    case D3DMULTISAMPLE_9_SAMPLES: return "D3DMULTISAMPLE_9_SAMPLES";
    case D3DMULTISAMPLE_10_SAMPLES: return "D3DMULTISAMPLE_10_SAMPLES";
    case D3DMULTISAMPLE_11_SAMPLES: return "D3DMULTISAMPLE_11_SAMPLES";
    case D3DMULTISAMPLE_12_SAMPLES: return "D3DMULTISAMPLE_12_SAMPLES";
    case D3DMULTISAMPLE_13_SAMPLES: return "D3DMULTISAMPLE_13_SAMPLES";
    case D3DMULTISAMPLE_14_SAMPLES: return "D3DMULTISAMPLE_14_SAMPLES";
    case D3DMULTISAMPLE_15_SAMPLES: return "D3DMULTISAMPLE_15_SAMPLES";
    case D3DMULTISAMPLE_16_SAMPLES: return "D3DMULTISAMPLE_16_SAMPLES";
	}
	return "Unknown D3D multisample type";
}

TCHAR* D3DSwapEffectToString(D3DSWAPEFFECT swap) {
	switch(swap) {
	case D3DSWAPEFFECT_DISCARD: return "D3DSWAPEFFECT_DISCARD";
    case D3DSWAPEFFECT_FLIP: return "D3DSWAPEFFECT_FLIP";
    case D3DSWAPEFFECT_COPY: return "D3DSWAPEFFECT_COPY";
    case D3DSWAPEFFECT_OVERLAY: return "D3DSWAPEFFECT_OVERLAY";
    case D3DSWAPEFFECT_FLIPEX: return "D3DSWAPEFFECT_FLIPEX";
	}
	return "Unknown swap effect";
}

TCHAR* D3DRenderStateTypeToString(D3DRENDERSTATETYPE s) {
	switch(s) {
	case D3DRS_ZENABLE: return "D3DRS_ZENABLE";    
    case D3DRS_FILLMODE: return "D3DRS_FILLMODE";    
    case D3DRS_SHADEMODE: return "D3DRS_SHADEMODE";    
    case D3DRS_ZWRITEENABLE: return "D3DRS_ZWRITEENABLE";   
    case D3DRS_ALPHATESTENABLE: return "D3DRS_ALPHATESTENABLE";   
    case D3DRS_LASTPIXEL: return "D3DRS_LASTPIXEL";   
    case D3DRS_SRCBLEND: return "D3DRS_SRCBLEND";   
    case D3DRS_DESTBLEND: return "D3DRS_DESTBLEND";   
    case D3DRS_CULLMODE: return "D3DRS_CULLMODE";   
    case D3DRS_ZFUNC: return "D3DRS_ZFUNC";   
    case D3DRS_ALPHAREF: return "D3DRS_ALPHAREF";   
    case D3DRS_ALPHAFUNC: return "D3DRS_ALPHAFUNC";   
    case D3DRS_DITHERENABLE: return "D3DRS_DITHERENABLE";   
    case D3DRS_ALPHABLENDENABLE: return "D3DRS_ALPHABLENDENABLE";   
    case D3DRS_FOGENABLE: return "D3DRS_FOGENABLE";   
    case D3DRS_SPECULARENABLE: return "D3DRS_SPECULARENABLE";   
    case D3DRS_FOGCOLOR: return "D3DRS_FOGCOLOR";   
    case D3DRS_FOGTABLEMODE: return "D3DRS_FOGTABLEMODE";   
    case D3DRS_FOGSTART: return "D3DRS_FOGSTART";   
    case D3DRS_FOGEND: return "D3DRS_FOGEND";   
    case D3DRS_FOGDENSITY: return "D3DRS_FOGDENSITY";   
    case D3DRS_RANGEFOGENABLE: return "D3DRS_RANGEFOGENABLE";   
    case D3DRS_STENCILENABLE: return "D3DRS_STENCILENABLE";   
    case D3DRS_STENCILFAIL: return "D3DRS_STENCILFAIL";   
    case D3DRS_STENCILZFAIL: return "D3DRS_STENCILZFAIL";   
    case D3DRS_STENCILPASS: return "D3DRS_STENCILPASS";   
    case D3DRS_STENCILFUNC: return "D3DRS_STENCILFUNC";   
    case D3DRS_STENCILREF: return "D3DRS_STENCILREF";   
    case D3DRS_STENCILMASK: return "D3DRS_STENCILMASK";   
    case D3DRS_STENCILWRITEMASK: return "D3DRS_STENCILWRITEMASK";   
    case D3DRS_TEXTUREFACTOR: return "D3DRS_TEXTUREFACTOR";   
    case D3DRS_WRAP0: return "D3DRS_WRAP0";  
    case D3DRS_WRAP1: return "D3DRS_WRAP1";  
    case D3DRS_WRAP2: return "D3DRS_WRAP2";  
    case D3DRS_WRAP3: return "D3DRS_WRAP3";  
    case D3DRS_WRAP4: return "D3DRS_WRAP4";  
    case D3DRS_WRAP5: return "D3DRS_WRAP5";  
    case D3DRS_WRAP6: return "D3DRS_WRAP6";  
    case D3DRS_WRAP7: return "D3DRS_WRAP7";  
    case D3DRS_CLIPPING: return "D3DRS_CLIPPING";
    case D3DRS_LIGHTING: return "D3DRS_LIGHTING";
    case D3DRS_AMBIENT: return "D3DRS_AMBIENT";
    case D3DRS_FOGVERTEXMODE: return "D3DRS_FOGVERTEXMODE";
    case D3DRS_COLORVERTEX: return "D3DRS_COLORVERTEX";
    case D3DRS_LOCALVIEWER: return "D3DRS_LOCALVIEWER";
    case D3DRS_NORMALIZENORMALS: return "D3DRS_NORMALIZENORMALS";
    case D3DRS_DIFFUSEMATERIALSOURCE: return "D3DRS_DIFFUSEMATERIALSOURCE";
    case D3DRS_SPECULARMATERIALSOURCE: return "D3DRS_SPECULARMATERIALSOURCE";
    case D3DRS_AMBIENTMATERIALSOURCE: return "D3DRS_AMBIENTMATERIALSOURCE";
    case D3DRS_EMISSIVEMATERIALSOURCE: return "D3DRS_EMISSIVEMATERIALSOURCE";
    case D3DRS_VERTEXBLEND: return "D3DRS_VERTEXBLEND";
    case D3DRS_CLIPPLANEENABLE: return "D3DRS_CLIPPLANEENABLE";
    case D3DRS_POINTSIZE: return "D3DRS_POINTSIZE";   
    case D3DRS_POINTSIZE_MIN: return "D3DRS_POINTSIZE_MIN";   
    case D3DRS_POINTSPRITEENABLE: return "D3DRS_POINTSPRITEENABLE";   
    case D3DRS_POINTSCALEENABLE: return "D3DRS_POINTSCALEENABLE";   
    case D3DRS_POINTSCALE_A: return "D3DRS_POINTSCALE_A";   
    case D3DRS_POINTSCALE_B: return "D3DRS_POINTSCALE_B";   
    case D3DRS_POINTSCALE_C: return "D3DRS_POINTSCALE_C";   
    case D3DRS_MULTISAMPLEANTIALIAS: return "D3DRS_MULTISAMPLEANTIALIAS";  
    case D3DRS_MULTISAMPLEMASK: return "D3DRS_MULTISAMPLEMASK";  
    case D3DRS_PATCHEDGESTYLE: return "D3DRS_PATCHEDGESTYLE";  
    case D3DRS_DEBUGMONITORTOKEN: return "D3DRS_DEBUGMONITORTOKEN";  
    case D3DRS_POINTSIZE_MAX: return "D3DRS_POINTSIZE_MAX";   
    case D3DRS_INDEXEDVERTEXBLENDENABLE: return "D3DRS_INDEXEDVERTEXBLENDENABLE";
    case D3DRS_COLORWRITEENABLE: return "D3DRS_COLORWRITEENABLE";  
    case D3DRS_TWEENFACTOR: return "D3DRS_TWEENFACTOR";   
    case D3DRS_BLENDOP: return "D3DRS_BLENDOP";   
    case D3DRS_POSITIONDEGREE: return "D3DRS_POSITIONDEGREE";   
    case D3DRS_NORMALDEGREE: return "D3DRS_NORMALDEGREE";   
    case D3DRS_SCISSORTESTENABLE: return "D3DRS_SCISSORTESTENABLE";
    case D3DRS_SLOPESCALEDEPTHBIAS: return "D3DRS_SLOPESCALEDEPTHBIAS";
    case D3DRS_ANTIALIASEDLINEENABLE: return "D3DRS_ANTIALIASEDLINEENABLE";
    case D3DRS_MINTESSELLATIONLEVEL: return "D3DRS_MINTESSELLATIONLEVEL";
    case D3DRS_MAXTESSELLATIONLEVEL: return "D3DRS_MAXTESSELLATIONLEVEL";
    case D3DRS_ADAPTIVETESS_X: return "D3DRS_ADAPTIVETESS_X";
    case D3DRS_ADAPTIVETESS_Y: return "D3DRS_ADAPTIVETESS_Y";
    case D3DRS_ADAPTIVETESS_Z: return "D3DRS_ADAPTIVETESS_Z";
    case D3DRS_ADAPTIVETESS_W: return "D3DRS_ADAPTIVETESS_W";
    case D3DRS_ENABLEADAPTIVETESSELLATION: return "D3DRS_ENABLEADAPTIVETESSELLATION";
    case D3DRS_TWOSIDEDSTENCILMODE: return "D3DRS_TWOSIDEDSTENCILMODE";   
    case D3DRS_CCW_STENCILFAIL: return "D3DRS_CCW_STENCILFAIL";   
    case D3DRS_CCW_STENCILZFAIL: return "D3DRS_CCW_STENCILZFAIL";   
    case D3DRS_CCW_STENCILPASS: return "D3DRS_CCW_STENCILPASS";   
    case D3DRS_CCW_STENCILFUNC: return "D3DRS_CCW_STENCILFUNC";   
    case D3DRS_COLORWRITEENABLE1: return "D3DRS_COLORWRITEENABLE1";   
    case D3DRS_COLORWRITEENABLE2: return "D3DRS_COLORWRITEENABLE2";   
    case D3DRS_COLORWRITEENABLE3: return "D3DRS_COLORWRITEENABLE3";   
    case D3DRS_BLENDFACTOR: return "D3DRS_BLENDFACTOR";   
    case D3DRS_SRGBWRITEENABLE: return "D3DRS_SRGBWRITEENABLE";   
    case D3DRS_DEPTHBIAS: return "D3DRS_DEPTHBIAS";
    case D3DRS_WRAP8: return "D3DRS_WRAP8";   
    case D3DRS_WRAP9: return "D3DRS_WRAP9";
    case D3DRS_WRAP10: return "D3DRS_WRAP10";
    case D3DRS_WRAP11: return "D3DRS_WRAP11";
    case D3DRS_WRAP12: return "D3DRS_WRAP12";
    case D3DRS_WRAP13: return "D3DRS_WRAP13";
    case D3DRS_WRAP14: return "D3DRS_WRAP14";
    case D3DRS_WRAP15: return "D3DRS_WRAP15";
    case D3DRS_SEPARATEALPHABLENDENABLE: return "D3DRS_SEPARATEALPHABLENDENABLE";  
    case D3DRS_SRCBLENDALPHA: return "D3DRS_SRCBLENDALPHA";  
    case D3DRS_DESTBLENDALPHA: return "D3DRS_DESTBLENDALPHA";  
    case D3DRS_BLENDOPALPHA: return "D3DRS_BLENDOPALPHA";
	}
	return "Unknown render state";
}

TCHAR* D3DPoolToString(D3DPOOL pool) {
	switch(pool) {
	case D3DPOOL_DEFAULT: return "D3DPOOL_DEFAULT";
	case D3DPOOL_MANAGED: return "D3DPOOL_MANAGED";
	case D3DPOOL_SYSTEMMEM: return "D3DPOOL_SYSTEMMEM";
	case D3DPOOL_SCRATCH: return "D3DPOOL_SCRATCH";
	}
	return "Unknown d3d pool";
}

TCHAR* D3DPrimitiveTypeToString(D3DPRIMITIVETYPE prim) {
	switch(prim) {
	case D3DPT_POINTLIST: return "D3DPT_POINTLIST";
	case D3DPT_LINELIST: return "D3DPT_LINELIST";
	case D3DPT_TRIANGLELIST: return "D3DPT_TRIANGLELIST";
	case D3DPT_TRIANGLESTRIP: return "D3DPT_TRIANGLESTRIP";
	case D3DPT_TRIANGLEFAN: return "D3DPT_TRIANGLEFAN";
	}
	return "Unknown primitive type";
}



string D3DMatrixToString(const D3DMATRIX* pMatrix) {
	std::stringstream ss;
	if(!pMatrix) return string("NULL_MATRIX");
	for(int i=0; i<4; ++i) {
		ss << " | ";
		for(int j=0; j<4; ++j) {
			ss << format("%6.2f ", pMatrix->m[i][j]);
		}
		ss << "\n";
	}
	return ss.str();
}

string D3DPresentExFlagsToString(DWORD flags) {
	string ret;
	if(flags & D3DPRESENT_DONOTFLIP) ret += "D3DPRESENT_DONOTFLIP | ";
	if(flags & D3DPRESENT_DONOTWAIT) ret += "D3DPRESENT_DONOTWAIT | ";
	if(flags & D3DPRESENT_FORCEIMMEDIATE) ret += "D3DPRESENT_FORCEIMMEDIATE | ";
	if(flags & D3DPRESENT_LINEAR_CONTENT) ret += "D3DPRESENT_LINEAR_CONTENT | ";
	if(flags & D3DPRESENT_VIDEO_RESTRICT_TO_MONITOR) ret += "D3DPRESENT_VIDEO_RESTRICT_TO_MONITOR | ";
	if(flags & D3DPRESENT_UPDATEOVERLAYONLY) ret += "D3DPRESENT_UPDATEOVERLAYONLY | ";
	if(flags & D3DPRESENT_HIDEOVERLAY) ret += "D3DPRESENT_HIDEOVERLAY | ";
	if(flags & D3DPRESENT_UPDATECOLORKEY) ret += "D3DPRESENT_UPDATECOLORKEY | ";
	return ret;
}

string D3DSurfaceDescToString(const D3DSURFACE_DESC& desc) {
	return format("%dx%d, format: %s, usage: %d, ms type: %s, ms qual: %d, mem pool: %s", desc.Width, desc.Height, D3DFormatToString(desc.Format), desc.Usage, 
		D3DMultisampleTypeToString(desc.MultiSampleType), desc.MultiSampleQuality, D3DPoolToString(desc.Pool));
}


void logRenderState(IDirect3DDevice9* dev, int level) {
	DWORD result = 0;
	dev->GetRenderState(D3DRS_ZENABLE, &result); SDLOG(level, "D3DRS_ZENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_FILLMODE, &result); SDLOG(level, "D3DRS_FILLMODE: %d\n", result);
	dev->GetRenderState(D3DRS_SHADEMODE, &result); SDLOG(level, "D3DRS_SHADEMODE: %d\n", result);
	dev->GetRenderState(D3DRS_ZWRITEENABLE, &result); SDLOG(level, "D3DRS_ZWRITEENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_ALPHATESTENABLE, &result); SDLOG(level, "D3DRS_ALPHATESTENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_LASTPIXEL, &result); SDLOG(level, "D3DRS_LASTPIXEL: %d\n", result);
	dev->GetRenderState(D3DRS_SRCBLEND, &result); SDLOG(level, "D3DRS_SRCBLEND: %d\n", result);
	dev->GetRenderState(D3DRS_DESTBLEND, &result); SDLOG(level, "D3DRS_DESTBLEND: %d\n", result);
	dev->GetRenderState(D3DRS_CULLMODE, &result); SDLOG(level, "D3DRS_CULLMODE: %d\n", result);
	dev->GetRenderState(D3DRS_ZFUNC, &result); SDLOG(level, "D3DRS_ZFUNC: %d\n", result);
	dev->GetRenderState(D3DRS_ALPHAREF, &result); SDLOG(level, "D3DRS_ALPHAREF: %d\n", result);
	dev->GetRenderState(D3DRS_ALPHAFUNC, &result); SDLOG(level, "D3DRS_ALPHAFUNC: %d\n", result);
	dev->GetRenderState(D3DRS_DITHERENABLE, &result); SDLOG(level, "D3DRS_DITHERENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_ALPHABLENDENABLE, &result); SDLOG(level, "D3DRS_ALPHABLENDENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_FOGENABLE, &result); SDLOG(level, "D3DRS_FOGENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_SPECULARENABLE, &result); SDLOG(level, "D3DRS_SPECULARENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_FOGCOLOR, &result); SDLOG(level, "D3DRS_FOGCOLOR: %d\n", result);
	dev->GetRenderState(D3DRS_FOGTABLEMODE, &result); SDLOG(level, "D3DRS_FOGTABLEMODE: %d\n", result);
	dev->GetRenderState(D3DRS_FOGSTART, &result); SDLOG(level, "D3DRS_FOGSTART: %d\n", result);
	dev->GetRenderState(D3DRS_FOGEND, &result); SDLOG(level, "D3DRS_FOGEND: %d\n", result);
	dev->GetRenderState(D3DRS_FOGDENSITY, &result); SDLOG(level, "D3DRS_FOGDENSITY: %d\n", result);
	dev->GetRenderState(D3DRS_RANGEFOGENABLE, &result); SDLOG(level, "D3DRS_RANGEFOGENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_STENCILENABLE, &result); SDLOG(level, "D3DRS_STENCILENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_STENCILFAIL, &result); SDLOG(level, "D3DRS_STENCILFAIL: %d\n", result);
	dev->GetRenderState(D3DRS_STENCILZFAIL, &result); SDLOG(level, "D3DRS_STENCILZFAIL: %d\n", result);
	dev->GetRenderState(D3DRS_STENCILPASS, &result); SDLOG(level, "D3DRS_STENCILPASS: %d\n", result);
	dev->GetRenderState(D3DRS_STENCILFUNC, &result); SDLOG(level, "D3DRS_STENCILFUNC: %d\n", result);
	dev->GetRenderState(D3DRS_STENCILREF, &result); SDLOG(level, "D3DRS_STENCILREF: %d\n", result);
	dev->GetRenderState(D3DRS_STENCILMASK, &result); SDLOG(level, "D3DRS_STENCILMASK: %d\n", result);
	dev->GetRenderState(D3DRS_STENCILWRITEMASK, &result); SDLOG(level, "D3DRS_STENCILWRITEMASK: %d\n", result);
	dev->GetRenderState(D3DRS_TEXTUREFACTOR, &result); SDLOG(level, "D3DRS_TEXTUREFACTOR: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP0, &result); SDLOG(level, "D3DRS_WRAP0: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP1, &result); SDLOG(level, "D3DRS_WRAP1: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP2, &result); SDLOG(level, "D3DRS_WRAP2: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP3, &result); SDLOG(level, "D3DRS_WRAP3: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP4, &result); SDLOG(level, "D3DRS_WRAP4: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP5, &result); SDLOG(level, "D3DRS_WRAP5: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP6, &result); SDLOG(level, "D3DRS_WRAP6: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP7, &result); SDLOG(level, "D3DRS_WRAP7: %d\n", result);
	dev->GetRenderState(D3DRS_CLIPPING, &result); SDLOG(level, "D3DRS_CLIPPING: %d\n", result);
	dev->GetRenderState(D3DRS_LIGHTING, &result); SDLOG(level, "D3DRS_LIGHTING: %d\n", result);
	dev->GetRenderState(D3DRS_AMBIENT, &result); SDLOG(level, "D3DRS_AMBIENT: %d\n", result);
	dev->GetRenderState(D3DRS_FOGVERTEXMODE, &result); SDLOG(level, "D3DRS_FOGVERTEXMODE: %d\n", result);
	dev->GetRenderState(D3DRS_COLORVERTEX, &result); SDLOG(level, "D3DRS_COLORVERTEX: %d\n", result);
	dev->GetRenderState(D3DRS_LOCALVIEWER, &result); SDLOG(level, "D3DRS_LOCALVIEWER: %d\n", result);
	dev->GetRenderState(D3DRS_NORMALIZENORMALS, &result); SDLOG(level, "D3DRS_NORMALIZENORMALS: %d\n", result);
	dev->GetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, &result); SDLOG(level, "D3DRS_DIFFUSEMATERIALSOURCE: %d\n", result);
	dev->GetRenderState(D3DRS_SPECULARMATERIALSOURCE, &result); SDLOG(level, "D3DRS_SPECULARMATERIALSOURCE: %d\n", result);
	dev->GetRenderState(D3DRS_AMBIENTMATERIALSOURCE, &result); SDLOG(level, "D3DRS_AMBIENTMATERIALSOURCE: %d\n", result);
	dev->GetRenderState(D3DRS_EMISSIVEMATERIALSOURCE, &result); SDLOG(level, "D3DRS_EMISSIVEMATERIALSOURCE: %d\n", result);
	dev->GetRenderState(D3DRS_VERTEXBLEND, &result); SDLOG(level, "D3DRS_VERTEXBLEND: %d\n", result);
	dev->GetRenderState(D3DRS_CLIPPLANEENABLE, &result); SDLOG(level, "D3DRS_CLIPPLANEENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_POINTSIZE, &result); SDLOG(level, "D3DRS_POINTSIZE: %d\n", result);
	dev->GetRenderState(D3DRS_POINTSIZE_MIN, &result); SDLOG(level, "D3DRS_POINTSIZE_MIN: %d\n", result);
	dev->GetRenderState(D3DRS_POINTSPRITEENABLE, &result); SDLOG(level, "D3DRS_POINTSPRITEENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_POINTSCALEENABLE, &result); SDLOG(level, "D3DRS_POINTSCALEENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_POINTSCALE_A, &result); SDLOG(level, "D3DRS_POINTSCALE_A: %d\n", result);
	dev->GetRenderState(D3DRS_POINTSCALE_B, &result); SDLOG(level, "D3DRS_POINTSCALE_B: %d\n", result);
	dev->GetRenderState(D3DRS_POINTSCALE_C, &result); SDLOG(level, "D3DRS_POINTSCALE_C: %d\n", result);
	dev->GetRenderState(D3DRS_MULTISAMPLEANTIALIAS, &result); SDLOG(level, "D3DRS_MULTISAMPLEANTIALIAS: %d\n", result);
	dev->GetRenderState(D3DRS_MULTISAMPLEMASK, &result); SDLOG(level, "D3DRS_MULTISAMPLEMASK: %d\n", result);
	dev->GetRenderState(D3DRS_PATCHEDGESTYLE, &result); SDLOG(level, "D3DRS_PATCHEDGESTYLE: %d\n", result);
	dev->GetRenderState(D3DRS_DEBUGMONITORTOKEN, &result); SDLOG(level, "D3DRS_DEBUGMONITORTOKEN: %d\n", result);
	dev->GetRenderState(D3DRS_POINTSIZE_MAX, &result); SDLOG(level, "D3DRS_POINTSIZE_MAX: %d\n", result);
	dev->GetRenderState(D3DRS_INDEXEDVERTEXBLENDENABLE, &result); SDLOG(level, "D3DRS_INDEXEDVERTEXBLENDENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_COLORWRITEENABLE, &result); SDLOG(level, "D3DRS_COLORWRITEENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_TWEENFACTOR, &result); SDLOG(level, "D3DRS_TWEENFACTOR: %d\n", result);
	dev->GetRenderState(D3DRS_BLENDOP, &result); SDLOG(level, "D3DRS_BLENDOP: %d\n", result);
	dev->GetRenderState(D3DRS_POSITIONDEGREE, &result); SDLOG(level, "D3DRS_POSITIONDEGREE: %d\n", result);
	dev->GetRenderState(D3DRS_NORMALDEGREE, &result); SDLOG(level, "D3DRS_NORMALDEGREE: %d\n", result);
	dev->GetRenderState(D3DRS_SCISSORTESTENABLE, &result); SDLOG(level, "D3DRS_SCISSORTESTENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_SLOPESCALEDEPTHBIAS, &result); SDLOG(level, "D3DRS_SLOPESCALEDEPTHBIAS: %d\n", result);
	dev->GetRenderState(D3DRS_ANTIALIASEDLINEENABLE, &result); SDLOG(level, "D3DRS_ANTIALIASEDLINEENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_MINTESSELLATIONLEVEL, &result); SDLOG(level, "D3DRS_MINTESSELLATIONLEVEL: %d\n", result);
	dev->GetRenderState(D3DRS_MAXTESSELLATIONLEVEL, &result); SDLOG(level, "D3DRS_MAXTESSELLATIONLEVEL: %d\n", result);
	dev->GetRenderState(D3DRS_ADAPTIVETESS_X, &result); SDLOG(level, "D3DRS_ADAPTIVETESS_X: %d\n", result);
	dev->GetRenderState(D3DRS_ADAPTIVETESS_Y, &result); SDLOG(level, "D3DRS_ADAPTIVETESS_Y: %d\n", result);
	dev->GetRenderState(D3DRS_ADAPTIVETESS_Z, &result); SDLOG(level, "D3DRS_ADAPTIVETESS_Z: %d\n", result);
	dev->GetRenderState(D3DRS_ADAPTIVETESS_W, &result); SDLOG(level, "D3DRS_ADAPTIVETESS_W: %d\n", result);
	dev->GetRenderState(D3DRS_ENABLEADAPTIVETESSELLATION, &result); SDLOG(level, "D3DRS_ENABLEADAPTIVETESSELLATION: %d\n", result);
	dev->GetRenderState(D3DRS_TWOSIDEDSTENCILMODE, &result); SDLOG(level, "D3DRS_TWOSIDEDSTENCILMODE: %d\n", result);
	dev->GetRenderState(D3DRS_CCW_STENCILFAIL, &result); SDLOG(level, "D3DRS_CCW_STENCILFAIL: %d\n", result);
	dev->GetRenderState(D3DRS_CCW_STENCILZFAIL, &result); SDLOG(level, "D3DRS_CCW_STENCILZFAIL: %d\n", result);
	dev->GetRenderState(D3DRS_CCW_STENCILPASS, &result); SDLOG(level, "D3DRS_CCW_STENCILPASS: %d\n", result);
	dev->GetRenderState(D3DRS_CCW_STENCILFUNC, &result); SDLOG(level, "D3DRS_CCW_STENCILFUNC: %d\n", result);
	dev->GetRenderState(D3DRS_COLORWRITEENABLE1, &result); SDLOG(level, "D3DRS_COLORWRITEENABLE1: %d\n", result);
	dev->GetRenderState(D3DRS_COLORWRITEENABLE2, &result); SDLOG(level, "D3DRS_COLORWRITEENABLE2: %d\n", result);
	dev->GetRenderState(D3DRS_COLORWRITEENABLE3, &result); SDLOG(level, "D3DRS_COLORWRITEENABLE3: %d\n", result);
	dev->GetRenderState(D3DRS_BLENDFACTOR, &result); SDLOG(level, "D3DRS_BLENDFACTOR: %d\n", result);
	dev->GetRenderState(D3DRS_SRGBWRITEENABLE, &result); SDLOG(level, "D3DRS_SRGBWRITEENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_DEPTHBIAS, &result); SDLOG(level, "D3DRS_DEPTHBIAS: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP8, &result); SDLOG(level, "D3DRS_WRAP8: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP9, &result); SDLOG(level, "D3DRS_WRAP9: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP10, &result); SDLOG(level, "D3DRS_WRAP10: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP11, &result); SDLOG(level, "D3DRS_WRAP11: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP12, &result); SDLOG(level, "D3DRS_WRAP12: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP13, &result); SDLOG(level, "D3DRS_WRAP13: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP14, &result); SDLOG(level, "D3DRS_WRAP14: %d\n", result);
	dev->GetRenderState(D3DRS_WRAP15, &result); SDLOG(level, "D3DRS_WRAP15: %d\n", result);
	dev->GetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, &result); SDLOG(level, "D3DRS_SEPARATEALPHABLENDENABLE: %d\n", result);
	dev->GetRenderState(D3DRS_SRCBLENDALPHA, &result); SDLOG(level, "D3DRS_SRCBLENDALPHA: %d\n", result);
	dev->GetRenderState(D3DRS_DESTBLENDALPHA, &result); SDLOG(level, "D3DRS_DESTBLENDALPHA: %d\n", result);
	dev->GetRenderState(D3DRS_BLENDOPALPHA, &result); SDLOG(level, "D3DRS_BLENDOPALPHA: %d\n", result);
}
