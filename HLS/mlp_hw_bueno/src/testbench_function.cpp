#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "mlp.h"


#define N_PRUEBAS 10
#define NIMAGES 10000
#define IMGPIXELES 784
#define C_OUT 10

const int m_imageCount = 10000;

float m_pixelsFloat[IMGPIXELES*NIMAGES];
uint8_t* m_labels;
uint8_t* m_pixels;
uint8_t* m_labelData[8+NIMAGES];
uint8_t* m_imageData[16+NIMAGES*IMGPIXELES];


///////////////////////////////////////7
//Estas funciones leen la base de datos de las imágenes de caracteres de los archivo ubyte,
//que tienen un formato concreto


uint32_t EndianSwap (uint32_t a){
    return (a<<24) | ((a<<8) & 0x00ff0000) |
           ((a>>8) & 0x0000ff00) | (a>>24);
}




bool Load(){
    FILE* file = fopen("t10k-labels-idx1-ubyte","rb");  //aqui esta abriendo el archivo de entrenamiento, hay que poner que abra el normal
    if (!file){
        printf("could not open the archive for reading.\n");
        return false;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    //m_labelData = malloc(fileSize*sizeof(uint8_t));
    fseek(file, 0, SEEK_SET);
    fread(m_labelData, fileSize, 1, file);
    fclose(file);
    uint32_t* data = (uint32_t*)m_labelData;
        if (data[0] == 0x01080000){
            data[0] = EndianSwap(data[0]);
            data[1] = EndianSwap(data[1]);
    }


    if (data[0] != 2049 || data[1] != NIMAGES){
        printf("Label data had unexpected header values.n");
        return false;
    }
    m_labels = (uint8_t*)&(data[2]);

    file = fopen("t10k-images-idx3-ubyte","rb");
    if (!file){
        printf("could not open the archive for reading.\n");
        return false;
    }

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    //m_imageData = malloc(fileSize*sizeof(uint8_t));
    fseek(file, 0, SEEK_SET);
    fread(m_imageData, fileSize, 1, file);
    fclose(file);

    data = (uint32_t*)m_imageData;
    if (data[0] == 0x03080000){
        data[0] = EndianSwap(data[0]);
        data[1] = EndianSwap(data[1]);
        data[2] = EndianSwap(data[2]);
        data[3] = EndianSwap(data[3]);
    }

    if (data[0] != 2051 || data[1] != NIMAGES || data[2] != 28 || data[3] != 28){
        printf("Label data had unexpected header values.n");
        return false;
    }
    m_pixels = (uint8_t*)&(data[4]);

    for (size_t i = 0; i < IMGPIXELES * NIMAGES; ++i){
        m_pixelsFloat[i] = (float)m_pixels[i] / 255.0f;
    }

}

uint8_t GetLabel(size_t index){
    return m_labels[index];
}

float* GetImage (size_t index, uint8_t label){
    label = m_labels[index];
    return &m_pixelsFloat[index * 28 * 28];
}

int main_standalone(){
	int aciertos=0;
		int digito = 0;

	    Load();

		for(int ntest=0; ntest<N_PRUEBAS;ntest++){
			const float* pixels = GetImage(ntest,GetLabel(ntest));
			digito = MLP(pixels);

			if(digito==GetLabel(ntest)){
				aciertos++;
			}
		}
		printf("Aciertos %i \n", aciertos);
	    return 0;
}

int main_axi(){
	int aciertos=0;
	int digito = 0;
	AXI_VAL inp_stream[C_INTRO];
    Load();

	for(int ntest=0; ntest<N_PRUEBAS;ntest++){
		const float* pixels = GetImage(ntest,GetLabel(ntest));
		 for(int i=0; i<C_INTRO;i++)
			    		{
			    			inp_stream[i] = push_stream<T,U,TI,TD>(pixels[i],0,0,1,2);
			    		}

		digito = Wrapped_MLP(inp_stream);
		if(digito==GetLabel(ntest)){
			aciertos++;
		}
	}
	printf("Aciertos %i \n", aciertos);


    return 0;
}

int main(){
	return main_axi();
}
