#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "ImageStitching.h"
#include "kernel.cuh"



void ImageStitching::BrightingWithCUDA(unsigned char* Input_Image, int Height, int Width, int Channels) {
	unsigned char* Dev_Input_Image = NULL;

	//Gpu üzerinde alan aç
	cudaMalloc((void**)&Dev_Input_Image, Height * Width * Channels);

	//Datayı CPU dan GPU ya taşı
	cudaMemcpy(Dev_Input_Image, Input_Image, Height * Width * Channels, cudaMemcpyHostToDevice);

	dim3 Grid_Image(Width, Height);
	Brighting << <Grid_Image, 16 >> > (Dev_Input_Image, Channels);

	//Tekrar Cpu'ya kopyala
	cudaMemcpy(Input_Image, Dev_Input_Image, Height * Width * Channels, cudaMemcpyDeviceToHost);

	//Gpu bellek serbest bırak
	cudaFree(Dev_Input_Image);
}

__global__ void Brighting(unsigned char* Image, int Channels) {
	int x = blockIdx.x;
	int y = blockIdx.y;
	int idx = (x + y * gridDim.x) * Channels;

	//Piksel kanalları 10 değeri kadar artır.
	for (int i = 0; i < Channels; i++) {
		Image[idx + i] = Image[idx + i] + 10
			;
	}
}
