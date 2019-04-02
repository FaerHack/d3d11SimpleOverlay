#pragma once
#include <iostream>
#include <array>
#include <Windows.h>
#include <d3d11_1.h>
#include <directxcolors.h>
#include <D3DX11.h>
#include <xnamath.h>
#include <d3dcompiler.h>
#include "Effects.h"
#include <vector>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")

struct VertexTemplate
{
	XMFLOAT3 Pos;
	XMFLOAT4 color;
};
class DrawingClass
{
public:
	HRESULT CompileShaderFromMemory(const char* szdata, SIZE_T len, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
	HRESULT InitWindow(const char* ClassName);
	HRESULT InitDevice(bool Multisampling);
	void    Render();
	HRESULT DrawLine(XMFLOAT2 pos1, XMFLOAT2 pos2);
	HRESULT DrawCircle(XMFLOAT2 center, UINT radius, UINT numVertices);
	void    DispatchInput();
	DrawingClass(const char* WndClassName, int width, int height, bool Multisampling):Width{width},Height{height}
	{
		InitWindow(WndClassName);
		InitDevice(Multisampling);
		DispatchInput();
	}
private:
	HINSTANCE                 g_hInst = NULL;
	HWND                      g_hWnd = NULL;
	D3D_DRIVER_TYPE           g_driverType = D3D_DRIVER_TYPE_HARDWARE;
	D3D_FEATURE_LEVEL         g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device*             g_pd3dDevice = nullptr;
	ID3D11DeviceContext*      g_pImmediateContext = nullptr;
	IDXGISwapChain*           g_pSwapChain = nullptr;
	ID3D11RenderTargetView*   g_pRenderTargetView = nullptr;
	ID3D11VertexShader*       g_pVertexShader = NULL;
	ID3D11PixelShader*        g_pPixelShader = NULL;
	ID3D11InputLayout*        g_pVertexLayout = NULL;
	ID3D11Buffer*             g_pVertexBuffer = NULL;
	ID3D11Texture2D*          g_pDepthStencilBuffer = NULL;
	ID3D11DepthStencilView*   g_pDepthView = NULL;
	ID3D11DepthStencilState*  g_pDepthState = NULL;
	ID3D11RasterizerState*    g_pRasterizerState = NULL;
	int Width;
	int Height;
};