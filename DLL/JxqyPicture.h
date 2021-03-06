#ifndef JXQYPICTURE_H_INCLUDED
#define JXQYPICTURE_H_INCLUDED

#ifdef BUILDING_DLL
#define JXQYPICTURE_DLL __declspec(dllexport)
#else
#define JXQYPICTURE_DLL __declspec(dllimport)
#endif
#define DLL_CALLCONV __stdcall

typedef unsigned char BYTE,*PBYTE;

#ifdef __cplusplus
extern "C" {
#endif

//读取文件，读取成功返回true
JXQYPICTURE_DLL bool DLL_CALLCONV JX_ReadFile(const char* filePath);
//读取文件后，获得帧数量
JXQYPICTURE_DLL int DLL_CALLCONV JX_GetFrameCount();
//获得文件的画布大小
JXQYPICTURE_DLL int DLL_CALLCONV JX_GetCanvasWidth();
JXQYPICTURE_DLL int DLL_CALLCONV JX_GetCanvasHeight();
//设置透明域
//像素透明度小于mask的为透明
JXQYPICTURE_DLL void DLL_CALLCONV JX_SetAlphaMask(BYTE mask);
//获得帧图像数据，每帧图片得长宽都是画布大小，失败返回NULL
//RGBA,BGRA,RGB,BGR为颜色循序
//数据的循序是从左到右，从上到下。
//即：0 1 2 3
//    4 5 6 7
//    . . .
//返回的data不需要时要使用JX_FreeData释放
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetFrameDataRGBA(int index);
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetFrameDataBGRA(int index);
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetFrameDataRGB(int index);
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetFrameDataBGR(int index);
//获得帧图像数据，每帧图片得长宽都是画布大小，失败返回NULL
//RGBA,BGRA,RGB,BGR为颜色循序
//数据的循序是从左到右，从下到上。
//即：8 9 . .
//    4 5 6 7
//    0 1 2 3
//返回的data不需要时要使用JX_FreeData释放
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetFrameDataRGBA_R(int index);
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetFrameDataBGRA_R(int index);
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetFrameDataRGB_R(int index);
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetFrameDataBGR_R(int index);
//读取MPC文件
JXQYPICTURE_DLL bool DLL_CALLCONV JX_ReadMpcFile(const char* path, int *frameCount);
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetMpcFrameDataRGBA_R(int index, int *width, int *height);
//读取ASF文件
JXQYPICTURE_DLL bool DLL_CALLCONV JX_ReadAsfFile(const char* path, int *frameCount);
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetAsfFrameDataRGBA_R(int index, int *width, int *height);
//读取RPC文件
JXQYPICTURE_DLL bool DLL_CALLCONV JX_ReadRpcFile(const char* path, int *frameCount);
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetRpcFrameDataRGBA_R(int index, int *width, int *height);
//读取SPR文件
JXQYPICTURE_DLL bool DLL_CALLCONV JX_ReadSprFile(const char* path, int *frameCount);
JXQYPICTURE_DLL PBYTE DLL_CALLCONV JX_GetSprFrameDataRGBA_R(int index, int *width, int *height);

//释放资源
JXQYPICTURE_DLL void DLL_CALLCONV JX_FreeData(PBYTE data);

#ifdef __cplusplus
}
#endif

#endif // JXQYPICTURE_H_INCLUDED
